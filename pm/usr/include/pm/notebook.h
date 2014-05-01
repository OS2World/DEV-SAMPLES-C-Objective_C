#ifndef _NOTEBOOK_H_
#define _NOTEBOOK_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

@interface NoteBook : FactoryWindow
{
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

- (ULONG) createTopPageWithStatusText: (BOOL) stFlag;
- (ULONG) createMajorTopPageWithStatusText: (BOOL) stFlag;
- (ULONG) createMinorTopPageWithStatusText: (BOOL) stFlag;

- (ULONG) createLastPageWithStatusText: (BOOL) stFlag;
- (ULONG) createMajorLastPageWithStatusText: (BOOL) stFlag;
- (ULONG) createMinorLastPageWithStatusText: (BOOL) stFlag;

- (ULONG) createPageBefore: (ULONG) pageID withStatusText: (BOOL) stFlag;
- (ULONG) createMajorPageBefore: (ULONG) pageID withStatusText: (BOOL) stFlag;
- (ULONG) createMinorPageBefore: (ULONG) pageID withStatusText: (BOOL) stFlag;

- (ULONG) createPageAfter: (ULONG) pageID withStatusText: (BOOL) statusFlag;
- (ULONG) createMajorPageAfter: (ULONG) pageID withStatusText: (BOOL) stFlag;
- (ULONG) createMinorPageAfter: (ULONG) pageID withStatusText: (BOOL) stFlag;

- deletePage: (ULONG) pageID;
- deleteAllPages;

- setStatusLineTextFor: (ULONG) pageID to: (char *) aString;
- setTabTextFor: (ULONG) pageID to: (char *) aString;

- setMajorTabDimensions: (USHORT) width : (USHORT) height;
- setMinorTabDimensions: (USHORT) width : (USHORT) height;
- setPageButtonDimensions: (USHORT) width : (USHORT) height;

- setPage: (ULONG) pageID to: (Window *) aWindow;

@end

#endif
