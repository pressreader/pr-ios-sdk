# Authorization

Auth API is available via `account` property of `PressReader`. Normally Host app performs PressReader authorization on start or before access to `PressReader` features is required.
```swift
let account = PressReader.instance().account
```

## Authorization by  token

```
account.authorize(token: String, completion: Callback)
```

## Authorization by  service name
Authorization by service name allows working with SDK based on service name only, without token. In order to achieve this behavior the next configuration has to be done:

In `Info.plist` of your app add [`PRConfig`](Configuration.md) dictionary with `SERVICE_NAME` string type entry with your service name value.
<br><br>

# Observing SDK state

To observer SDK's current state utilize the `state` property:
```swift
PressReader.instance().state
```
SDK `state` is described by the following options:
```c
typedef NS_OPTIONS(NSUInteger, PRState) {
    PRStateRunning = 1 << PRStateTypeRunning,
    PRStateActivated = 1 << PRStateTypeActivated,
    PRStateCatalogLoaded = 1 << PRStateTypeCatalogLoaded
};
```
Each change in the state triggers the `PressReaderStateDidChange` notification. Alternatively, employ the `PressReaderState` class to manage state using the Combine API.

SDK `state` has to turn `.activated` to execute any operations and `.catalogLoaded` to be able to download issues.
<br><br>

# Download

After the instance of PressReader SDK is authorized, issues downloading becomes possible. The downloading process is manageable via catalog item's download property that conforms to Download interface described below.

```swift
Download {
  var state: DownloadState
  var progress: Int
  var error: Error?

  func start()
  func pause()
  func cancel()
}
```
where `DownloadState` is
```swift
enum DownloadState {
    stop,     // the downloading wasn’t started or was stopped due to error
    progress, //  the downloading is in progress
    pause,    // the downloading is paused
    ready     // downloading was successfully completed
}
```

## Access download property

You access specific download for a `cid` / `date` pair via corresponding item in catalog:
```swift
guard let download = PressReader.instance().catalog.item(cid, date)?.download else {
    print("Item with given cid / date isn't found")
    return
}
```

## Start download
```swift
download.start()
```

## Pause download
```swift
download.pause()
```
To resume download call `download.start()` method again.

## Cancel download
```swift
download.cancel()
```

## Download state and progress observation
Downloading state and progress can be accessed via `state`, `progress` and `error` properties. 
Additionally `download` object conforms to observation interface that allows to attach handlers to follow download progress in real time.
```swift
Download {
    /// when the returned DownloadObserver is deinited it will stop observing
    func observe(_ callback: @escaping Callback) -> DownloadObserver?
}
```
where `Callback` is
```swift
typealias Callback = (DownloadState, Progress, Error?) -> Void
```

## Download error processing
`AuthorizationError` is returned when there’s a problem with authorization and re-authorization is required.
<br><br>

