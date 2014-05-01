#ifndef _DBRECORD_H_
#define _DBRECORD_H_

#ifndef _DBFILE_H_
#include "DBFile.h"
#endif

@interface DBRecord : Object
{
  DBRecord *nextRecord;
  DBFile   *database;
  long      recNo;
  void     *buffer;
  BOOL      changed;
}

- initForDatabase: (DBFile *) aDatabase;
- free;

- insert: (DBRecord *) aRecord at: (int) index;
- deleteAt: (int) index;
- findAt: (int) index;

- copyToDB;
- copyFromDB;
- replace;

- saveChanges: sender;

- setChanged: (BOOL) value;
- (BOOL) changed;

- (long) recNo;

- setNext: (DBRecord *) aRecord;
- next;

@end

#endif
