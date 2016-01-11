/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <XCTest/XCTest.h>

@class FBSimulatorControl;
@class FBSimulatorPool;
@class FBSimulatorSession;
@protocol FBInteraction;

/**
 FBSimulatorControl Assertion Helpers.
 */
@interface XCTestCase (FBSimulatorControlAssertions)

#pragma mark Interactions

/**
 Assertion Failure if the Interaction Fails.
 */
- (void)assertInteractionSuccessful:(id<FBInteraction>)interaction;

/**
 Assertion Failure if the Interaction Succeeds.
 */
- (void)assertInteractionFailed:(id<FBInteraction>)interaction;

#pragma mark Sessions

/**
 Assertion failure if the Session fails to terminate
 */
- (void)assertShutdownSimulatorAndTerminateSession:(FBSimulatorSession *)session;

#pragma mark Strings

/**
 Assertion failure if the needle can't be found in the haystack.
 */
- (void)assertNeedle:(NSString *)needle inHaystack:(NSString *)haystack;

@end

/**
 Assertion Helpers for FBSimulatorControl Notifications.
 */
@interface FBSimulatorControlNotificationAssertions : NSObject

+ (instancetype)withTestCase:(XCTestCase *)testCase pool:(FBSimulatorPool *)pool;

/**
 Assertion Failure if a notification of the given name isn't the first in the list of received notifications.
 */
- (NSNotification *)consumeNotification:(NSString *)notificationName;

/**
 Assertion Failure if a notification of the given name isn't the first in the list of received notifications.
 Will wait timeout seconds for the notification to appear if there isn't a notification recieved.
 */
- (NSNotification *)consumeNotification:(NSString *)notificationName timeout:(NSTimeInterval)timeout;

/**
 Assertion Failure if all of the notifications don't appear in the list of notifications recieved.s
 Ordering doesn't matter but the notifications must be contiguous.
 */
- (NSNotification *)consumeNotifications:(NSArray *)notificationNames;

/**
 Assertion failure if there are pending notifications.
 */
- (void)noNotificationsToConsume;

/**
 Removes all pending notifications
 */
- (void)consumeAllNotifications;

@end
