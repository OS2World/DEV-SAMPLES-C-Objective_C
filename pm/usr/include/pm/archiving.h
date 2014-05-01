#ifndef _ARCHIVING_H_
#define _ARCHIVING_H_

@protocol Archiving
- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
@end

#endif
