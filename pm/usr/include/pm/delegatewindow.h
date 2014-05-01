#ifndef _DELEGATEWINDOW_H_
#define _DELEGATEWINDOW_H_

#ifndef _WINDOW_H_
#include <pm/Window.h>
#endif

@interface DelegateWindow : Window
{
  id delegate;
}

- init;
- setDelegate: anObject;
- delegate;

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;

@end

#endif
