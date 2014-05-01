#include <pm/pm.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>

main(int argc,char *argv[])
{
  StdApp      *application;
  StdWindow   *window;
  Window      *mle;
  FILE        *inputFile;
  struct stat  statbuffer;
  char        *contents;
  char        *title;

  /*
   * check for command line arguments and check given file (struct stat)
   */
  if (argc != 2) /* check for command line arguments, must be exactly one */
    exit (-1);

  if (stat (argv[1],&statbuffer) < 0) /* check file */
    exit (-1);

  /*
   * open file and read contents to buffer
   */
  inputFile = fopen (argv[1],"r"); /* open text file read-only */

  contents = (char *) malloc (statbuffer.st_size + 1); /* allocate buffer */
  fread (contents,statbuffer.st_size,1,inputFile); /* read contents of file */

  /*
   * create app instance and window, create MLE for text display
   */
  application = [[StdApp alloc] init]; /* initialize application object */
  window = [[MainWindow alloc] initWithId: 1000
                                andFlags: FCF_BORDER]; /* create main window */
  
  [window createObjects]; /* create child windows of main window */

  mle = [[MultiLineEntryField alloc] initWithId: 1001 
                                       andFlags: (WS_VISIBLE | MLS_READONLY |
						  MLS_HSCROLL | MLS_VSCROLL)
                                             in: window];
  [window insertChild: mle]; /* insert MLE into window */

  /*
   * calculate title of window and set it
   */
  title = (char *) malloc (11 + /* this is the length of "Textview: " + NULL */
			   strlen (argv[1])); /* allocate buffer for title */
  sprintf (title,"Textview: %s",argv[1]); /* fill title buffer */

  [window setTitle: title]; /* set window title */

  free (title); /* free title buffer */

  /*
   * show window, set MLE size and  display contents of file
   */
  [window makeKeyAndOrderFront: nil]; /* show window */
  [mle setSize: 0:0:[window width]:[window height]]; /* set MLE size */
  [mle setText: contents]; /* display contents of file */

  /*
   * run application
   */
  [application run];

  /*
   * free all resources
   */
  free (contents); /* free contents buffer */
  fclose (inputFile); /* close file */

  [application free]; /* free application */
  [window free]; /* free window */
}
