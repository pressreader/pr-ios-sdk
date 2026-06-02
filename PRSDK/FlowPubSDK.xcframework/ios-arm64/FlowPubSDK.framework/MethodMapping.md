
# FlowPub iOS SDK

## The SDK exposes below methods to consumers.

# class PublicationFactory

---
## Instance Methods

**makePublication(type\_:with\_:completion\_:)**  [View in Source](x-source-tag://makePublication)  
_Makes a Publication model by parsing an input publication format._

### Declaration  
`func makePublication(type publicationFormat: PublicationFormat, with entryURL: URL, completion: @escaping (Result<Publication, Error>) -> Void)`

### Methods used from Core  
`Publication::async parseFromJSON(string: selfURL?) : Promise(Publication)`



___



# class Navigator

---
## Instance Methods

**addExternalLinkClickHandler(handler\_:)**  [View in Source](x-source-tag://addExternalLinkClickHandler)  
_Subscribes to onExternalLinkClicked events_

### Declaration  
`func addExternalLinkClickHandler(handler: @escaping (String) -> Void)`

### Methods used from Core  
`public onExternalLinkClicked = (_href: string): void => {...}`



___

**addHighlight(id\_:startLoc\_:endLoc\_:color\_:duration\_:)**  [View in Source](x-source-tag://addHighlight)  
_Adds a highlight_

### Declaration  
`func addHighlight(id: String, startLoc: Locator, endLoc: Locator, color: String, duration: Int = 0)`

### Methods used from Core  
`public addHighlight = (id: string, startLocatorJSON: string, endLocatorJSON: string, color: string, duration = 0): void =>`



___

**addHighlightSelectedHandler(handler\_:)**  [View in Source](x-source-tag://addHighlightSelectedHandler)  
_Subscribes to onHighlightedSelected events_

### Declaration  
`func addHighlightSelectedHandler(handler: @escaping (SelectedHighlightInfo) -> Void)`

### Methods used from Core  
`public onHighlightSelected = (_highlightInfo: SelectedHighlightInfo): void => {...}`



___

**addHighlights(highlights\_:)**  [View in Source](x-source-tag://addHighlights)  
_Add a list of highlights_

### Declaration  
`func addHighlights(highlights: [NewHighlightInfo])`

### Methods used from Core  
`public addHighlightList = (highlightList: string): void`



___

**addLocationChangedHandler(handler\_:)**  [View in Source](x-source-tag://addLocationChangedHandler)  
_Subscribe to location change events_

### Declaration  
`func addLocationChangedHandler(handler: @escaping ([Locator]) -> Void)`

### Methods used from Core  
`public onLocationChanged = (): void => {..}`



___

**addOnContentIsLoadingHandler(handler\_:)**  [View in Source](x-source-tag://addOnContentIsLoadingHandler)  
_Subscribe to contentIsLoading events_

### Declaration  
`func addOnContentIsLoadingHandler(handler: @escaping (Bool) -> Void)`

### Methods used from Core  
`public onContentIsLoading = (_isLoading: boolean): void => {...}`



___

**addOnPageLabelInfoChangedHandler(handler\_:)**  [View in Source](x-source-tag://addOnPageLabelInfoChangedHandler)  
_Adds a listener for when  gets updated._

### Declaration  
`func addOnPageLabelInfoChangedHandler(handler: @escaping ([PageLabelInfo]) -> Void)`

### Methods used from Core  
`public onPageLabelInfoChanged: PageLabelsVisibleInfoListener = (_visiblePageLabelsInfo: PageLabelInfo[]): void => {}`



### Warning  
Listener will produce empty array if pageLabelRendering is not enabled.

___

**addOnViewportTappedHandler(zone\_:handler\_:)**  [View in Source](x-source-tag://addOnViewportTappedHandler)  
_Registers handlers to be called when the viewport is tapped._

### Declaration  
`func addOnViewportTappedHandler(zone: HotZone, handler: @escaping (TapInfo) -> Void)`

### Methods used from Core  
`public onViewportTapped = (_clickInfo: ClickInfo): void`



___

**addOnViewportResizeStartImmediateHandler(handler\_:)**  [View in Source](x-source-tag://addOnViewportResizeStartImmediateHandler)  
_Registers handlers to be called immediately when the viewport resize starts._

### Declaration  
`func addOnViewportResizeStartImmediateHandler(handler: @escaping () -> Void)`

### Methods used from Core  
`public onViewportResizeStartImmediate = (): void`



___

**addOnViewportResizeStartHandler(handler\_:)**  [View in Source](x-source-tag://addOnViewportResizeStartHandler)  
_Registers handlers to be called after the viewport resize starts with a slight delay._

### Declaration  
`func addOnViewportResizeStartHandler(handler: @escaping () -> Void)`

### Methods used from Core  
`public onViewportResizeStart = (): void`



___

**addOnViewportResizedHandler(handler\_:)**  [View in Source](x-source-tag://addOnViewportResizedHandler)  
_Registers handlers to be called when the viewport resize completes._

### Declaration  
`func addOnViewportResizedHandler(handler: @escaping () -> Void)`

### Methods used from Core  
`public onViewportResized = (): void`



___

**addPinchGestureHandler(handler\_:)**  [View in Source](x-source-tag://addPinchGestureHandler)  
_Add pinch gesture callback_

### Declaration  
`func addPinchGestureHandler(handler: @escaping (Any, Any) -> Void)`

### Methods used from Core  
`public onPinch = (_scale: 'start' | 'change' | 'end',_pinchDist: number): void => {`



___

**addSelectionChangedHandler(handler\_:)**  [View in Source](x-source-tag://addSelectionChangedHandler)  
_Subscribes to selectionChanged events_

### Declaration  
`func addSelectionChangedHandler(handler: @escaping (SelectionInfo?) -> Void)`

### Methods used from Core  
`public onSelectionChanged = (_data: SelectionInfo | null): void => {...}`



___

**cleanUp(())**  [View in Source](x-source-tag://cleanUp)  
_Perform clean up work required before close_

### Declaration  
`func cleanUp()`

### Methods used from Core  
`public clearSelection(): void`



___

**clearSelection(())**  [View in Source](x-source-tag://clearSelection)  
_Clears selection_

### Declaration  
`func clearSelection()`

### Methods used from Core  
`public clearSelection(): void`



___

**compareCFIs(_\_:_\_:)**  _(Deprecated)_  [View in Source](x-source-tag://compareCFIs)  
_Compares relative location of two partial CFIs_

### Declaration  
`func compareCFIs(_ beginCFI: String, _ endCFI: String) throws -> [Int]`

### Methods used from Core  
`public compareCFIs(cfiA: string, cfiB: string): string`



>**Deprecated** - Please use `compareCFIs(String, String, (Result<Int, String>) -> Void)` instead

___

**compareCFIs(_\_:_\_:_\_:)**  [View in Source](x-source-tag://compareCFIs)  
_Compares relative location of two partial CFIs_

### Declaration  
`func compareCFIs(_ beginCFI: String, _ endCFI: String, _ completion: @escaping (Result<Int, String>) -> Void)`

### Methods used from Core  
`public compareCFIs(cfiA: string, cfiB: string): string`



___

**compareLocators(_\_:_\_:)**  _(Deprecated)_  [View in Source](x-source-tag://compareLocators)  
_Compares relative location of two locator objects_

### Declaration  
`func compareLocators(_ locator1: Locator, _ locator2: Locator) -> Result<Int, String>`

### Methods used from Core  
`public compareCFIs(cfiA: string, cfiB: string): string`



>**Deprecated** - Please use `compareLocators(Locator, Locator, (Result<Int, String>) -> Void)` instead

___

**compareLocators(_\_:_\_:_\_:)**  [View in Source](x-source-tag://compareLocators)  
_Compares relative location of two locator objects_

### Declaration  
`func compareLocators(_ locator1: Locator, _ locator2: Locator, _ completion: @escaping (Result<Int, String>) -> Void)`

### Methods used from Core  
`public compareCFIs(cfiA: string, cfiB: string): string`



___

**doLocationsIntersect(_\_:_\_:)**  [View in Source](x-source-tag://doLocationsIntersect)  
_Checks if two range intersect. Any overlap, including a shared boundary, is considered intersecting. A pair of locators defined the start and end of the range. A single locator will be considered a range with length 0._

### Declaration  
`func doLocationsIntersect(_ array1: [Locator], _ array2: [Locator]) throws -> Bool`

### Methods used from Core  
`public doLocationsIntersect([aStart, aEnd = aStart]: [Locator, Locator?], [bStart, bEnd = bStart]: [Locator, Locator?]): boolean`



___

**enablePageLabelRendering(_\_:)**  [View in Source](x-source-tag://enablePageLabelRendering)  
_Toggles page label rendering_

### Declaration  
`func enablePageLabelRendering(_ enabled: Bool) throws`

### Methods used from Core  
`public enablePageLabelRendering(enabled: boolean): void`



### Warning  
For  to work, pageLabelRendering has to be set to true. Failure to do so will result in PageLabelInfoListener returning an empty array.

___

**enableScreenTransitionAnimation(_\_:completion\_:)**  [View in Source](x-source-tag://enableScreenTransitionAnimation)  
_Enable/disable screen transition animation_

### Declaration  
`func enableScreenTransitionAnimation(_ enabled: Bool, completion: @escaping (Result<Void, Error>) -> Void)`

### Methods used from Core  
`public enableScreenTransitionAnimation(mode: boolean): void`



___

**getCharacterOffsetDistance(_\_:_\_:)**  [View in Source](x-source-tag://getCharacterOffsetDistance)  
_Returns the distance between two ranges. 0 means they are intersecting. Negative means the second range is before the first range._

### Declaration  
`func getCharacterOffsetDistance(_ first: [Locator], _ second: [Locator]) throws -> Int`

### Methods used from Core  
`public getCharacterOffsetDistance([firstStart, firstEnd = firstStart]: [Locator, Locator?], [secondStart, secondEnd = secondStart]: [Locator, Locator?]): number`



___

**getLocation(completion\_:)**  [View in Source](x-source-tag://getLocation)  
_Get the current location representing the visible rendering in the viewport._

### Declaration  
`func getLocation(completion: @escaping (Result<[Locator], Error>) -> Void)`

### Methods used from Core  
`public getCurrentLocation(): Location | undefined | null`



___

**getViewSettings(completion\_:)**  [View in Source](x-source-tag://getViewSettings)  
_Retrieve the current view settings_

### Declaration  
`func getViewSettings(completion: @escaping (Result<ViewSettings, Error>) -> Void)`

### Methods used from Core  
`public getViewSettings(): ViewSettings`



___

**getCurrentBackgroundColor(readingMode:handler:)**  [View in Source](x-source-tag://getCurrentBackgroundColor)  
_Gets the background color for a given reading mode (theme). Current actual background color of the viewport is returned if no reading mode is passed in._

### Declaration  
`func getCurrentBackgroundColor(readingMode: ReadingMode? = nil, handler: @escaping (String) -> Void)`

### Methods used from Core  
`public getCurrentBackgroundColor(mode?: ReadingMode): String`



___

**goBackward(completion\_:)**  [View in Source](x-source-tag://goBackward)  
_Move the progression backward and render the previous page in the viewport._

### Declaration  
`func goBackward(completion: @escaping (Result<Bool, Error>) -> Void)`

### Methods used from Core  
`public async previousScreen(): Promise<boolean>`



___

**goForward(completion\_:)**  [View in Source](x-source-tag://goForward)  
_Move the progression forward and render the next page in the viewport._

### Declaration  
`func goForward(completion: @escaping (Result<Bool, Error>) -> Void)`

### Methods used from Core  
`public async nextScreen(): Promise<boolean>`



___

**goToLocation(with\_:)**  [View in Source](x-source-tag://goToLocation)  
_Changes the progression to the given location and renders it in the viewport._

### Declaration  
`func goToLocation(with location: Locator)`

### Methods used from Core  
`public async goToLocationWithLocatorJSON(loc: string): Promise<void>`



___

**goToLocation(with\_:)**  [View in Source](x-source-tag://goToLocation)  
_Changes the progression to the location of the given link and renders it in the viewport._

### Declaration  
`func goToLocation(with link: Link)`

### Methods used from Core  
`public async goToLocationWithLink(link: string): Promise<void>`



___

**goToLocation(with\_:)**  [View in Source](x-source-tag://goToLocation)  
_Go to location with the given locator represented by the string passed_

### Declaration  
`func goToLocation(with jsonString: String)`

### Methods used from Core  
`public async goToLocationWithLocatorJSON(loc: string): Promise<void>`



___

**goToEdge(\_:)**  [View in Source](x-source-tag://goToEdge)  
_Go to start or end with the given publication edge represented by the string passed_

### Declaration  
`func goToEdge(_ edge: PublicationEdge)`

### Methods used from Core  
`public async goToEdge(edge: PublicationEdge): Promise<void>`



___

**goToLocation(with\_:)**  [View in Source](x-source-tag://goToLocation)  
_Go to location with the given absolute position_

### Declaration  
`func goToLocation(with absolutePosition: Int)`

### Methods used from Core  
`public async goToLocationWithAbsolutePosition(position: number): Promise<void>`



___

**isLocationContained(_\_:_\_:strict\_:)**  [View in Source](x-source-tag://isLocationContained)  
_Checks if range inner is contained within range outer. Range inner is contained within range outer if and only if the entire range inner is between the start and end of the range outer. A pair of locators defines the start and end of the range. A single locator will be considered a range with length 0._

### Declaration  
`func isLocationContained(_ outer: [Locator], _ inner: [Locator], strict: Bool = false) throws -> Bool`

### Methods used from Core  
`public isLocationContained([outerStart, outerEnd = outerStart]: [Locator, Locator?], [innerStart, innerEnd = innerStart]: [Locator, Locator?], strict = false): boolean`



___

**openPublication(publication\_:locator\_:viewSettings\_:completion\_:)**  [View in Source](x-source-tag://openPublication)  
_Open a publication to load and render in the viewport._

### Declaration  
`func openPublication(publication: Publication, locator: Locator? = nil, viewSettings: ViewSettings? = nil, completion: @escaping (Result<Void, Error>) -> Void)`

### Methods used from Core  
`function createNavigator(viewportRootSelector: HTMLElement | string, ): Navigator`

`public setContentModuleBase(moduleBase: string): void`

`public setCssBase(cssBase: string): void`

`public setCustomStyleSheetPaths(styleSheetPaths: string): void`



___

**pageLinkToLocation(_\_:_\_:)**  [View in Source](x-source-tag://pageLinkToLocation)  
_Converts a link object to a locator object with as much information as available_

### Declaration  
`func pageLinkToLocation(_ pageLink: Link, _ completion: @escaping (Result<Locator, Error>) -> Void)`

### Methods used from Core  
`public pageLinkToLocation(pageLink: Link, sizeUpToResource?: number): Locator`



___

**removeHighlight(id\_:)**  [View in Source](x-source-tag://removeHighlight)  
_Removes highlight associated with the given id_

### Declaration  
`func removeHighlight(id: String)`

### Methods used from Core  
`public deleteHighlight(id: string): void`



___

**removeHighlights(ids\_:)**  [View in Source](x-source-tag://removeHighlights)  
_Removes highlights associated with given Ids_

### Declaration  
`func removeHighlights(ids: [String])`

### Methods used from Core  
`public deleteHighlightList = (highlightIdList: string): void => {...}`



___

**removeReflowHighlightAndRefreshID(())**  [View in Source](x-source-tag://removeReflowHighlightAndRefreshID)  
_Removes ephemeral highlight created for reflowed text_

### Declaration  
`func removeReflowHighlightAndRefreshID()`

### Methods used from Core  
`public removeReflowHighlightAndRefreshID(): void`



___

**setGestureParameters(params\_:)**  [View in Source](x-source-tag://setGestureParameters)  
_Set gesture parameters_

### Declaration  
`func setGestureParameters(params: GestureParameters)`

### Methods used from Core  
`public setPanSettings(settings: string): void`



___

**setHighlightingOnReflow(_\_:color\_:duration\_:)**  [View in Source](x-source-tag://setHighlightingOnReflow)  
_Set whether a highlight should be applied to the last navigated location when the test is reflowed (e.g., on viewport resize on text size change)._

### Declaration  
`func setHighlightingOnReflow(_ flag: Bool, color: String = "", duration: Int = 0)`

### Methods used from Core  
`public setHighlightingOnReflow(highlightOnReflow: boolean, lastLocationHighlightColor: string, duration: number): void`



___

**setPageLabelVisibility(to\_:)**  [View in Source](x-source-tag://setPageLabelVisibility)  
_Toggles the visibility of page label_

### Declaration  
`func setPageLabelVisibility(to flag: Bool) throws`

### Methods used from Core  
`public setPageLabelVisibility(visible: boolean): void`



___

**setPrefetchPercent(_\_:)**  [View in Source](x-source-tag://setPrefetchPercent)  
_Update prefetch percent_

### Declaration  
`func setPrefetchPercent(_ percent: Double)`

### Methods used from Core  
`public setPrefetchPercent(percent: number): void`



___

**setViewSettings(_\_:)**  [View in Source](x-source-tag://setViewSettings)  
_Update a view setting to change the view._

### Declaration  
`func setViewSettings(_ viewSettings: ViewSettings)`

### Methods used from Core  
`public setViewSettings(viewSetting: ViewSettings): void`

`public updateInitialSetting(name: SettingName, value: any): void`



___

**updateHighlight(id\_:color\_:)**  [View in Source](x-source-tag://updateHighlight)  
_Applies given color to the highlight associated with the given id_

### Declaration  
`func updateHighlight(id: String, color: String)`

### Methods used from Core  
`public updateHighlight(id: string, color: string): void`



___

**getBlobPathForSpineHref(String:completion:)**  [View in Source](x-source-tag://getBlobPathForSpineHref)  
_Returns blob path from the publication using HREF_

### Declaration  
`public func getBlobPathForSpineHref(_ href: String, completion: @escaping (Result<String?, Error>) -> Void)`

### Methods used from Core  
`public getBlobPathForSpineHref(href: string): string | undefined`



___

**getBlobPathForSpineIndex(Int:completion:)**  [View in Source](x-source-tag://getBlobPathForSpineIndex)  
_Returns blob path from the publication using Spine Index_

### Declaration  
`public func getBlobPathForSpineIndex(_ index: Int, completion: @escaping (Result<String?, Error>) -> Void)`

### Methods used from Core  
`public getBlobPathForSpineIndex(index: string | number): string | undefined`



___

**getBlobsArray(:completion:)**  [View in Source](x-source-tag://getBlobsArray)  
_Returns blob path array_

### Declaration  
`public func getBlobsArray(_ completion: @escaping (Result<[Blob], Error>) -> Void)`

### Methods used from Core  
`public getBlobsArray(): string[] | undefined`



___

**getBlobDataObject(:completion:)**  [View in Source](x-source-tag://getBlobDataObject)  
_Returns blob path array_

### Declaration  
`public func getBlobDataObject(_ completion: @escaping (Result<BlobData, Error>) -> Void)`

### Methods used from Core  
`public getBlobData(): FpBlobData | undefined`



___

**getChapterLocator(at:\_:)**  [View in Source](x-source-tag://getChapterLocatorAtPosition)  
_Returns chapter locator at given position_

### Declaration  
`public func getChapterLocator(at position: Int, _ completion: @escaping (Result<Locator, Error>) -> Void)`

### Methods used from Core  
`public getChapterLocatorAtPosition(position: number): Locator | undefined`



___

**getPageOfTocItem(:\_:)**  [View in Source](x-source-tag://getPageOfTocItem)  
_Returns relative page number to the start of the chapter_

### Declaration  
`public func getPageOfTocItem(at position: Int, _ completion: @escaping (Result<Int, Error>) -> Void)`

### Methods used from Core  
`public getPageOfTocItem(position: number): number | undefined`



___
