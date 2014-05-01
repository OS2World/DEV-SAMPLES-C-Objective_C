#ifndef _PRESENTATIONSPACE_H_
#define _PRESENTATIONSPACE_H_

#ifndef _OS2EMX_H
#define INCL_PM
#include <objc/os2.h>
#endif

#include <objc/Object.h>

@interface PresentationSpace : Object
{
  HPS   hps;
  float spacing;
  LONG  xResolution;
  LONG  yResolution;
  LONG  textHeight;
}

- init;

- setHPS: (HPS) aHPS;
- (HPS) hps;

// form definition
- (LONG) widthInPels;
- (LONG) widthInMm;
- (LONG) heightInPels;
- (LONG) heightInMm;

- (LONG) xResolution;
- (LONG) yResolution;

- (LONG) textHeight;

// font settings
- setSpacing: (float) ratio;
- (float) spacing;

- setFont: (char *) fontName;
- setFont: (char *) fontName at: (LONG) pointSize;
- setFontSize: (LONG) pointSize;

// methods for drawing characters & strings
- (LONG) stringWidth: (char *) aString;
- (LONG) stringBoxWidth: (char *) stringBox;
- (LONG) stringBoxHeight: (char *) stringBox;

- string: (char *) aString;
- string: (char *) aString at: (LONG) x : (LONG) y;
- stringBox: (char *) stringBox;
- stringBox: (char *) stringBox at: (LONG) x : (LONG) y;

// methods for putting graphics to HPS
- lineTo: (LONG) x : (LONG) y;
- lineFrom: (LONG) x0 : (LONG) y0 to: (LONG) x : (LONG) y;

@end

#endif
