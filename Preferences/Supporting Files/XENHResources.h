//
//  XENPResources.h
//  
//
//  Created by Matt Clarke on 21/11/2015.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define orient3 [[UIApplication sharedApplication] statusBarOrientation]

#define SCREEN_MAX_LENGTH (MAX([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height))
#define SCREEN_MIN_LENGTH (MIN([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height))

#define SCREEN_HEIGHT (orient3 == 1 || orient3 == 2 ? SCREEN_MAX_LENGTH : SCREEN_MIN_LENGTH)
#define SCREEN_WIDTH (orient3 == 1 || orient3 == 2 ? SCREEN_MIN_LENGTH : SCREEN_MAX_LENGTH)

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

@protocol XENHEditorController <NSObject>
-(id)view;
-(void)saveData;
-(void)cancelChanges;
-(void)addNewWidgetWithFilePath:(NSString*)filePath;
-(void)configureNoHTMLLabel:(BOOL)isEditing;
-(void)setIsEditing:(BOOL)editing;
-(NSString*)currentFilePath;
-(NSDictionary*)currentMetadataOptions;
-(void)updateMetadataWithNewOptions:(NSDictionary*)options;
-(void)reloadWebView;
@end

typedef enum : NSUInteger {
    kLocationBackground,
    kLocationForeground,
    kLocationWidgets,
    kLocationSBHTML
} XENHViewLocation;

@protocol XENHPreviewCellStateDelegate
- (void)didChangeEnabledState:(BOOL)state forVariant:(int)variant;
- (void)didChangeSkewPercentage:(CGFloat)percent forVariant:(int)variant;
@end

@interface XENHResources : NSObject

+(CGRect)boundedRectForFont:(UIFont*)font andText:(NSString*)text width:(CGFloat)width;

+(void)reloadSettings;
+(NSString*)foregroundLocation;
+(NSString*)backgroundLocation;
+(NSString*)SBLocation;

+(NSDictionary*)widgetPrefs;

+(CGFloat)editorGetWidgetSize;

+(NSString*)localisedStringForKey:(NSString*)key value:(NSString*)val;
+(NSString*)imageSuffix;

+(void)setPreferenceKey:(NSString*)key withValue:(id)value;
+(id)getPreferenceKey:(NSString*)key;

/* Preview cell shenanigans */
+ (void)addPreviewObserverForStateChanges:(id<XENHPreviewCellStateDelegate>)observer identifier:(NSString*)identifer;
+ (void)removePreviewObserverWithIdentifier:(NSString*)identifier;
+ (BOOL)getPreviewStateForVariant:(int)variant;
+ (void)setPreviewState:(BOOL)state forVariant:(int)variant;
+ (CGFloat)getPreviewSkewPercentageForVariant:(int)variant;
+ (void)setPreviewSkewPercentage:(CGFloat)skewPercentage forVariant:(int)variant;
+ (void)updatePreviewSkewPercentage:(CGFloat)skewPercentage forVariant:(int)variant;

+ (BOOL)isCurrentDeviceD22;

@end