#ifndef _DBSEARCHARG_H_
#define _DBSEARCHARG_H_

#include <objc/Object.h>

@interface DBSearchArg : Object
{
  int   fieldNumber;
  char  operator;
  char *operand;

  DBSearchArg *next;
}

- initForField: (int) aField
      operator: (char) anOperator
   withOperand: (char *) anOperand;
- free;

- add: (DBSearchArg *) anArg;
- next;

@end

#endif
