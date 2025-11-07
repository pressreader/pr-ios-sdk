//
//  SelectionView.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 06/11/2025.
//  Copyright © 2025 PressReader. All rights reserved.
//

import SwiftUI
import PRSyntacticSugar

public struct SelectionView: View {

    public let options: [String]
    public let selectedOption: String?
    public let completion: (String) -> Void

    public init(
        options: [String],
        selectedOption: String?,
        completion: @escaping (String) -> ()
    ) {
        self.options = options
        self.selectedOption = selectedOption
        self.completion = completion
    }

    public var body: some View {
        List {
            ForEach(self.options.indices, id: \.self) {
                let title = self.options[$0]

                return RowView(
                    title: title,
                    selected: title == self.selectedOption
                ) {
                    self.completion($0)
                }
            }
            
            Section {
                CustomEntryView(completion: self.completion)
            } header: {
                Text("Custom Service")
            }
        }
    }
}

private struct CustomEntryView: View {
    let completion: (String) -> Void

    @State
    private var text: String = ""

    var body: some View {
        HStack(spacing: 12) {
            TextField("Enter custom option", text: self.$text, onCommit: self.onCompletion)
                .textInputAutocapitalization(.words)
                .disableAutocorrection(true)
            Spacer()
            Button {
                self.onCompletion()
            } label: {
                Text("Apply")
            }
            .disabled(self.text.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty)
        }
    }
    
    private func onCompletion() {
        self.text.nonEmpty.map {
            self.completion($0)
        }
    }
}

private struct RowView: View {
    let title: String
    let selected: Bool
    let onTap: (String) -> ()

    var body: some View {
        Button {
            self.onTap(title)
        } label: {
            HStack(spacing: 12) {
                Text(title)
                    .foregroundColor(.primary)

                Spacer()

                if selected {
                    Image(systemName: "checkmark")
                        .foregroundColor(.accentColor)
                }
            }
            .contentShape(Rectangle())
        }
        .buttonStyle(.plain)
    }
}

// MARK: - Preview

private struct SelectionPreviewContainer: View {
    var options: [String] = ["One", "Two", "Three", "Two"]

    @State
    var selected: String? = "Two"

    var body: some View {
        SelectionView(
            options: self.options,
            selectedOption: self.selected
        ) { value in
            // Update selection interactively inside the preview.
            self.selected = value
        }
        .animation(.default, value: self.selected)
    }
}

struct SelectionView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            SelectionPreviewContainer()
                .previewDisplayName("Interactive - Light")

            SelectionPreviewContainer()
                .environment(\.colorScheme, .dark)
                .previewDisplayName("Interactive - Dark")

            SelectionPreviewContainer()
            .environment(\.dynamicTypeSize, .accessibility3)
            .previewDisplayName("Static - Accessibility3")

            SelectionPreviewContainer(options: [])
                .previewDisplayName("Empty")

        }
    }
}
