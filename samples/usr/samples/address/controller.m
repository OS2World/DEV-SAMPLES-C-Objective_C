#include "Controller.h"
#include "address.h"

@implementation Controller

- init
{
  insertRecord = [[StdDialog alloc] initWithId: IDD_INSREP];
  replaceRecord = [[StdDialog alloc] initWithId: IDD_INSREP];
  infoRecord = [[StdDialog alloc] initWithId: IDD_INFO];

  [insertRecord setText: "Insert new Record"];
  [replaceRecord setText: "Replace existing Record"];

  [insertRecord createObjects];
  [replaceRecord createObjects];
  [infoRecord createObjects];

  insertName = [insertRecord findFromID: IDD_NAMEENTRY];
  insertAddress = [insertRecord findFromID: IDD_ADDRESSENTRY];
  insertPhone = [insertRecord findFromID: IDD_PHONEENTRY];
  insertFax = [insertRecord findFromID: IDD_FAXENTRY];
  insertEMail = [insertRecord findFromID: IDD_EMAILENTRY];
  replaceName = [replaceRecord findFromID: IDD_NAMEENTRY];
  replaceAddress = [replaceRecord findFromID: IDD_ADDRESSENTRY];
  replacePhone = [replaceRecord findFromID: IDD_PHONEENTRY];
  replaceFax = [replaceRecord findFromID: IDD_FAXENTRY];
  replaceEMail = [replaceRecord findFromID: IDD_EMAILENTRY];
  infoName = [infoRecord findFromID: IDD_NAMEENTRY];
  infoAddress = [infoRecord findFromID: IDD_ADDRESSENTRY];
  infoPhone = [infoRecord findFromID: IDD_PHONEENTRY];
  infoFax = [infoRecord findFromID: IDD_FAXENTRY];
  infoEMail = [infoRecord findFromID: IDD_EMAILENTRY];

  database = [[DBFile alloc] init: "address.dbf"];
  recordList = [[DBList alloc] initForDatabase: database];

  return self;
}

- free
{
  [database free];
  [insertRecord free];
  [replaceRecord free];
  [infoRecord free];
  return [super free];
}

- readList: sender;
{
  ListBox *nameListBox = [sender findFromID: IDD_PUSHBUTTON1];
  int i;

  [recordList fetchAllRecords];

  for (i = 0;i < [recordList count];i++) {
    [[recordList findRecordAt: i] copyToDB];
    [nameListBox insertItem: LIT_END text: [[database field: 0] string]];
  }

  return self;
}

- insert: sender
{
  ListBox *nameListBox = [sender findFromID: IDD_PUSHBUTTON1];
  char *nameBuffer;
  char *addressBuffer;
  char *phoneBuffer;
  char *faxBuffer;
  char *emailBuffer;

  [database clear];

  [insertName setText: ""];
  [insertAddress setText: ""];
  [insertPhone setText: ""];
  [insertFax setText: ""];
  [insertEMail setText: ""];

  [insertRecord runModalFor: sender];

  if ([insertRecord result] == DID_OK) {
    nameBuffer = [insertName text: NULL];
    addressBuffer = [insertAddress text: NULL];
    phoneBuffer = [insertPhone text: NULL];
    faxBuffer = [insertFax text: NULL];
    emailBuffer = [insertEMail text: NULL];

    [[database field: 0] setString: nameBuffer];
    [[database field: 1] setString: addressBuffer];
    [[database field: 2] setString: phoneBuffer];
    [[database field: 3] setString: faxBuffer];
    [[database field: 4] setString: emailBuffer];

    [database append];
    [recordList insertRecord: [[DBRecord alloc] initForDatabase: database]];

    [nameListBox insertItem: LIT_END text: nameBuffer];

    free (nameBuffer);
    free (addressBuffer);
    free (phoneBuffer);
    free (faxBuffer);
    free (emailBuffer);
  }

  return self;
}

- replace: sender
{
  ListBox *nameListBox = [sender findFromID: IDD_PUSHBUTTON1];
  SHORT selected = [nameListBox selected];
  char *nameBuffer;
  char *addressBuffer;
  char *phoneBuffer;
  char *faxBuffer;
  char *emailBuffer;

  if (selected < 0)
    return nil;

  [[recordList findRecordAt: selected] copyToDB];

  [replaceName setText: [[database field: 0] string]];
  [replaceAddress setText: [[database field: 1] string]];
  [replacePhone setText: [[database field: 2] string]];
  [replaceFax setText: [[database field: 3] string]];
  [replaceEMail setText: [[database field: 4] string]];

  [replaceRecord runModalFor: sender];

  if ([replaceRecord result] == DID_OK) {
    nameBuffer = [replaceName text: NULL];
    addressBuffer = [replaceAddress text: NULL];
    phoneBuffer = [replacePhone text: NULL];
    faxBuffer = [replaceFax text: NULL];
    emailBuffer = [replaceEMail text: NULL];

    [[database field: 0] setString: nameBuffer];
    [[database field: 1] setString: addressBuffer];
    [[database field: 2] setString: phoneBuffer];
    [[database field: 3] setString: faxBuffer];
    [[database field: 4] setString: emailBuffer];

    [[recordList findRecordAt: selected] copyFromDB];
    [[recordList findRecordAt: selected] replace];

    [nameListBox deleteItem: selected];
    [nameListBox insertItem: selected text: nameBuffer];

    free (nameBuffer);
    free (addressBuffer);
    free (phoneBuffer);
    free (faxBuffer);
    free (emailBuffer);
  }

  return self;
}

- info: sender
{
  ListBox *nameListBox = [sender findFromID: IDD_PUSHBUTTON1];
  SHORT selected = [nameListBox selected];
  
  if (selected < 0)
    return nil;
  
  [[recordList findRecordAt: selected] copyToDB];

  [infoName setText: [[database field: 0] string]];
  [infoAddress setText: [[database field: 1] string]];
  [infoPhone setText: [[database field: 2] string]];
  [infoFax setText: [[database field: 3] string]];
  [infoEMail setText: [[database field: 4] string]];

  [infoRecord runModalFor: sender];

  return self;
}

- delete: sender
{
  ListBox *nameListBox = [sender findFromID: IDD_PUSHBUTTON1];
  SHORT selected = [nameListBox selected];
  char  numberBuffer[6];
  long  numberOfRecord;
  char *nameBuffer;

  if (selected < 0)
    return nil;

  if (WinMessageBox (HWND_DESKTOP,[sender window],
		     "Do you really want to delete the selected Item?",
		     "Addresses",
		     0,MB_YESNO | MB_QUERY) == MBID_YES) {
    numberOfRecord = atoi(numberBuffer);
    
    [database readRecord: [[recordList findRecordAt: selected] recNo]];

    [nameListBox deleteItem: selected];
    [database delete];
    [recordList deleteRecordAt: selected];
  }

  return self;
}

- closeApp: sender
{
  WinPostMsg ([sender window],WM_CLOSE,0L,0L);
  return self;
}

- windowDidResize: sender
{
  ListBox *nameListBox = [sender findFromID: IDD_PUSHBUTTON1];

  [nameListBox setSize: 0:0:[sender width]:[sender height]];
  return self;
}

@end
