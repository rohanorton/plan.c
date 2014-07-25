CFLAGS=-Wall -g -pipe 
#CFLAGS=-pipe -O2

CC=gcc
RM=rm -f

BIN=../../bin/
PROG_FILES = $(BIN)/22_bank_vault

$(BIN)22_bank_vault: bank_vault.c libhfsecurity.a
	gcc $< -I .  -L . -lhfsecurity -o $@

encrypt.o: encrypt.c 
	gcc -c $< -o $@

checksum.o: checksum.c 
	gcc -c $< -o $@

libhfsecurity.a: encrypt.o checksum.o
	ar -rcs $@ encrypt.o checksum.o


