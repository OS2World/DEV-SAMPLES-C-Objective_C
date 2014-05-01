#ifndef _WINDOWDELEGATE_H_
#define _WINDOWDELEGATE_H_

@protocol CommandDelegate
- buttonWasPressed: (ULONG) buttonId : sender;
- menuWasSelected: (ULONG) menuId : sender;
- commandPosted: (ULONG) origin : sender;
@end

@protocol SysCommandDelegate
- sysButtonWasPressed: (ULONG) buttonId : sender;
- sysMenuWasSelected: (ULONG) menuId : sender;
- sysCommandPosted: (ULONG) origin : sender;
@end

@protocol WindowDelegate
- (MRESULT) handleMessage: (ULONG) msg withParams: (MPARAM) mp1 
            and: (MPARAM) mp2 : sender;
- windowWillClose: sender;
- windowDidClose: sender;
- windowDidMove: sender;
- windowDidResizeFrom: (LONG) oldX : (LONG) oldY 
                   to: (LONG) newX : (LONG) newY : sender;
- windowDidResize: sender;
- windowWasSelected: sender;
- windowWasDeSelected: sender;
@end

@protocol ContainerObject
- (CHAR *) fieldData: (ULONG) field;
@end

@protocol ContainerDelegate
- showContextMenu: (PRECORDCORE) recordCore;
- enterPressed: (NOTIFYRECORDENTER *) recordEnter;
- changeString: (CNREDITDATA *) editData;
- stringChanged: (CNREDITDATA *) editData;
@end

@protocol EntryFieldDelegate
- textChanged: sender;
- focusLost: sender;
- focusReceived: sender;
@end

#endif
