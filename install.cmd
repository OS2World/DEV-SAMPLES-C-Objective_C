/*
 * PM & DB lib installation script
 */

call rxfuncadd sysloadfuncs, rexxutil, sysloadfuncs
call sysloadfuncs

call SysCls
say 'Objective C PM & DB Library - Installation'
say '------------------------------------------'
say ''
say 'Creating folder object and program objects...'
say ''

rc = SysCreateObject('WPFolder','Objective C Dev','<WP_DESKTOP>','OBJECTID=<OBJC_PROGRAM_FOLDER>;')

if (SysCreateObject('WPProgram','Interface Builder','<OBJC_PROGRAM_FOLDER>','MINIMIZED=NO;PROGTYPE=PM;EXENAME='filespec("drive",directory())'\usr\bin\PM\ib.exe;OBJECTID=<OBJC_IB_PROGRAM_OBJECT>;') = 0) THEN
  rc = SysSetObjectData('<OBJC_IB_PROGRAM_OBJECT>','MINIMIZED=NO;PROGTYPE=PM;EXENAME='filespec("drive",directory())'\usr\bin\PM\ib.exe;')

if (SysCreateObject('WPProgram','DB Creator','<OBJC_PROGRAM_FOLDER>','MINIMIZED=NO;PROGTYPE=PM;EXENAME='filespec("drive",directory())'\usr\bin\PM\dbbuild.exe;OBJECTID=<OBJC_DBBUILD_PROGRAM_OBJECT>;') = 0) THEN
  rc = SysSetObjectData('<OBJC_DBBUILD_PROGRAM_OBJECT>','MINIMIZED=NO;PROGTYPE=PM;EXENAME='filespec("drive",directory())'\usr\bin\PM\dbbuild.exe;')

if (SysCreateObject('WPProgram','Class Reference','<OBJC_PROGRAM_FOLDER>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;OBJECTID=<OBJC_REFERENCE_INFO>;PARAMETERS='filespec("drive",directory())'\usr\lib\book\referenc.inf;')) THEN
  rc = SysSetObjectData('<OBJC_REFERENCE_INFO>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;PARAMETERS='filespec("drive",directory())'\usr\lib\book\referenc.inf;')

if (SysCreateObject('WPProgram','Tutorial','<OBJC_PROGRAM_FOLDER>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;OBJECTID=<OBJC_TUTORIAL_INFO>;PARAMETERS='filespec("drive",directory())'\usr\lib\book\tutorial.inf;')) THEN
  rc = SysSetObjectData('<OBJC_TUTORIAL_INFO>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;PARAMETERS='filespec("drive",directory())'\usr\lib\book\tutorial.inf;')

if (SysCreateObject('WPProgram','Installation','<OBJC_PROGRAM_FOLDER>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;OBJECTID=<OBJC_INSTALL_INFO>;PARAMETERS='filespec("drive",directory())'\usr\lib\book\install.inf;')) THEN
  rc = SysSetObjectData('<OBJC_INSTALL_INFO>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;PARAMETERS='filespec("drive",directory())'\usr\lib\book\install.inf;')

if (SysCreateObject('WPProgram','Tools Reference','<OBJC_PROGRAM_FOLDER>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;OBJECTID=<OBJC_TOOLS_INFO>;PARAMETERS='filespec("drive",directory())'\usr\lib\book\tools.inf;')) THEN
  rc = SysSetObjectData('<OBJC_TOOLS_INFO>','MINIMIZED=NO;PROGTYPE=PM;EXENAME=view.exe;PARAMETERS='filespec("drive",directory())'\usr\lib\book\tools.inf;')

say 'A new folder "Objective C Dev" was created on your desktop.'
say 'The program objects for the Interface Builder and the Database Creator'
say 'program can be found there!'
Exit
