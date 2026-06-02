# FlowPub SDK

🍎🛠 Reading System Development Kit for iOS

[![GitHub Actions: CI status](https://github.com/flowpub/ios-sdk/workflows/ci/badge.svg)](https://github.com/flowpub/ios-sdk/actions?query=workflow%3Aci) [![GitHub Actions: CD status](https://github.com/flowpub/ios-sdk/workflows/cd/badge.svg)](https://github.com/flowpub/ios-sdk/actions?query=workflow%3Acd) [![Jazzy Docs](https://docs.flowpub.io/ios-sdk/badge.svg)](https://docs.flowpub.io/ios-sdk/)

## Using

FlowPub SDK has two major modules:

- A _Publication_ module that provides publication information as a model.
- A _Navigator_ module, that loads publication models, and renders in a WebView.
- Additional modules for convenience, such as a _WebServer_.

Modules can be instantiated by using the associated factory classes through a shared singleton instance.

### Getting Started

To open a publication, we need to start a webserver, parse the publication,
then finally create a Navigator

```swift
import FlowPubSDK
import FlowPubWebServer

let server = WebServer()
server.start(bundle: SomeBundle, path: "/Path/To/EPUB/Resources")

let navigator = NavigatorFactory.sharedInstance.makeNavigator()
let url = server.url.appendingPathComponent("/epub-directory/manifest.json")

PublicationFactory.sharedInstance.makePublication(
    type: .readium, with: url,
) { result in
    let publication = try! result.get()

    navigator.openPublication(publication: publication) { result in
        try! result.get()
        // Successfully opened an EPUB
    }
}
```

Then simply add the value of this property to your UI view:

```swift
navigator.webView
```

#### 📖 Publication

To parse a publication, you can call:

```swift
PublicationFactory.sharedInstance.makePublication(type:with:completion:)
```

The only type supported at the moment is: `.readium`

This is the type for a [Readium Web Publication](https://readium.org/webpub-manifest/).

#### 🧭 Navigator

The Navigator simply takes a Publication model and sets up a WebView to display it.

```swift
let navigator = NavigatorFactory.sharedInstance.makeNavigator()
navigator.openPublication(publication:completion:)
```

The navigator hosts the `navigator.webView` field, which is integrated into the app view hierarchy.

The navigator is also responsible for progressing the reading display.

For example to flip pages:

```swift
navigator.goForward()
navigator.goBackward()
```

#### 🕸 WebServer

A reference implementation using GCDWebServer is provided.

To start a web server you can call:

```swift
let server = WebServer()

server.start(bundle: Bundle, path: "Path/To/Resources")
```

This will start a server with a randomized\* port, and will serve files in the specified path under the specified bundle.

It will also add a UUID to obfuscate resource paths, such that the resulting URL follows this format:

```
http://localhost:<port>/<uuid>
```

For example:

```
http://localhost:58271/56199698-8F9D-4C03-B2EB-909EAEBAE557
```

The property `server.url` can be used to read this value.

To set the URL to an EPUB asset folder you can use:

```swift
server.url.appendingPathComponent("path/to/an/expanded/epub")
```

### Documentation

#### 📚 [API Reference](https://docs.flowpub.io/ios-sdk/)

## Building

> **ℹ For now a more detailed guide can be found in the project wiki [here](https://github.com/flowpub/ios-sdk/wiki/Getting-Started).**

### Prerequisites

#### 🌱 [Mint](https://github.com/yonaskolb/Mint)

A package manager that installs and runs Swift CLI packages.

Needed to run tools such as SwiftLint during buildtime.

```sh
brew install mint
```

#### 🛠 Xcode 11.3+

macOS Catalina 10.15 or higher is recommended.

### Open in Xcode

#### 📂 FlowPub.xcworkspace

Open the FlowPub workspace in Xcode.

### Targets

#### 🧰 FlowPubSDK

Use to build the framework, or run unit tests.

#### 🧪 FlowPubTestApp

Use to build and run the testing app, or run UI tests.

## License

FlowPub is developed and maintained by [Evident Point Software](https://www.evidentpoint.com/), under the [3-Clause BSD license](./LICENSE).

See [LICENSE-3RD-PARTY.md](./LICENSE-3RD-PARTY.md) for the licenses of included third-party libraries.


## Building the framework via Github Actions

Framework generation has been automated via Github Actions using [buildGeneration.yml](https://github.com/flowpub/ios-sdk/blob/master/.github/workflows/buildGeneration.yml).

In order to trigger automatic build generation, follow these steps

1. Checkout the branch you want to create a build from.  
  `git checkout some_branch`
2. Update the SDK version. Commit & push changes.
3. Create a tag using `v` prefix e.g. `v1.2.3`  
  `git tag 'v1.2.3'`
4. Push the tag to origin.  
  `git push origin 'v1.2.3'`

Once the automation is finished, the framework will be attached as a zip file in the [release](https://github.com/flowpub/ios-sdk/releases) associated with given tag.

## Building the framework manually


If you want to create a manual release, there are some extra steps you'll need to follow.

1. Checkout the branch you want to create a build from.  
  `git checkout some_branch`
2. Update the SDK version. Commit & push changes so that we have a record of what changes were pushed in the specific version of the framework.  

Here you have two options. You can either go to terminal, navigate to root directory of the project and type `./manual_framework_generation.sh` and hit enter, or you can do everything yourself by following steps 3 through 8. In any case, you should have the framework ziped up at root/Build/FlowPubSDK.xcframework.zip.

3. In terminal, type `make build_xcframework` and hit enter.
4. Once framework generation finishes, type `cd Build && open .` and hit enter. This should open the directory containing the framework in Finder.
5. In this directory, you should find a directory named FlowPubSDK.xcframework. Inside this directory, you'll see 2 directories, named _ios-arm64_ and _ios-arm64_x86_64-simulator_.
6. Inside _ios-arm64_ directory, go to FlowPubSDK.framework/Runtime/WebView/. You should see a _.gitignore_ file. Open the _.gitignore_ file and remove `node_modules/`.
7. Repeat step 6 for _ios-arm64_x86_64-simulator_ directory.
8. Go back to root/Build. Right click on `FlowPubSDK.xcframework` and select **compress "FlowPubSDK.xcframework"**. The compressed zip will be available at root/Build/FlowPubSDK.xcframework.zip
