#ifndef _DBFIELD_H_
#define _DBFIELD_H_

#include <objc/Object.h>

#include "DBTypes.h"

@interface DBField : Object
{
   DBField      *next;
   char         *data,
                 length,
                 decimals,
                *name,
                *string;
}

- initWithName: (char *) aName andLength: (char) aLength 
   andDecimals: (char) someDecimals;
- free;
- setData: (void *) aPointer;
- (char *) data;
- add: (DBField *) newField;
- next;
- printRecord;
- printInfo;
- setString: (char *) aString;
- (char *) string;
- (char *) titleString;

@end

#endif

