#import "MVChatPluginManager.h"

@interface JVAppleScriptChatPlugin : NSObject <MVChatPlugin> {
	MVChatPluginManager *_manager;
	NSAppleScript *_script;
	NSString *_path;
	NSMutableSet *_doseNotRespond;
	NSTimer *_idleTimer;
	NSDate *_modDate;
}
- (id) initWithScript:(NSAppleScript *) script atPath:(NSString *) path withManager:(MVChatPluginManager *) manager;
- (id) initWithScriptAtPath:(NSString *) path withManager:(MVChatPluginManager *) manager;

@property (strong) NSAppleScript *script;

- (void) reloadFromDisk;

- (MVChatPluginManager *) pluginManager;

@property (copy) NSString *scriptFilePath;

- (id) callScriptHandler:(OSType) handler withArguments:(NSDictionary *) arguments forSelector:(SEL) selector;

- (BOOL) respondsToSelector:(SEL) selector;
- (void) doesNotRespondToSelector:(SEL) selector;
@end

@interface NSAppleScript (NSAppleScriptIdentifier)
- (NSNumber *) scriptIdentifier;
@end
