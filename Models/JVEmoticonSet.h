extern NSString *JVEmoticonSetsScannedNotification;

@interface JVEmoticonSet : NSObject {
	NSBundle *_bundle;
	NSDictionary *_emoticonMappings;
	NSArray *_emoticonMenu;
}
+ (void) scanForEmoticonSets;
+ (NSSet *) emoticonSets;
+ (instancetype) emoticonSetWithIdentifier:(NSString *) identifier;
+ (instancetype) newWithBundle:(NSBundle *) bundle;

+ (instancetype) textOnlyEmoticonSet;

- (instancetype) initWithBundle:(NSBundle *) bundle;

- (void) unlink;
@property (readonly, getter=isCompliant) BOOL compliant;

- (void) performEmoticonSubstitution:(NSMutableAttributedString *) string;

- (NSBundle *) bundle;
- (NSString *) identifier;

- (NSComparisonResult) compare:(JVEmoticonSet *) style;
@property (readonly, copy) NSString *displayName;

- (NSDictionary *) emoticonMappings;
- (NSArray *) emoticonMenuItems;

- (NSURL *) baseLocation;
- (NSURL *) styleSheetLocation;

- (NSString *) contentsOfStyleSheet;
@end
