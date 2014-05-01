/*
 * os2.h (emx+gcc)
 * special include file for objective c language
 * modified 06-05-1995 by Thomas Baier
 */

/* includes os2emx.h */

/* default location: /usr/include/objc/os2.h */

#if !defined (_OS2_H)

/*
 * conflicts with objc.h:       SEL, BOOL, id
 * solution:  prefixing those with _OS2_ before including os2emx.h
 */

#define SEL _OS2_SEL
#define BOOL _OS2_BOOL

#if defined (__cplusplus)
extern "C" {
#endif

#define _OS2_H

#define _Cdecl
#define _Far16
#define _Optlink
#define _Pascal
#define _Seg16
#define _System

#if defined (USE_OS2_TOOLKIT_HEADERS)
#include <os2tk.h>
#else
#include <os2emx.h>   /* <-- change this line to use Toolkit headers */
#endif
#include <os2thunk.h>

#if defined (__cplusplus)
}
#endif

#undef SEL
#undef BOOL

#endif /* !defined (_OS2_H) */
