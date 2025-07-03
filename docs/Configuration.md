# Configuration

- [PRConfig](#prconfig)
- [Splash Screen](#splash-screen)
- [Catalog View](#catalog-view)

# PRConfig

The configuration of `PRSDK` primarily occurs through the `Info.plist` file of the host application.
To initiate configuration of PRSDK, add `PRConfig` dictionary into your application's `Info.plist`.

`SERVICE_NAME` is the only `PRConfig`'s required entry. The rest of configuration parameters (see [PRConfig subsections](#configuration-types)) are optional and their presence depends on your needs.

There’re two types of services supported by PRSDK: 
* __Brand Edition__ - a service tailored to a specific range of catalog items associated with a particular host application;

* __Baseline__ - a general service that operates with the same catalog as the PressReader application.

For __Brand Edition__ service, ensure to include your assigned `SERVICE_NAME` within `PRConfig`, as illustrated below. Failure to provide a `SERVICE_NAME` entry will result in PRSDK defaulting to the __Baseline__ service.

![PRConfig_image](assets/PRConfig.png)

## Configuration types
- [Configuration](#configuration)
- [PRConfig](#prconfig)
	- [Configuration types](#configuration-types)
		- [Appearance](#appearance)
		- [Behavioural](#behavioural)
		- [Catalog UI](#catalog-ui)
		- [Feed](#feed)
		- [Local Service](#local-service)
		- [Reader](#reader)
		- [Support](#support)
		- [Tabs](#tabs)
		- [Translation](#translation)
		- [User Authorization](#user-authorization)
- [Splash Screen](#splash-screen)
- [Catalog View](#catalog-view)

---
### Appearance

| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| COLOR_BRAND | Number | 0x15b25 | Tint colour of buttons, highlights, some other action controls. |
| COLOR_BRAND_DARK | Number | 0x11a011 | Tint colour of action controls like bar button items. |
| COLOR_BACKGROUND | Number | 0xECECEC | |
| COLOR_BACKGROUND_DARK | Number | 0x2A2A2A | |
| BRAND_GRADIENT_START_COLOR | Number | 0x1F836A | Start gradient colour of brand modal screens (Onboarding, Subscription, Calendar, etc.). |
| BRAND_GRADIENT_END_COLOR | Number | 0x043652 | End gradient colour of brand modal screens. |

---
### Behavioural

<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>

`SDK.AUTHORIZATION_TYPE`

</td><td>Number</td><td/><td>

```swift
enum PRSDKAuthType: Int {
	case jwtToken = 0
	case serviceName = 1
}
```
If you need authorization with a JWT token, the parameter in PRConfig can be omitted.

Authorization with service name currently works only if SERVICE_NAME corresponds to some BE service name. In this case, JWT token is not required.

</td></tr>
<tr><td>

`CONFIG_RUN_TIME_UPDATE_ALLOWED`

</td><td>Boolean</td><td>YES</td><td>

Set to `YES` to allow PRSDK automatically update its configuration from the Publishing Portal. Note that in this case settings described in PRConfig section of the host app’s Info.plist may be implicitly overridden.

</td></tr>
<tr><td>

`config_version`

</td><td>String</td><td/><td>

Current version of `PRConfig`. If `CONFIG_RUN_TIME_UPDATE_ALLOWED` is turned on and the back-end has a newer than stated `config_version` of `PRConfig`, then `PRSDK` will be using this newer config from the back-end instead.

</td></tr>
<tr><td>

`ONBOARDING_SUPPORTED`

</td><td>Boolean</td><td>NO</td><td>Onboarding procedure includes setting up user interests.</td></tr>
<tr><td>

`CATALOG.MODE`

</td><td>Number</td><td>0</td><td>
<p>In BRAND_EDITION apps catalog defines the UI. That’s why during the first launch the app waits for a catalog to get loaded before dismissing splash screen. It can be a problem if the catalog is big and requires significant loading time. You can override this behaviour by providing CATALOG.MODE parameter, defining what type of catalog you’re expecting and thus reducing the user’s waiting time.</p>

```swift
enum PRCatalogMode: Int {
	case unknown = 0
	case regular = 1
	case singleTitle = 2
	case singleTitlePlusSupplements = 3
}
```
</td></tr>
</table>

---
### Catalog UI

| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| FILTER_PANEL_ENABLED | Boolean | NO in BRAND_EDITION | Convenient catalog filters (Type, Language, Country). Makes sense for big catalogs. |

### Feed
<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>NEWSFEED_API</td><td>Number</td><td>0</td><td>

```swift
enum PRNewsFeedAPI: UInt8 {
    case none = 0 // Type reserved for PressReader service.
    case homeFeed // Aggregate feed based on the followed by user issues.
    case publicationsRSSFeed // Feed of the specific channel. HOME_FEED_CHANNEL parameter must be additionally set.
    case channel // Feed of the specific bookmark collection. Both HOME_FEED_CHANNEL and HOME_FEED_COLLECTION must be set.
    case bookmarks
}
```

</td></tr>
<tr><td>HOME_FEED_CHANNEL</td><td>String</td><td></td><td>ID of a channel used as a source of Home feed. This parameter is ignored if `NEWSFEED_API` value is other than `PRNewsFeedAPIChannel`.</td></tr>
<tr><td>HOME_FEED_COLLECTION</td><td>String</td><td></td><td>ID of a collection used as a source of Home feed. This parameter is ignored if `NEWSFEED_API` value is other than `PRNewsFeedAPIBookmarks`.</td></tr>
<tr><td>ARTICLE_AUTORIZATION_REQUIRED_TO_PRINT</td><td>Boolean</td><td>YES in BRAND_EDITION  mode</td><td></td></tr>
<tr><td>ARTICLE_AUTORIZATION_REQUIRED_TO_LISTEN</td><td>Boolean</td><td>YES in BRAND_EDITION  mode</td><td></td></tr>
<tr><td>CHANNEL.FEED_ARTICLE_ACCESS_MODE</td><td>Number</td><td>0</td><td>

```swift
enum PRFeedArticleAccessMode: Integer {
    case none = 0
    case requireSignIn
    case requireSubscription
}
```

</td></tr>
<tr><td>ARTICLE_COMMENTS_ENABLED</td><td>Boolean</td><td>NO</td><td>Article comments feature</td></tr>
<tr><td>ARTICLE_VOTES_ENABLED</td><td>Boolean</td><td>NO</td><td>Article votes feature</td></tr>
<tr><td>FEED.ARTICLE_ACTIONS</td><td>Number</td><td>PRFeedAcrticleActionListen in BRAND_EDITION</td><td>

```swift
struct PRFeedArticleAction: OptionSet {
    let rawValue: UInt
    static let none = PRFeedArticleAction(rawValue: 0)
    static let print = PRFeedArticleAction(rawValue: 1 << 0)
    static let share = PRFeedArticleAction(rawValue: 1 << 1)
    static let listen = PRFeedArticleAction(rawValue: 1 << 2)
    static let bookmark = PRFeedArticleAction(rawValue: 1 << 3)
    static let unlock = PRFeedArticleAction(rawValue: 1 << 4)
    static let multi: PRFeedArticleAction = [.print, .share, .listen]
}
```

</td></tr>
<tr><td>ISSUE.FEED.ARTICLE_ACTIONS</td><td>Number</td><td>PRFeedArticleActionMulti</td><td>Issue feed article action button. See option above</td></tr>
<tr><td>ARTICLE.POPUP_VIEW_ALLOWED</td><td>Boolean</td><td>YES</td><td>Show Article details in popover mode for tablets UI idiom. Include “two level“ navigation stack functionality.</td></tr>
<tr><td>ARTICLE.POPUP_VIEW_ALLOWED</td><td>Boolena</td><td>NO</td><td>Disable article text hyphenation</td></tr>
</table>

### Local Service
<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>LOCAL_SERVER_URL</td><td>String</td><td></td><td>SDK starts working with the given server instead of default online one.</td></tr>
</table>

### Reader
<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>READER.EXTERNAL_LINKS.ENABLED</td><td>Boolean</td><td>YES</td><td>Interactive external links rendering.</td></tr>
</table>

### Support
<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>BUNDLE.SHOW_CUSTOMER_SUPPORT</td><td>Boolean</td><td>YES</td><td>Displayed in `Settings > Subscriptions` section</td></tr>
<tr><td>SUPPORT_EMAIL_ADDRESS</td><td>String</td><td>support@pressreader.com</td><td>Displayed in `Settings > Subscriptions` section</td></tr>
<tr><td>SUPPORT_PHONE_NUMBER</td><td>String</td><td>+1-604-278-4604</td><td>Displayed in `Settings > Subscriptions` section</td></tr>
<tr><td>PRIVACY_POLICY_URL</td><td>String</td><td></td><td>Privacy policy link</td></tr>
<tr><td>LEGAL_URL</td><td>String</td><td></td><td>Terms or Use</td></tr>
<tr><td>ABOUT_SOCIAL_URLS</td><td>Array</td><td></td><td>
<p>List of social media’s links. It’s an array of dictionaries:</p>

```swift
[["Facebook": "https://facebook.com/mypage"],
["Twitter": "https://twitter.com/mypage"],
["Instagram": "https://instagram.com/mypage"]]
```

</td></tr>
<tr><td>support_emails</td><td>Array</td><td></td><td>Feedback eamail(s). Array of String, i.e.`["support@me.com"]`</td></tr>
<tr><td>support_email_subject</td><td>String</td><td></td><td>Feedback email. You can use `{deviceType}` occurrence symbol which will be replaced with the appropriate device type.</td></tr>
</table>

### Tabs
<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>APP_MENU_ITEMS_ABSENCE</td><td>Number</td><td>0 (all available items are visible)</td><td>
<p>Opting-out app menu items (tabs).</p>

```swift
struct PRAppMenuItemAbsence: OptionSet {
    let rawValue: UInt
    static let home = PRAppMenuItemAbsence(rawValue: 1 << 0)
    static let catalog = PRAppMenuItemAbsence(rawValue: 1 << 1)
    static let downloaded = PRAppMenuItemAbsence(rawValue: 1 << 2)
    static let bookmarks = PRAppMenuItemAbsence(rawValue: 1 << 3)
    static let signIn = PRAppMenuItemAbsence(rawValue: 1 << 4)
    static let hotspots = PRAppMenuItemAbsence(rawValue: 1 << 5)
    static let account = PRAppMenuItemAbsence(rawValue: 1 << 6)
    static let settings = PRAppMenuItemAbsence(rawValue: 1 << 7)
    static let subscriptions = PRAppMenuItemAbsence(rawValue: 1 << 8)
    static let about = PRAppMenuItemAbsence(rawValue: 1 << 9)
    static let more = PRAppMenuItemAbsence(rawValue: 1 << 10)
}
```

</td></tr>
<tr><td>SDK_EXIT_BUTTON_TITLE</td><td>String</td><td>Dismiss</td><td>Title of the Dismiss PressReader menu item. Providing value is actually a localisable string’s key. A host app is responsible for the localisation.</td></tr>
<tr><td>SDK_EXIT_BUTTON_HIDDEN</td><td>Boolean</td><td>NO</td><td>Set `YES` to hide exit button. </td></tr>
</table>

### Translation
<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>TRANSLATE</td><td>Boolean</td><td>YES</td><td>Enables Article translation feature</td></tr>
<tr><td>AUTOTRANSLATE_AVAILABILITY</td><td>Number</td><td>0</td><td>
<p>Zones where auto translation is available</p>
<p>Use 0 value to trun auto translate feature off</p>
<p>Auto translation depends on `TRANSLATE` parameter and available only in case regular translation is ON</p>

```swift
struct AutoTranslationZone: OptionSet {
    let rawValue: Int

    public static let downloadedFeed = AutoTranslationZone(rawValue: 1 << 0)
    public static let downloadedArticleDetails = AutoTranslationZone(rawValue: 1 << 1)
    public static let feed = AutoTranslationZone(rawValue: 1 << 2)
    public static let articleDetails = AutoTranslationZone(rawValue: 1 << 3)
}
```

</td></tr>
<tr><td>AUTOTRANSLATE.PAIRS_LIMIT</td><td>Number</td><td>3</td><td>Maximum amount of language pairs which could be saved for auto translation</td></tr>
</table>

### User Authorization
<table>
<tr align='center'><th>Parameter</th><th>Type</th><th>Default value</th><th>Description</th></tr>
<tr><td>DEVICE_ACCOUNT_ONLY</td><td>Boolean</td><td>NO</td><td>Set `YES` to disable sign-in</td></tr>
<tr><td>SHOW_SIGNUP</td><td>Boolean</td><td>YES</td><td>Set `NO`to disable in-app account registration</td></tr>
<tr><td>EXTERNAL_AUTH_ENABLED*</td><td>Boolean</td><td>NO</td><td>
<p>Set `YES` to enable social sign-in</p>
<p><em>To activate external (social) auth the following url schemes must be included into the root of the host app’s Info.plist.</em></p>

```xml
    <key>CFBundleURLTypes</key>
    <array>
        <dict>
            <key>CFBundleTypeRole</key>
            <string>Viewer</string>
            <key>CFBundleURLSchemes</key>
            <array>
                <string>com.googleusercontent.apps.614161124286-9krroucmnbmfecvhpup0usbfibort4nf</string>
                <string>fb110297589138469</string>
                <string>twitterkit-MiQSaDwkC0Ykr56GQ4el4w</string>
            </array>
        </dict>
    </array>
```

<p>Additionally for the users' convenience you may want to include the following schemes into the root of the host app’s Info.plist to be able to open installed social apps to request a quick login (instead of opening the browser).</p>

```xml
    <key>LSApplicationQueriesSchemes</key>
    <array>
        <string>fbapi</string>
        <string>fb-messenger-api</string>
        <string>fbauth2</string>
        <string>fbshareextension</string>
        <string>youtube</string>
        <string>fb</string>
        <string>twitter</string>
        <string>twitterauth</string>
    </array>
```

</td></tr>
</table>

# Splash Screen
To customise splash (loading) screen background add `PRSplashBackground` (or `SplashBackground`) image set into assets catalog of your host app.

# Catalog View
To customise splash (loading) screen background add PRSplashBackground (or SplashBackground) image set into assets catalog of your host app.

[BE2.0: Page Sections json configuration](https://pressreader.atlassian.net/wiki/x/AYAH1g)

