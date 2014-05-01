# Makefile for Objective C classes for PM programming

include Makefile.preamble

all: addresses.exe

ifeq (.depend,$(wildcard .depend))
include .depend
endif

OBJECTS = addresses.o controller.o 

depend dep:
	$(CPP) -MM *.m > .depend

addresses.exe:	$(OBJECTS) address.res
	$(CC) -o addresses.exe -g $(OBJECTS) address.res \
		-lobjcpm -lobjcdb -lobjc
	emxbind -ep addresses.exe
	$(STRIP) addresses.exe

clean:
	rm -rf $(OBJECTS) address.res addresses.exe core *~
