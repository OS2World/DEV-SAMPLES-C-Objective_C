#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <pm/pm.h>
#include <db/db.h>

@interface Controller : Object
{
  StdDialog *insertRecord;
  StdDialog *replaceRecord;
  StdDialog *infoRecord;

  id insertName;
  id insertAddress;
  id insertPhone;
  id insertFax;
  id insertEMail;
  id replaceName;
  id replaceAddress;
  id replacePhone;
  id replaceFax;
  id replaceEMail;
  id infoName;
  id infoAddress;
  id infoPhone;
  id infoFax;
  id infoEMail;

  DBFile *database;
  DBList *recordList;
}

- init;
- free;

- readList: sender;

- insert: sender;
- replace: sender;
- info: sender;
- delete: sender;

- closeApp: sender;
- windowDidResize: sender;

@end

#endif
