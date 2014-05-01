#ifndef _PRINTER_H_
#define _PRINTER_H_

#define INCL_SPLDOSPRINT
#ifndef _PRESENTATIONSPACE_H_
#include <pm/presentationspace.h>
#endif

#ifndef _STDAPP_H_
#include <pm/stdapp.h>
#endif

#ifndef _STDDIALOG_H_
#include <pm/stddialog.h>
#endif

@interface Printer : PresentationSpace
{
  StdApp      *application;
  id           setupDialog;

  HDC          printerDeviceContext;
  PRQINFO3    *queueInformation;
  ULONG        defaultPrinterIndex;
  ULONG        numberOfPrintingQueues;
  HCINFO       formInformation;
  DEVOPENSTRUC deviceOpenStructure;
}

- initForApp: (StdApp *) anApp;
- free;

- beginSpool: (char *) spoolTitle appTitle: (char *) appTitle;
- endSpool;
- newPage;

- printerSetup: sender;

- setSetupDialog: aSetupDialog;
- setupDialog;
- jobProperties: sender;
- setDefault;

// form definition
- (LONG) widthInPels;
- (LONG) widthInMm;
- (LONG) heightInPels;
- (LONG) heightInMm;

@end

#endif
