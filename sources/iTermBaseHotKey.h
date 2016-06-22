//
//  iTermBaseHotKey.h
//  iTerm2
//
//  Created by George Nachman on 5/22/16.
//
//

#import <Cocoa/Cocoa.h>

@class iTermProfileHotKey;

@protocol iTermHotKeyDelegate<NSObject>
- (void)didFinishRollingOutProfileHotKey:(iTermProfileHotKey *)profileHotKey;
- (void)suppressHideApp;
- (void)storePreviouslyActiveApp;
@end

// Abstract base class.
@interface iTermBaseHotKey : NSObject

@property(nonatomic, assign) NSUInteger keyCode;
@property(nonatomic, assign) NSEventModifierFlags modifiers;
@property(nonatomic, copy) NSString *characters;
@property(nonatomic, copy) NSString *charactersIgnoringModifiers;
@property(nonatomic, assign) id<iTermHotKeyDelegate> delegate;

- (instancetype)initWithKeyCode:(NSUInteger)keyCode
                      modifiers:(NSEventModifierFlags)modifiers
                     characters:(NSString *)characters
    charactersIgnoringModifiers:(NSString *)charactersIgnoringModifiers NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (void)register;
- (void)unregister;

@end

@interface iTermBaseHotKey(Internal)
- (BOOL)keyDownEventTriggers:(NSEvent *)event;
- (void)simulatePress;
@end
