BIN=../../bin/
PROG_FILES = $(BIN)/23_elliptical
LIB=./libs/
INC=./includes/

CFLAGS=-Wall -g -pipe 
#CFLAGS=-pipe -O2
LDFLAGS=-I$(INC) -L$(LIB) -fPIC

CC=gcc
RM=rm -f


$(BIN)23_elliptical: elliptical.o $(LIB)libhfcal.so 
	$(CC) $(CFLAGS) $(LDFLAGS)  $< -lhfcal -o $@
	@echo "=========================="
	@echo "If using linux, remember to run following command before attempting to run:"
	@echo '    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./src/23_elliptical/libs'
	@echo "=========================="

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(LIB)libhfcal.so: hfcal.o
	$(CC) -shared $< -o $@

