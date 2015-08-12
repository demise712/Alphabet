# Make file for Lab Exercise 4
# ORIGINALLY WRITTEN BY: Michael Main (main@colorado.edu), Jan 11, 1997
# MODIFIED BY: Jim Rogers, Jan/2001, Jan/2010
#
# This makefile is used to regenerate files for the testtank program:
#   make tank.o   --  Regenerates tank.o by compiling
#   make testtank.o   --  Regenerates testtank.o by compiling
#   make testtank --  Regenerates the executable testtank file by compiling
#   make              --  Same as "make testtank"
#
# Two special targets may also be used with this makefile:
#   make all          --  Regenerates all files listed above
#   make clean        --  Erases all expendable files
#   make distclean    --  Erases all expendables and executables
#
# All compilations occur with -Wall and -ggdb.


CPPFLAGS = -Wall -ggdb

EXPENDABLES = testtank.o tank.o
EXECUTABLES = testtank

testtank: testtank.o tank.o
	g++ $(CPPFLAGS) tank.o testtank.o -o testtank

tank.o: tank.h tank.cpp
	g++  $(CPPFLAGS) -c tank.cpp

testtank.o: tank.h testtank.cpp
	g++ $(CPPFLAGS) -Wall -ggdb -c testtank.cpp

clean:
	rm -f $(EXPENDABLES)

distclean:
	rm -f $(EXPENDABLES) $(EXECUTABLES)

all:
	rm -f $(EXPENDABLES) $(EXECUTABLES)
	@make $(EXECUTABLES)


