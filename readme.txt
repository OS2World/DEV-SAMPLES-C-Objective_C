===============================================================================
           Objective C OS/2 PM and database library - README.TXT
===============================================================================

1. Introduction:
===============

This package contains an Objective C PM class library and an Objective C
database library.

For a description of the PM and database class libraries print the documentation.
This can be found in \usr\doc. 

Use a Postscript printer or a Postscript Interpreter program (Ghostscript
will do fine) to print it.

All documents were prepared for twosided printing. You can find one Postscript
File for the even and one for the odd pages for each document. In all files,
the pages are in ascending order.

The files found there are:

	install.ps.odd		odd pages of the installation manual
	install.ps.even		even pages of the installation manual

	reference.ps.odd	odd pages of the reference manual
	reference.ps.even	even pages of the reference manual

	tools.ps.odd		odd pages of the library tools manual
	tools.ps.even		even pages of the library tools manual

	tutorial.ps.odd		odd pages of the tutorial
	tutorial.ps.even	even pages of the tutorial

All documents were formatted for A4 paper.

Changes to the class library and some information on the Interface Builder can
be found in NEWS.TXT.


2. List of files:
================

The main compressed archive file contains the following files:

	*	README.TXT	This file
        *       REGISTER.TXT    Registration form
	*	NEWS.TXT	Changes of the library from version 0.6 to
				version 0.7. Short documentation of the
				Interface Builder program!
	*	DOC.ZIP		Documentation for the PM and database class
				libraries in Postscript form. Use a Postscript
				Printer or a Postscript Interpreter program
				(e.g. Ghostscript) to print. Odd and even pages
				are found in different files. These manuals
				haven't changed since version 0.6. If you
				already printed them, just read NEWS.TXT!
	*	PM.ZIP		Compressed archive file containing all
				necessary include files for the PM class
				library and the library itself.
	*	DB.ZIP		Compressed archive file containing all	
				necessary include files for the DB class
				library and the library itself.
	*	HEADER.ZIP	Patched versions of 'os2.h' and 'os2emx.h'
				to be used with the libraries.
	*	SAMPLES.ZIP	Sample programs demonstrating some of the
				classes of the PM and database libraries.
	*	IB.ZIP		The Interface Builder program.
	*	BOOK.ZIP	The documentation in INF form. Don't be too
				excited, no tables, no figures, no index!
				The conversion to INF-format was done
				automatically, the translater is not this
				flexible at the moment! These files contain
				the SAME text as the postscript files!!!
				Newer information can be found in NEWS.TXT


3. Installation:
===============

Change the current working directory to the root directory of the HPFS drive
you want to install the libraries to and type:

		unzip doc
		unzip pm
		unzip db
		unzip header
		unzip samples
		unzip ib
		unzip book

This will create some directories and copy the necessary files into them.
Add 'c:/usr/include' to your environment variable 'OBJC_INCLUDE_PATH'
in your CONFIG.SYS, if you installed the library to drive C, or replace
'c:' with the drive label you installed the library to.

To use the resource compiler RC.EXE, just set the environment variable
INCLUDE to somewhere, where os2.h can be found, e.g. add
	SET INCLUDE=c:\emx\include
to your config.sys file.

Add \usr\lib\book to your BOOSHELF= statement in your config.sys file!

The samples have been installed to '\usr\samples'. See 'readme.txt' in
'\usr\samples' for a description of the sample programs.

The documentation files are installed in '\usr\doc'. Deleting them is 
recommended after printing. These file are quite large.

The binaries go into \usr\bin\PM
Read the installation manual for more information.

After uncompressing all files, just change to the drive, the packages were
installed to and start the installation script "install.cmd". This will create
a folder on your desktop and put the program objects for the Interface Builder
and the Database Creator into it. Sorry, but no time for drawing some fancy
icons for these programs!

The manuals can be found also in \usr\lib\book in IPF form. At the moment,
these are "raw" conversions of the original sources to the postscript files.
Tables, references, figures and footnotes are NOT included, but I think,
especially the reference manual can be quite helpful!

Program objects for viewing the documentation are created by install.cmd


4. Distribution:
===============

This program is Shareware. Feel free to distribute the whole and unmodified
package to anyone. You are not allowed to change any of the files part of
the package before distributing, you only are allowed to distribute the
package as a whole, including all files you received with it.

