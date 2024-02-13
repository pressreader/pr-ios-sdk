//
//  PRUI.h
//  PRUI
//
//  Created by berec on 08/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for PRUI.
FOUNDATION_EXPORT double PRUIVersionNumber;

//! Project version string for PRUI.
FOUNDATION_EXPORT const unsigned char PRUIVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PRUI/PublicHeader.h>

#import "PRMainVC.h"
#import "PREPubReaderLinker.h"
#import "VerticalTextFlowView.h"
#import "PRAppPanelsManager.h"
#import "PRFeedbackController.h"

#import "PRStylingTableVC.h"
#import "UIView+CustomSeparator.h"
#import "UITableView+FullHeightWithResizableHeader.h"

#import "PROrder.h"
#import "PROrderEnum.h"

#import "PROrderDelivery+Error.h"

#import "PREmailSignInOptions.h"

#import "PRActivityItem.h"
#import "PRActivityProvider.h"

#import "NTFCommentsDataSource.h"
#import "PRCommentComposeVC.h"
#import "PRCommentTableVC.h"
#import "PRAttachmetsContainerView.h"

#import "NTFBookmarksDataSource.h"
#import "PRCurrentAccountBookmarkDataSource.h"

#import "PRBookmarkListVC.h"

#import "PRCollectionViewFlowLayout.h"
#import "PRCollectionViewAlignedLayout.h"

#import "PRPubHubDataSource.h"

#import "PRPubHubVerticalFlowLayout.h"

#import "PREmbedablePubHubVC.h"
#import "PRPubHubVC.h"

#import "PRSourceCollectionVC.h"
#import "PRSourcesHorizontalCollectionVC.h"
#import "PRSourceCategoriesCollectionVC.h"
#import "PRGroupedExemplarsCollectionVC.h"

#import "PRSourceItemCell.h"
#import "PRSourceItemCellGrid.h"
#import "PRSourceItemCellList.h"

#import "VerticalTextFlowVC.h"
#import "VerticalTextFlowVC+Statistics.h"
#import "PRVerticalFeedVC.h"
#import "VerticalTextFlowVC+ActionMenu.h"
#import "CustomStyleableTextFlowVC.h"

#import "LibraryItemFeedUtil.h"

#import "VerticalTextFlowArticleDetailsVC.h"
#import "PRArticleContainerVC.h"

#import "PRSettingsMasterPanelVC.h"
#import "PRSettingsDetailsPanelVC.h"
#import "PRGeneralSettingsDetailsPanelVC.h"

#import "PRAccountInfoCell.h"

#import "PRAuthorizeView.h"
#import "PRAccountVC.h"

#import "PRBasePaymentOptionsVC.h"

#import "PRDownloadedVC.h"

#import "PRExecutable.h"
#import "PROnlineValidator.h"

#import "PROnlineCommand.h"
#import "PRCommandOpenCatalog.h"
#import "PRCommandOpenDownloaded.h"
#import "PRCommandAuthorizeAccount.h"
#import "PRCommandOpenOrder.h"
#import "PRCommandOpenHomeFeed.h"
#import "PRCommandOpenReader.h"

#import "UINavigationController+Presentation.h"
#import "PRModalNavigationController.h"

#import "PRSubscriptionBundle+PlanType.h"

#import "PRSignInOption+Display.h"

#import "UIViewController+Popover.h"
#import "UIViewController+AccountObserver.h"
#import "UIViewController+Modal.h"
#import "UIViewController+NavigationState.h"
#import "UIViewController+StatusBar.h"
#import "UIViewController+Size.h"

#import "PRAppMenu.h"
#import "PRAppMenuVC.h"

#import "PRAuthorizeVC.h"

#import "PRErrorManager.h"

#import "PRTipButton.h"

#import "PRAppStyle+Categories.h"

#import "PRActionMenuVC.h"

#import "PROrderParametersCell.h"

#import "PRBannerPresentationConfig.h"

#import "PRProductCell.h"

#import "NTFBaseHomeFeedDataSource.h"

#import "PRLoadMoreView.h"

#import "PROrderThumbnailView.h"

#import "PRPasswordRecoveryVC.h"

#import "UITableViewCell+TintedDisclosureIndicator.h"

#import "NTFDataSource.h"
#import "NTFHomeFeedDataSource.h"
#import "PRFeedLayoutManager.h"
#import "NTFMyLibraryItemDataSource.h"

#import "PRBookmarkEditVC.h"

#import "SelectionTableViewController.h"

#import "PRAccountManager+ExternalAuthUI.h"

#import "PRArticleIssueThumbnail.h"

#import "NTFCompactFlowCell.h"
#import "NTFArticleSetCell.h"

#import "PRBannersHubVC.h"

#import "PROnlineViewCtrl.h"

#import "PRSourceItemManager.h"

#import "ReadingViewController.h"
#import "PRPDFScrollView.h"
#import "ReadingMapFrame.h"

#import "PressReader.h"
#import "PRModel+API.h"

#import "PRCalendarDelegate.h"

#import "NTFArticlesSearchDataSource.h"
#import "NTFCompactArticleCell.h"

#import "PRSectionHeaderView.h"
#import "PRCatalogSectionHeaderView.h"
#import "PRSeeAllButton.h"

#import "AdDataSource+Service.h"

#import "CompatibilityFactory.h"

#import "NTFLabeledArticleCell.h"
#import "NTFArticleCompactViewMetaInfo.h"
#import "PRCommandOpenArticle.h"

#import "_PRSocialManager.h"
#import "PRFacebookSignInManager.h"
#import "PRGoogleSignInManager.h"
#import "PRProgressButton.h"
#import "ViewRefreshable.h"

#import "PROrderBannerVC.h"

#import "PRAlignedImageView.h"

#import "NTFFeedDataSource+Search.h"

#import "PRCategoryCell.h"
#import "PRRadioVC.h"
#import "PRRadioManager.h"
#import "PROrderVC.h"
#import "PRSelectionPanelVC.h"
#import "PREditAccountVC.h"

// Protected API
#import "PRVerticalFeedVC_Protected.h"
#import "PREmbedablePubHubVC_Protected.h"
#import "VerticalTextFlowVC_Protected.h"
#import "ModalVideoPlayerVC.h"
#import "PhotoGalleryVC.h"
#import "PRAVPlayerActor.h"
#import "PRScrollAnimationSynchronizer.h"
#import "PRImageDetailsCaptionView.h"
#import "PRHotSpotServicesBannerVC.h"
#import "PRBannerProvider.h"
#import "PRMyAccountMasterPanelVC.h"
#import "PRPremiumBannerView.h"
#import "PRPubHubDataSource_Protected.h"
#import "PRAppMenu_Protected.h"
#import "PRUniversalMasterVC_Protected.h"
#import "NTFSmartArticleDataItem.h"
#import "PROrderModel.h"
#import "PRDebugSettingsDetailsPanelVC.h"
#import "PRCatalogFilterTableCell.h"
#import "PRRelatedArticlesView.h"
#import "NTFRelatedArticleCell.h"
