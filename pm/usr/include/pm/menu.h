#ifndef _MENU_H_
#define _MENU_H_

#ifndef _WINDOW_H_
#include <pm/Window.h>
#endif

@interface Menu : Window
{
}

- enableItem: (USHORT) identifier;
- disableItem: (USHORT) identifier;

@end

#endif