You are allowed to charge a small amount of money for the physical act of
transferring the library. This amount of money must not exceed twice the cost
of the storage medium. So, if you for example use floppy disks at a price of
10 ATS each, you are allowed to charge at most 20 ATS for copying the disk.
That makes a total of 30 ATS (including packaging).

If you don't like these distribution restrictions, don't distribute the
program.

It's a shame to see some vendors "selling" Public Domain or Shareware programs
at a price of 80 ATS per disk (3,5'' HD disks are sold at a price between
5 and 10 ATS). Especially those vendors are not allowed to distribute the
library package at their normal copying costs. So, change your pricing policy,
or just don't distribute this library package.

If you're not sure, whether you are allowed to distribute the package, contact
me at the address shown below. Any vendors who want to distribute registered
versions of the library should do the same.


5. Licensing:
============

This libraries are distributed as Shareware. To become a registered user
fill in the registration form at the end of this file and send it to me (the
address can be found below).

After registration you are automatically registered for all following versions
of the library until the major version number increases. That means by
registering this version of the library together with the PM class library
(PM library: version 0.7; DB library: version 0.5) you are automatically
registered for all future versions of the PM and DB libraries including version
1.0.

Starting at version 1.1 of the PM or DB library you have to register newly at a
special update price.

Support the Shareware distribution concept and register if you like this
library and want to use it in your own applications. Future Shareware
releases of this library depend heavily on the will of users to register.
So, if no one registers this library, surely no further effort will be made
in adding functionality to the libraries.

As a registered user you are allowed to write applications using these two
libraries and distribute them at whatever price you think of.

Before registering you are allowed to test this library package as much as
you like for a trial period of 30 days after first installing this package.
You are not allowed to sell any of the applications written using this
package if you have not registered it.

The Interface Builder program is limited to at most two open interface files
at the same time and each file can contain at most two dialog windows!

If you continue using the library package after the trial period of 30 days
and don't register, that's an act of software-piracy. May your bad conscious
haunt you till the end of your days ;-)

Think of the cheap pricing for this powerful library package and register.
Future versions will include some tools to make life easier for programmers
(just look at the NEXTSTEP development environment. Some kind of Project
Builder would look fine for OS/2 systems).


6. Warranty:
===========

Well, as you might have thought, there's ABSOLUTELY NO WARRANTY for this
library package.


7. Pricing:
==========

The registration fee for the OS/2 PM class library together with the Database
library is 400ATS (400 Austrian Schillings), that's about 40US$, per copy
for individuals or 500ATS for companies. Don't forget to check with your bank,
how much you should pay, so that I will get the whole registration fee as
mentioned above.

Don't forget to fill in the registration form and send it to me (address
below).

-------------------------------------------------------------------------------

Send the money directly to my local bank account:

	NAME OF BANK: 		RAIFFEISENBANK KREMS
	ID Nr. OF BANK:		32397
	ACCOUNT NR.:		12.195

or - if outside Austria, use any alternatives, you can think of for me to
receive the registration fee (e.g. Eurocheque).

For information about 10+ licenses of this libraries feel free to contact
me via Internet E-Mail (baier@ci.tuwien.ac.at) or via Snail Mail at:

Thomas Baier
Ufergasse 68
A-3500 Krems
Austria

Internet: baier@ci.tuwien.ac.at


8. Registration Form:
====================

After paying the registration fee, fill in the following registration form
and send it to me to the following address:

	Thomas Baier
	Ufergasse 68
	A-3500 Krems
	AUSTRIA

--------------------------------- CUT HERE ---------------------------------

Registration form for OS/2 PM and database libraries

PM class library version is 		0.6
Database class library version is	0.4

The registration fee for the OS/2 PM class library together with the Database
library is 250ATS (250 Austrian Schillings), that's about 25US$, per copy
for individuals or 500ATS for companies.


	Pricing for individuals:

		____ copies for 250 ATS each makes a total of _____ ATS.


	Pricing for companies:

		____ copies for 500 ATS each makes a total of _____ ATS.


	The total sum of _____ ATS has been paid to

					THOMAS BAIER
		NAME OF BANK: 		RAIFFEISENBANK KREMS
		ID Nr. OF BANK:		32397
		ACCOUNT NR.:		12.195


	Registration information:


		NAME:		______________________________


		INTERNET-EMAIL: ______________________________


		COMPANY:	______________________________


		ADDRESS:	______________________________


				______________________________


				______________________________


				______________________________


		SIGNATURE:	______________________________



------------------------- END OF REGISTRATION FORM -------------------------
