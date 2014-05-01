#include <pm/pm.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>

void readAndDisplayFile (char *fileName);

@interface Controller : Object
{
}

- windowDidResize: sender;
- loadFile: sender;

@end

char        *contents;
StdWindow   *window;
Window      *mle;

@implementation Controller

- windowDidResize: sender
{
  [[sender findFromID: 1001] setSize: 0:0:[sender width]:[sender height]];
  return self;
}

- loadFile: sender
{
  FileDlg *fileDlg = [[FileDlg alloc] initForOpen: "Open File..."
		      withFilter: "*.*"];
  if ([fileDlg runModalFor: window] == DID_OK)
    readAndDisplayFile ([fileDlg fileName]);

  [fileDlg free];
  return self;
}

@end

void readAndDisplayFile (char *fileName)
{
  char        *title;
  FILE        *inputFile;
  struct stat  statbuffer;

  if (stat (fileName,&statbuffer) < 0) { /* check file */
    if (contents != NULL) {
      free (contents);
      contents = NULL;
    }

    [mle setText: ""];
    [window setTitle: "Textview: no file loaded"];
    return;
  }

  /*
   * open file and read contents to buffer
   */
  inputFile = fopen (fileName,"r"); /* open text file read-only */
      
  contents = (char *) malloc (statbuffer.st_size + 1); /* allocate buffer */
  fread (contents,statbuffer.st_size,1,inputFile); /* read contents of file */
      
  /*
   * calculate title of window and set it
   */
  title = (char *) malloc (11 + /* this is the length of "Textview: " + 
				   NULL */
			   strlen (fileName)); /* allocate buffer 
						 for title */
  sprintf (title,"Textview: %s",fileName); /* fill title buffer */
  [mle setText: contents]; /* display contents of file */
  [window setTitle: title];
  free (title);
  fclose (inputFile); /* close file */
  
}

main(int argc,char *argv[])
{
  StdApp      *application;
  Controller  *controller;

  /*
   * create app instance and window, create MLE for text display
   */
  application = [[StdApp alloc] init]; /* initialize application object */
  window = [[MainWindow alloc] initWithId: 1000
	  andFlags: FCF_SIZEBORDER|FCF_MENU]; /* create main window */
  controller = [[Controller alloc] init];
  
  [window createObjects]; /* create child windows of main window */
  [window setDelegate: controller];

  [window bindCommand: 3001 withObject: controller 
             selector: @selector (loadFile:)];
  mle = [[MultiLineEntryField alloc] initWithId: 1001 
       andFlags: (WS_VISIBLE | MLS_READONLY |
		  MLS_HSCROLL | MLS_VSCROLL)
       in: window];
  [window insertChild: mle]; /* insert MLE into window */

  contents = NULL;

  /*
   * check for command line arguments and check given file (struct stat)
   */
  if (argc == 2) /* check for command line arguments, must be exactly one */
    readAndDisplayFile (argv[1]);
  else
    [window setTitle: "Textview: no file loaded"];
  
  /*
   * show window
   */
  [window makeKeyAndOrderFront: nil]; /* show window */

  /*
   * run application
   */
  [application run];

  /*
   * free all resources
   */
  if (contents != NULL)
    free (contents); /* free contents buffer */

  [application free]; /* free application */
  [window free]; /* free window */
  [controller free]; /* free controller */
}
