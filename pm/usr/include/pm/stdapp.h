#ifndef _STDAPP_H_
#define _STDAPP_H_

#define INCL_PM
#include <objc/os2.h>
#include <objc/Object.h>

@interface StdApp : Object
{
  HAB    hab;
  HMQ    hmq;
}

- init;
- free;
- run;

- (HAB) hab;

- loadIBFile: (char *) fileName;

@end

#endif
