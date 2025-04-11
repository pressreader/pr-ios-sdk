//
//  IssueCell.swift
//  PRSDKTest
//
//  Created by berec on 20/11/2020.
//  Copyright © 2020 PressReader. All rights reserved.
//

import UIKit
import PRAPI
import PRUI

protocol IssueHandler: AnyObject {
    func openIssue(_ issue: PRCatalogItem)
}

final class IssueCell: UITableViewCell {

    // MARK: - Public Properties

    weak var delegate: IssueHandler?

    var issue: PRCatalogItem? {
        didSet {
            self.update()

            let newValue = self.issue
            
            let skip = newValue?.isEqual(oldValue) == true
            guard !skip else { return }
            
            self.observer = newValue?.download?.observe {[weak self] (state, progress, error) in
                self?.update()
                
                if let error = error {
                    UIAlertController
                        .presentDismissableAlert(withTitle: "Download error",
                                                 message: error.localizedDescription)
                }
            }
        }
    }

    // MARK: - Private Properties
    
    private var observer: Download.Observer?

    private lazy var button: UIButton = {
        let button = UIButton(type: .system)
        
        button.addHandler(forEvent: .touchUpInside) { [weak self] in
            guard let self = self,
                  let issue = self.issue
            else { return }
            
            let download = issue.download
            
            switch download?.state {
            case .ready:
                self.delegate?.openIssue(issue)
                
            case .stop, .pause:
                self.button.isEnabled = false
                download?.start()
                
            case .progress:
                download?.pause()
                
            default :
                print("download.state is unknown")
            }
        }
        
        self.accessoryView = button
        
        return button
    }()
    
    private lazy var progressView: UIProgressView = {
        let progressView = UIProgressView(progressViewStyle: .default)
        let superview = self.contentView
        superview.addSubview(progressView)
        
        progressView.translatesAutoresizingMaskIntoConstraints = false
        
        NSLayoutConstraint.activate([
            progressView.leadingAnchor.constraint(equalTo: superview.leadingAnchor, constant: 15),
            progressView.bottomAnchor.constraint(equalTo: superview.bottomAnchor, constant: -12),
            progressView.widthAnchor.constraint(equalToConstant: 200)
        ])

        return progressView
    }()

    private lazy var dateFormatter: DateFormatter = {
        let dateFormatter = DateFormatter()
        dateFormatter.dateStyle = .full
        dateFormatter.timeStyle = .none
        
        return dateFormatter
    }()
    
    // MARK: - Init
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: .subtitle, reuseIdentifier: reuseIdentifier)
        
        self.accessoryView = self.button
    }
    
    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    // MARK: - Public Methods
    
    func update() {
        let issue = self.issue
        let _download = issue?.download
        let isDownloading = _download?.state == .progress || _download?.state == .pause
        
        self.textLabel?.text = issue?.title

        let size = issue?.size ?? 0
        self.detailTextLabel?.text = isDownloading
        ? " "
        : issue?.date.map { self.dateFormatter.string(from: $0) +  (size > 0 ? ", \(size) bytes" : "")}
        
        let progressView = self.progressView
        progressView.isHidden = !isDownloading

        let button = self.button
        button.isEnabled = true
        button.isHidden = issue == nil
        
        guard let download = _download else { return }
        
        var title: String?
        switch download.state {
        case .ready:
            title = "Open"
        case .pause:
            title = "Resume"
        case .progress:
            title = "Pause"
        case .stop:
            title = "Download"
        @unknown default:
            title = "Unknown"
        }
        
        progressView.progress = Float(download.progress) / 100

        if button.title(for: .normal) != title {
            button.setTitle(title, for: .normal)
            button.sizeToFit()
        }
    }
}
