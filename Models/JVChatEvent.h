#import "JVChatTranscript.h"

@interface JVChatEvent : NSObject <JVChatTranscriptElement> {
	@protected
	/* xmlNode */ void *_node;
	/* xmlDoc */ void *_doc;
	NSString *_eventIdentifier;
	NSScriptObjectSpecifier *_objectSpecifier;
	__weak JVChatTranscript *_transcript;
	NSDate *_date;
	NSString *_name;
	NSTextStorage *_message;
	NSDictionary *_attributes;
	BOOL _loadedMessage;
	BOOL _loadedAttributes;
	BOOL _loadedSmall;
}
- (/* xmlNode */ void *) node;

- (JVChatTranscript *) transcript;
- (NSString *) eventIdentifier;

@property (readonly, strong) NSDate *date;
@property (readonly, copy) NSString *name;

- (NSTextStorage *) message;
- (NSString *) messageAsPlainText;
- (NSString *) messageAsHTML;

- (NSDictionary *) attributes;
@end

@interface JVMutableChatEvent : JVChatEvent
+ (instancetype) chatEventWithName:(NSString *) name andMessage:(id) message;
- (instancetype) initWithName:(NSString *) name andMessage:(id) message;

@property (readwrite, strong) NSDate *date;
@property (readwrite, copy) NSString *name;

- (void) setMessage:(id) message;
- (void) setMessageAsPlainText:(NSString *) message;
- (void) setMessageAsHTML:(NSString *) message;

- (void) setAttributes:(NSDictionary *) attributes;

- (void) setEventIdentifier:(NSString *) identifier;
@end