# Downloaded
The management of downloaded catalog items can be done via `downloaded` property of `catalog`
```swift
let downloaded = PressReader.instance.catalog.downloaded
```
where `downloaded` is
```swift
Downloaded {
  // returns the list of downloaded items 
  var items: [Item]
  // deletes downloaded item
  func delete(_ item: Item)
  func deleteAll()
}
```
where `Item` is
```swift
Item {
  var cid: String
  var date: Date
  var title: String
  var size: Long?
  var download: Download
}
```
Please check [Download](#download) section for the information how to access the item's download state and open it.

## State observation
`Downloaded` object conforms to the observation interface and “calls back” on items deletion or insertion.
```swift
Downloaded {
  /// when the returned Observer is deinited it will stop observing
  func observe(_ callback: @escaping ()->()) -> Observer
}
```

# Open the downloaded issue (Reader API)

```swift
if let reader = ReadingVC(issue: issue) {
    yourViewController.present(reader. animated: true, completion: nil)
}
```
`reader` can be nil in case issue hasn't been previously ordered (dowload process not started)
<br><br>

# Open an article by id (Article API)

```swift
let articleId = "281651080992599"
await PressReader.instance().openArticle(id: articleId)
```

# Logs

The `getLogs` asyncronous method is available to collect device logs and upload to server
```swift
func getLogs(completion: (Result<(linkToUploadedLogs: URL, additionalInfo: String), Error>) -> Void)
```
`completion` is a callback executed after obtaining all required information including linkToUploadedLogs, additionalInfo - some textual information we usually provide along with logs inside feedback email, like OS version, device model, device id, some internal component versions (SDK version) and crash stack if available.
<br>

# Analytics

A list of tracker classes can be passed to PressReader SDK init method to track events happening when publication is viewed:
```swift
var trackerList: MutableList<AnalyticsTracker> = ArrayList()
trackerList.add(CustomTracker())
PressReader.init(Application.this, PressReader.Params(trackerList))
```
where `CustomTracker` inherits from `ReadingViewAnalyticsTracker` and overrides the methods corresponding to the events to be logged.

## Event list

|Event name|Event parameters|Description|
|---|---|---|
|`OpenIssueForReading`|`issue`| Publication issue opened for reading |
|`IssuePage`|`issue`,`pageNumber`|Issue page is changed (reading view)|
|`IssueTextFlow`|`issue`|Issue article feed is presented (text view)|
|`ArticleView`|`article`|Full Article Text view presented|
|`Translated`|`fromLanguage`,`toLanguage`|Translated article presented|
|`ListenView`|`issue`|text-to-speach view presented|

where `fromLanguage`, `toLanguage` are ISO language codes,

Any host app’s provided tracker should conform to abstract `AnalyticsTracker` protocol with no methods defined, but all protocol for different part of tracking functionality would include this protocol, for example the only currently defined `RreadingViewAnalyticsTracker` protocol:
```swift
public protocol ReadingViewAnalyticsTracker: AnalyticsTrackerProtocol {
    /// publication opened for reading
    func trackOpenIssueForReading(issue: TrackingIssue)
    /// reading(replica) view switched to pageNumber [1...N]
    func trackIssuePage(issue: TrackingIssue, pageNumber: Int)
    /// reading view switched to text flow of article snippets (phone only)
    func trackIssueTextFlow(issue: TrackingIssue)
    /// reading view switched to detail article view
    func trackArticleView(issue: TrackingIssue, article: TrackingArticle)
    /// presenting "newspaper radio view" initiated from replica or article view
    func trackListenView(issue: TrackingIssue)
    /// presenting translated version of article, languages parameter are alpha-2 ISO codes
    func trackTranlated(article: TrackingArticle, languageFrom: String, laguageTo: String)
    /// specific page printed from replica view (full page or cropped to visible part)
    func trackPrintedPages(issue: TrackingIssue, isFullPage: Bool, pageNumbers: [Int])
    /// article printed as a formatted text or as it presented in replica view
    func trackPrintedArticle(issue: TrackingIssue, article: TrackingArticle, inReplicaPresentation: Bool)
}
```
Protocol methods are all have default implementation doing nothing, so host app implementation should only defined those methods in their classes which they want to track for example:
```swift
extension SomeTracker: ReadingViewAnalyticsTracker {
    func trackOpenIssueForReading(issue: TrackingIssue) {
        print ("Openin publication \(issue.slug) of \(issue.date) opened for reading")
    }
}
```
The following public API structures defined for host developer to be used inside ReadingViewAnalytics protocol methods as parameters:
```swift
public struct TrackingIssue {
    public let cid: String
    public let date: Date
    public let isLatest: Bool
    public let version: Int?
    public let smartLayoutVersion: Int?
    public let title: String
    public let slug: String?
    public let sourceType: String // currently "newspaper" or "magazine"
}

public struct TrackingArticle {
    public let id: String
    public let headline: String
    public let language: String
}
```
providing most of possibly used for analytics information from both replica and article view. In the future we’ll define more protocols for analytics in other parts of the tracked functionality.

Because `PressReader` class is a singleton, the host app should setup the list of analytics trackers via launchOptions class property before first use of `PressReader`:
```swift
private lazy var pressreader: PressReader = {
    PressReader.launchOptions = [.prAnalyticsTrackers: [self]]
    return PressReader.instance()
} ()
```





