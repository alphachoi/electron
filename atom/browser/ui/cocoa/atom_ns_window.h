// Copyright (c) 2018 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_UI_COCOA_ATOM_NS_WINDOW_H_
#define ATOM_BROWSER_UI_COCOA_ATOM_NS_WINDOW_H_

#include "brightray/browser/mac/event_dispatching_window.h"
#include "ui/views/cocoa/native_widget_mac_nswindow.h"

namespace atom {

class NativeWindowMac;

// Prevents window from resizing during the scope.
class ScopedDisableResize {
 public:
  ScopedDisableResize() { disable_resize_ = true; }
  ~ScopedDisableResize() { disable_resize_ = false; }

  static bool IsResizeDisabled() { return disable_resize_; }

 private:
  static bool disable_resize_;
};

}  // namespace atom

@interface AtomNSWindow : EventDispatchingWindow {
 @private
  atom::NativeWindowMac* shell_;
  CGFloat windowButtonsInterButtonSpacing_;
}
@property BOOL acceptsFirstMouse;
@property BOOL enableLargerThanScreen;
@property BOOL disableAutoHideCursor;
@property BOOL disableKeyOrMainWindow;
@property NSPoint windowButtonsOffset;
@property (nonatomic, retain) NSView* vibrantView;
- (void)setShell:(atom::NativeWindowMac*)shell;
- (void)enableWindowButtonsOffset;
- (void)toggleFullScreenMode:(id)sender;
@end

#endif  // ATOM_BROWSER_UI_COCOA_ATOM_NS_WINDOW_H_
