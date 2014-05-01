#ifndef _DBFILE_H_
#define _DBFILE_H_

#ifndef _DBTYPES_H_
#include "DBTypes.h"
#endif

#ifndef _DBFIELD_H_
#include "DBField.h"
#endif

#ifndef _DBSEARCHARG_H_
#include "DBSearchArg.h"
#endif

#include <stdio.h>

@interface DBFile : Object
{
   DBHEADER *dbHeader;
   DBField  *fieldList;

   FILE     *fileHandle;
   void     *buffer;
   long      currentRecord;
}

- init:(char *) fileName;
- create: (char *) fileName withFields: (int) count list: (DBFIELD *) fields;
- free;

- field: (int) fieldNumber;
- (int) fieldCount;

- readRecord: (long) offset;
- writeRecord: (long) offset;
- (long) currentRecord;
- (BOOL) deleted;

- append;
- replace;
- delete;
- undelete;
- clear;

- (BOOL) findFirst;
- (BOOL) findNext;

- (void *) copyBuffer;
- (void *) copyBufferTo: (void *) aBuffer;
- setBuffer: (void *) aBuffer;

- printRecord;
- printInfo;
- (long) recordCount;

@end

#endif
