#ifndef _FACTORYWINDOW_H_
#define _FACTORYWINDOW_H_

#ifndef _DELEGATEWINDOW_H_
  #include <pm/DelegateWindow.h>
#endif

@interface FactoryWindow : DelegateWindow
{
  HWND owner;
}

- initIn: (Window *) parent;
- associate: (HWND) hwnd;

- destroy;

- createInPMWindow: (HWND) hwnd;

- (MRESULT) handleMessage: (ULONG) msg
            withParams: (MPARAM) mp1 and: (MPARAM) mp2;

- specialClass;

@end

#endif
