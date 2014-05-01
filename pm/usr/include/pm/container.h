#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

#ifndef _OS2TYPES_H_
#include <pm/OS2Types.h>
#endif

@interface Container : FactoryWindow <Archiving>
{
  ULONG              createFlags;
  CONTAINER_MINIREC *recordBuffer;
  FIELDINFO         *columnBuffer;
}

/*
 * Initializing an object
 */
- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;
- addColumn: (char *) aTitle;

/*
 * Inserting data
 */
- insertObject: anObject;
- insertObject: anObject withTitle: (const char *) aTitle;
- insertObject: anObject withTitle: (const char *) aTitle andIcon: (ULONG) anIcon;

/*
 * Set look & feel of object
 */
- arrange;
- iconView: sender;
- nameView: sender;
- textView: sender;
- treeView: sender;
- detailView: sender;

/*
 * Query contents
 */
- (ULONG) records;
- object;

- (CONTAINER_MINIREC *) firstRecord;
- (CONTAINER_MINIREC *) lastRecord;
- (CONTAINER_MINIREC *) nextRecord;
- (CONTAINER_MINIREC *) previousRecord;
- (CONTAINER_MINIREC *) firstSelected;
- (CONTAINER_MINIREC *) nextSelected;
- (BOOL) recordIsSelected;

- invalidateRecord;
- invalidateSelectedRecords;

- hideRecord : sender;
- hideSelectedRecords : sender;
- hideNotSelectedRecords : sender;
- showRecord : sender;
- showAllRecords : sender;
- (BOOL) recordIsHidden;

/*
 * Query column information
 */
- (ULONG) columns;

- (FIELDINFO *) firstColumn;
- (FIELDINFO *) lastColumn;
- (FIELDINFO *) nextColumn;
- (FIELDINFO *) previousColumn;

- (char *) columnTitle;
- (ULONG) columnTitleAttributes;
- (ULONG) columnDataAttributes;

- hideColumn : sender;
- showColumn : sender;
- showAllColumns : sender;
- (BOOL) columnIsHidden;

- invalidateColumns;
- setColumnTitleAttributes: (ULONG) attr;
- setColumnDataAttributes: (ULONG) attr;

/*
 * selecting and deselecting
 */
- select;
- deselect;
- selectAll: sender;
- deselectAll: sender;

/*
 * Sorting the records
 */
- sort: (ULONG) column;

/*
 * Archiving the object
 */
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

- createInPMWindow: (HWND) hwnd;

- (MRESULT) handleMessage: (ULONG) msg 
               withParams: (MPARAM) mp1 and: (MPARAM) mp2;

@end

SHORT compareColumn (CONTAINER_MINIREC *record1,
		     CONTAINER_MINIREC *record2,
		     ULONG column);

#endif
