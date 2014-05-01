#ifndef _DBLIST_H_
#define _DBLIST_H_

#ifndef _DBRECORD_H_
#include "DBRecord.h"
#endif

@interface DBList : Object
{
  DBRecord *firstRecord;
  DBFile   *database;
  int       count;
}

- init;
- initForDatabase: (DBFile *) aDatabase;
- free;

- insertRecord: (DBRecord *) aRecord;
- insertRecord: (DBRecord *) aRecord at: (int) index;
- deleteRecordAt: (int) index;
- findRecordAt: (int) index;

- fetchAllRecords;
- saveChanges: sender;

- setDatabase: (DBFile *) aDatabase;
- (DBFile *) database;
- (int) count;

@end

#endif
