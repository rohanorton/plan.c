CFLAGS=-Wall -g -pipe 
#CFLAGS=-pipe -O2

CC=gcc
RM=rm -f

BIN=../../bin/
PROG_FILES = $(BIN)/23_elliptical
LIB=./libs/
INC=./includes/

$(BIN)23_elliptical: elliptical.o $(LIB)libhfcal.a 
	gcc $< -L$(LIB) -I$(INC) -lhfcal -o $@

%.o: %.c 
	gcc -I$(INC) -c $< -o $@

$(LIB)libhfcal.a: hfcal.o
	ar -rcs $@ $<

