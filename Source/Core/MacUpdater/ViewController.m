// Copyright 2019 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad
{
  [super viewDidLoad];
  NSWindow* window = [[self view] window];

  [window setLevel:kCGMainMenuWindowLevel - 1];
  [window setCollectionBehavior:NSWindowCollectionBehaviorStationary |
                                NSWindowCollectionBehaviorCanJoinAllSpaces |
                                NSWindowCollectionBehaviorFullScreenAuxiliary];
}

- (void)SetDescription:(NSString*)string
{
  [_labelProgress setStringValue:string];
}

- (void)SetTotalMarquee:(bool)marquee
{
  [_progressTotal setIndeterminate:marquee];
}

- (void)SetCurrentMarquee:(bool)marquee
{
  [_progressCurrent setIndeterminate:marquee];
}

- (void)SetTotalProgress:(double)current total:(double)total
{
  [_progressTotal setMaxValue:total];
  [_progressTotal setDoubleValue:current];
}

- (void)SetCurrentProgress:(double)current total:(double)total
{
  [_progressCurrent setMaxValue:total];
  [_progressCurrent setDoubleValue:current];
}

- (void)setRepresentedObject:(id)representedObject
{
  [super setRepresentedObject:representedObject];
}

@end
