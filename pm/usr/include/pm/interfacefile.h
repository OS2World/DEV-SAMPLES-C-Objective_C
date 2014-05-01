#ifndef _INTERFACEFILE_H_
#define _INTERFACEFILE_H_

#ifndef _BUTTON_H_
#include <pm/Button.h>
#endif

#include <objc/Object.h>
#include <objc/TypedStream.h>

typedef struct {
  char *key;
  id    object;
} KeyedObject;

struct outlet_action_structure {
  char *source;
  char *target;
  char *command;
};

typedef struct {
  char *key;
  char *class;
} Classes;

typedef struct outlet_action_structure Action;
typedef struct outlet_action_structure Outlet;

#define INVALID_INDEX (int) -1

@interface InterfaceFile : Object
{
  int          objectCount;
  KeyedObject *keyedObject;

  int          actionCount;
  Action      *action;

  int          outletCount;
  Outlet      *outlet;

  int          classCount;
  Classes     *classes;
}

- init;
- free;          /* only free this object */
- freeObjects;   /* also free objects in the list */
- freeAll;       /* free this object, all objects in list and key strings */

- (char *) keyFor: (int) index;
- objectFor: (int) index;
- (int) objectCount;

- addObject: anObject withKey: (char *) aKey;
- objectForKey: (char *) aKey;
- deleteObjectWithKey: (char *) aKey;
- (int) indexForKey: (char *) aKey;
- (int) indexForObject: anObject;

- (KeyedObject *) keyedObjectAt: (int) index;

- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStrem;

@end

#endif
