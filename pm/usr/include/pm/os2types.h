#ifndef _OS2TYPES_H_
#define _OS2TYPES_H_

#include <objc/os2.h>
#include <objc/Object.h>

typedef struct {
  MINIRECORDCORE  mrcCore;
  id              object;
  CHAR           *fieldData[0];
} CONTAINER_MINIREC;

typedef struct {
  RECORDCORE rcCore;
  id         object;
} CONTAINER_REC;

typedef struct {
  USHORT cb;
  id     object;
} NEWCLASS_CDATA;

#endif
