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

@property (readonly, strong) NSBundle *bundle;
@property (readonly, copy) NSString *identifier;

- (NSComparisonResult) compare:(JVEmoticonSet *) style;
@property (readonly, copy) NSString *displayName;

@property (readonly, copy) NSDictionary *emoticonMappings;
@property (readonly, copy) NSArray *emoticonMenuItems;

@property (readonly, copy) NSURL *baseLocation;
@property (readonly, copy) NSURL *styleSheetLocation;

@property (readonly, copy) NSString *contentsOfStyleSheet;
@end
