#import "JVChatTranscript.h"

@interface JVChatSession : NSObject <JVChatTranscriptElement>
- (/* xmlNode */ void *) node;
@property (readonly, weak) JVChatTranscript *transcript;
- (NSDate *) startDate;
@end
