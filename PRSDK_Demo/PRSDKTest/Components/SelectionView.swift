//
//  SelectionView.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 06/11/2025.
//  Copyright © 2025 PressReader. All rights reserved.
//

import SwiftUI

public struct SelectionView: View {

    // MARK: - Public Properties

    public let options: [String]
    public let selectedOption: String?
    public let completion: (String) -> Void

    // MARK: - Init

    public init(
        options: [String],
        selectedOption: String?,
        completion: @escaping (String) -> ()
    ) {
        self.options = options
        self.selectedOption = selectedOption
        self.completion = completion
    }

    // MARK: - Public Methods

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
        }
        .accessibilityIdentifier("selection_list")
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
                        .accessibilityIdentifier("selection_checkmark_\(title)")
                }
            }
            .contentShape(Rectangle())
        }
        .buttonStyle(.plain)
        .accessibilityIdentifier("selection_row_\(title)")
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
