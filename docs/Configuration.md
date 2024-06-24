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
* [Appearance](#appearance)
* [Behavioural](#behavioural)
* [Catalog UI](#catalog-ui)
* [Feed](#feed)
* [Local Service](#local-service)
* [Reader](#reader)
* [Support](#support)
* [Tabs](#tabs)
* [Translation](#translation)
* [User Authorization](#user-authorization)

---
### Appearance

| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| `COLOR_BRAND` | Number | 0x15b25 | Tint colour of buttons, highlights, some other action controls. |
| `COLOR_BRAND_DARK` | Number | 0x11a011 | Tint colour of action controls like bar button items. |
| `COLOR_BACKGROUND` | Number | 0xECECEC | |
| `COLOR_BACKGROUND_DARK` | Number | 0x2A2A2A | |
| `BRAND_GRADIENT_START_COLOR` | Number | 0x1F836A | Start gradient colour of brand modal screens (Onboarding, Subscription, Calendar, etc.). |
| `BRAND_GRADIENT_END_COLOR` | Number | 0x043652 | End gradient colour of brand modal screens. |

---
### Behavioural

| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| `SDK.AUTHORIZATION_TYPE` | Number | | <p>There are 2 authorization types in the SDK at the moment:<pre><code class="language-c">typedef NS_ENUM(NSUInteger, PRSDKAuthType) {&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRSDKAuthTypeJWTToken = 0,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRSDKAuthTypeServiceName&#10;};</code></pre><p>If you need authorization with JWT token, the parameter in `PRConfig` can be omitted.<p>Authorization with service name currently works only if `SERVICE_NAME` corresponds to some BE service name. In this case, JWT token is not required. |
| `CONFIG_RUN_TIME_UPDATE_ALLOWED` | Boolean | YES | Set to `YES` to allow PRSDK automatically update its configuration from the Publishing Portal. **Note** that in this case settings described in PRConfig section of the host app’s Info.plist may be implicitly overridden.
| `config_version` | String | | Current version of `PRConfig`. If `CONFIG_RUN_TIME_UPDATE_ALLOWED` is turned on and the back-end has a newer than stated `config_version` of `PRConfig`, then `PRSDK` will be using this newer config from the back-end instead.
|`ONBOARDING_SUPPORTED`|Boolean|NO|Onboarding procedure includes setting up user interests.|
|`CATALOG.MODE`|Number|0|In BRAND_EDITION apps catalog defines the UI. That’s why during the first launch the app waits for a catalog to get loaded before dismissing splash screen. It can be a problem if the catalog is big and requires significant loading time. You can override this behaviour by providing CATALOG.MODE parameter, defining what type of catalog you’re expecting and thus reducing the user’s waiting time.<p><pre><code class="language-c">typedef NS_ENUM(NSInteger, PRCatalogMode) {&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRCatalogModeUnknown = 0,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRCatalogModeRegular,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRCatalogModeSingleTitle,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRCatalogModeSingleTitlePlusSupplements&#10;};</code></pre>|

---
### Catalog UI

| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| `FILTER_PANEL_ENABLED` | Boolean | NO in BRAND_EDITION | Convenient catalog filters (Type, Language, Country). Makes sense for big catalogs. |

### Feed
| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
|`NEWSFEED_API`|Number|0|<p>Home feed provider’s type. Available values are represented by the enum below.<pre><code class="language-c">typedef NS_ENUM(uint8_t, PRNewsFeedAPI) {&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRNewsFeedAPINone = 0,&#10;&nbsp;&nbsp;&nbsp;&nbsp;// Type reserved for PressReader service.&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRNewsFeedAPIHomeFeed,&#10;&nbsp;&nbsp;&nbsp;&nbsp;// Aggregate feed based on the followed by user issues.&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRNewsFeedAPIPublicationsRSSFeed,&#10;&nbsp;&nbsp;&nbsp;&nbsp;// Feed of the specific channel.&#10;&nbsp;&nbsp;&nbsp;&nbsp;// HOME_FEED_CHANNEL parameter must be additionaly set.&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRNewsFeedAPIChannel,&#10;&nbsp;&nbsp;&nbsp;&nbsp;// Feed of the specific bookmark collection.&#10;&nbsp;&nbsp;&nbsp;&nbsp;// Both HOME_FEED_CHANNEL and HOME_FEED_COLLECTION must be set.&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRNewsFeedAPIBookmarks&#10;};</code></pre>|
|`HOME_FEED_CHANNEL`|String||ID of a channel used as a source of Home feed. This parameter is ignored if `NEWSFEED_API` value is other than `PRNewsFeedAPIChannel`.|
|`HOME_FEED_COLLECTION`|String||ID of a collection used as a source of Home feed. This parameter is ignored if `NEWSFEED_API` value is other than `PRNewsFeedAPIBookmarks`.|
|`ARTICLE_AUTORIZATION_REQUIRED_TO_PRINT`|Boolean|YES in BRAND_EDITION  mode||
|`ARTICLE_AUTORIZATION_REQUIRED_TO_LISTEN`|Boolean|YES in BRAND_EDITION  mode||
|`CHANNEL.FEED_ARTICLE_ACCESS_MODE`|Number|0|<pre><code class="language-c">typedef NS_ENUM(uint8_t, PRFeedArticleAccessMode) {&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleAccessModeNone = 0,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleAccessModeRequireSignIn,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleAccessModeRequireSubscription&#10;};|</code></pre>|
|`ARTICLE_COMMENTS_ENABLED`|Boolean|NO|Article comments feature|
|`ARTICLE_VOTES_ENABLED`|Boolean|NO|Article votes feature|
|`FEED.ARTICLE_ACTIONS`|Number|`PRFeedAcrticleActionListen` in BRAND_EDITION|<p>Feed article action button<pre><code>typedef NS_OPTIONS(NSUInteger, PRFeedArticleAction) {&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleActionNone = 0,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleActionPrint = 1 << 0,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleActionShare = 1 << 1,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleActionListen = 1 << 2,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleActionBookmark = 1 << 3,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleActionUnlock = 1 << 4,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRFeedArticleActionMulti = PRFeedArticleActionPrint \| PRFeedArticleActionShare \| PRFeedArticleActionListen&#10;};</code></pre>|
|`ISSUE.FEED.ARTICLE_ACTIONS`|Number|`PRFeedArticleActionMulti`|Issue feed article action button. See option above|
|`ARTICLE.POPUP_VIEW_ALLOWED`|Boolean|YES|Show Article details in popover mode for tablets UI idiom. Include “two level“ navigation stack functionality.|
|`ARTICLE.POPUP_VIEW_ALLOWED`|Boolena|NO|Disable article text hyphenation|

### Local Service
| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| `LOCAL_SERVER_URL` | String | | SDK starts working with the given server instead of default online one. |

### Reader
| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| `READER.EXTERNAL_LINKS.ENABLED` | Boolean | YES | Interactive external links rendering. |

### Support
| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
|`BUNDLE.SHOW_CUSTOMER_SUPPORT`|Boolean|YES|Displayed in `Settings > Subscriptions` section|
|`SUPPORT_EMAIL_ADDRESS`|String|support@pressreader.com|Displayed in `Settings > Subscriptions` section|
|`SUPPORT_PHONE_NUMBER`|String|+1-604-278-4604|Displayed in `Settings > Subscriptions` section|
|`PRIVACY_POLICY_URL`|String||Privacy policy link|
|`LEGAL_URL`|String||Terms or Use|
|`ABOUT_SOCIAL_URLS|Array||<p>List of social media’s links. It’s an array of dictionaries: `[Dictionary<String, String>]`, i.e.<pre><code>[[“Facebook”: “https://facebook.com/mypage“],&#10;[“Twitter”: “https://twitter.com/mypage“],&#10;[“Instagram”: “https://instagram.com/mypage“]]</code><pre>|
|`support_emails`|Array||Feedback eamail(s). Array of String, i.e.`["support@me.com"]`|
|`support_email_subject`|String||Feedback email. You can use `{deviceType}` occurrence symbol which will be replaced with the appropriate device type.|

### Tabs
| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
|`APP_MENU_ITEMS_ABSENCE`|Number|0 (all available items are visible)|<p>Opting-out app menu items (tabs).<pre><code>typedef NS_OPTIONS(NSUInteger, PRAppMenuItemAbsence) {&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceHome = 1 << 0,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceCatalog = 1 << 1,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceDownloaded = 1 << 2,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceBookmarks = 1 << 3,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceSignIn = 1 << 4,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceHotspots = 1 << 5,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceAccount = 1 << 6,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceSettings = 1 << 7,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceSubscriptions = 1 << 8,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceAbout = 1 << 9,&#10;&nbsp;&nbsp;&nbsp;&nbsp;PRAppMenuItemAbsenceMore = 1 << 10,&#10;};</code></pre>|
|`SDK_EXIT_BUTTON_TITLE`|String|Dismiss|Title of the Dismiss PressReader menu item. Providing value is actually a localisable string’s key. A host app is responsible for the localisation.|
|`SDK_EXIT_BUTTON_HIDDEN`|Boolean|NO|Set `YES` to hide exit button. |

### Translation
| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
| `TRANSLATE` | Boolean | YES | Enables Article translation feature |
|`AUTOTRANSLATE_AVAILABILITY` | Number | 0 | <p>Zones where auto translation is available<p>Use 0 value to trun auto translate feature off<p>Auto translation depends on `TRANSLATE` parameter and available only in case regular translation is ON<pre><code class="language-swift">struct AutoTranslationZone: OptionSet {&#10;&nbsp;&nbsp;&nbsp;&nbsp;let rawValue: Int&#10;&#10;&nbsp;&nbsp;&nbsp;&nbsp;public static let downloadedFeed = AutoTranslationZone(rawValue: 1 << 0)&#10;&nbsp;&nbsp;&nbsp;&nbsp;public static let downloadedArticleDetails = AutoTranslationZone(rawValue: 1 << 1)&#10;&nbsp;&nbsp;&nbsp;&nbsp;public static let feed = AutoTranslationZone(rawValue: 1 << 2)&#10;&nbsp;&nbsp;&nbsp;&nbsp;public static let articleDetails = AutoTranslationZone(rawValue: 1 << 3)&#10;}</code></pre>
| `AUTOTRANSLATE.PAIRS_LIMIT` | Number | 3 | Maximum amount of language pairs which could be saved for auto translation |

### User Authorization
| Parameter | Type | Default value | Description |
| --- | --- | --- | --- |
|`DEVICE_ACCOUNT_ONLY`|Boolean|NO|Set `YES` to disable sign-in|
|`SHOW_SIGNUP`|Boolean|YES|Set `NO`to disable in-app account registration|
|`EXTERNAL_AUTH_ENABLED`*|Boolean|NO|Set `YES` to enable social sign-in|

*To activate external (social) auth the following url schemes must be included into the root of the host app’s Info.plist.
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
Additionally for the users' convenience you may want to include the following schemes into the root of the host app’s Info.plist to be able to open installed social apps to request a quick login (instead of opening the browser).
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

# Splash Screen
To customise splash (loading) screen background add `PRSplashBackground` (or `SplashBackground`) image set into assets catalog of your host app.

# Catalog View
To customise splash (loading) screen background add PRSplashBackground (or SplashBackground) image set into assets catalog of your host app.

[BE2.0: Page Sections json configuration](https://pressreader.atlassian.net/l/cp/MCNEC5yE)

