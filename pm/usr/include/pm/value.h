#ifndef _VALUE_H_
#define _VALUE_H_

@protocol Value
- (char *) stringValue;
- (int) intValue;
- (long) longValue;
- (float) floatValue;

- setStringValue: (char *) aValue;
- setIntValue: (int) aValue;
- setLongValue: (long) aValue;
- setFloatValue: (float) aValue;
@end

#endif
