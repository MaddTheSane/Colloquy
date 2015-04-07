#import "JVInspectorController.h"

@class MVMenuButton;
@class MVChatConnection;
@class JVChatWindowController;

@protocol JVChatViewController;
@protocol JVChatListItem;

extern NSString *JVToolbarToggleChatDrawerItemIdentifier;
extern NSString *JVChatViewPboardType;

@interface JVChatWindowController : NSWindowController <JVInspectionDelegator, NSMenuDelegate, NSOutlineViewDataSource, NSOutlineViewDelegate, NSToolbarDelegate, NSWindowDelegate> {
	@protected
	IBOutlet NSDrawer *viewsDrawer;
	IBOutlet NSOutlineView *chatViewsOutlineView;
	IBOutlet MVMenuButton *viewActionButton;
	IBOutlet MVMenuButton *favoritesButton;
	NSString *_identifier;
	NSMutableDictionary *_settings;
	NSMutableArray *_views;
	id <JVChatViewController> _activeViewController;
	BOOL _usesSmallIcons;
	BOOL _showDelayed;
	BOOL _reloadingData;
	BOOL _closing;
}
@property (copy) NSString *identifier;

@property (readonly, copy) NSString *userDefaultsPreferencesKey;
- (void) setPreference:(id) value forKey:(NSString *) key;
- (id) preferenceForKey:(NSString *) key;

- (void) showChatViewController:(id <JVChatViewController>) controller;

- (void) addChatViewController:(id <JVChatViewController>) controller;
- (void) insertChatViewController:(id <JVChatViewController>) controller atIndex:(NSUInteger) index;

- (void) removeChatViewController:(id <JVChatViewController>) controller;
- (void) removeChatViewControllerAtIndex:(NSUInteger) index;
- (void) removeAllChatViewControllers;

- (void) replaceChatViewController:(id <JVChatViewController>) controller withController:(id <JVChatViewController>) newController;
- (void) replaceChatViewControllerAtIndex:(NSUInteger) index withController:(id <JVChatViewController>) controller;

- (NSArray *) chatViewControllersForConnection:(MVChatConnection *) connection;
- (NSArray *) chatViewControllersWithControllerClass:(Class) class;
@property (readonly, copy) NSArray *allChatViewControllers;

@property (readonly, strong) id<JVChatViewController> activeChatViewController;
@property (readonly, strong) id<JVChatListItem> selectedListItem;

- (IBAction) getInfo:(id) sender;

- (IBAction) joinRoom:(id) sender;

- (IBAction) closeCurrentPanel:(id) sender;
- (IBAction) detachCurrentPanel:(id) sender;
- (IBAction) selectPreviousPanel:(id) sender;
- (IBAction) selectPreviousActivePanel:(id) sender;
- (IBAction) selectNextPanel:(id) sender;
- (IBAction) selectNextActivePanel:(id) sender;

@property (readonly, copy) NSToolbarItem *toggleChatDrawerToolbarItem;
- (IBAction) toggleViewsDrawer:(id) sender;
- (IBAction) openViewsDrawer:(id) sender;
- (IBAction) closeViewsDrawer:(id) sender;
- (IBAction) toggleSmallDrawerIcons:(id) sender;

- (void) reloadListItem:(id <JVChatListItem>) controller andChildren:(BOOL) children;
- (BOOL) isListItemExpanded:(id <JVChatListItem>) item;
- (void) expandListItem:(id <JVChatListItem>) item;
- (void) collapseListItem:(id <JVChatListItem>) item;
@end

@interface JVChatWindowController (JVChatWindowControllerScripting)
@property (readonly, copy) NSNumber *uniqueIdentifier;
@end

@protocol JVChatViewController <JVChatListItem>
@optional
- (id <JVChatViewController>) activeChatViewController;

@required
- (MVChatConnection *) connection;

- (JVChatWindowController *) windowController;
- (void) setWindowController:(JVChatWindowController *) controller;

- (NSView *) view;
- (NSResponder *) firstResponder;
- (NSString *) toolbarIdentifier;
- (NSString *) windowTitle;
- (NSString *) identifier;

@optional
- (void) willSelect;
- (void) didSelect;

- (void) willUnselect;
- (void) didUnselect;

- (void) willDispose;
@end

@protocol JVChatListItemScripting
- (NSNumber *) uniqueIdentifier;
- (NSArray *) children;
- (NSString *) information;
- (NSString *) toolTip;
- (BOOL) isEnabled;
@end

@protocol JVChatViewControllerScripting <JVChatListItemScripting>
- (NSWindow *) window;
- (IBAction) close:(id) sender;
@end

@protocol JVChatListItem <NSObject>
- (id <JVChatListItem>) parent;
- (NSImage *) icon;
- (NSString *) title;

@optional
- (BOOL) acceptsDraggedFileOfType:(NSString *) type;
- (void) handleDraggedFile:(NSString *) path;
- (IBAction) doubleClicked:(id) sender;
- (BOOL) isEnabled;

- (NSMenu *) menu;
- (NSString *) information;
- (NSString *) toolTip;
- (NSImage *) statusImage;

- (NSUInteger) numberOfChildren;
- (id) childAtIndex:(NSUInteger) index;
@end

@interface NSObject (MVChatPluginToolbarSupport)
- (NSArray *) toolbarItemIdentifiersForView:(id <JVChatViewController>) view;
- (NSToolbarItem *) toolbarItemForIdentifier:(NSString *) identifier inView:(id <JVChatViewController>) view willBeInsertedIntoToolbar:(BOOL) willBeInserted;
@end
