# Makefile for Objective C classes for PM programming

include Makefile.preamble

all: plot.exe

ifeq (.depend,$(wildcard .depend))
include .depend
endif

OBJECTS = plot.o controller.o 

depend dep:
	$(CPP) -MM *.m > .depend

plot.exe:	$(OBJECTS) gnuplot.res
	$(CC) -o plot.exe -g $(OBJECTS) gnuplot.res \
		-lobjcpm -lobjc
	emxbind -ep plot.exe
	$(STRIP) plot.exe

clean:
	rm -rf $(OBJECTS) gnuplot.res plot.exe core *~
