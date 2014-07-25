CFLAGS=-Wall -g -pipe 
#CFLAGS=-pipe -O2

CC=gcc
RM=rm -f
MAKE=make

SRC=./src/
BIN=./bin/

MSG_HIDER_DIR=$(SRC)12_message_hider/

SRC_FILES = $(wildcard $(SRC)*.c)
PROG_FILES = $(patsubst %.c,%,$(patsubst $(SRC)%,$(BIN)%,$(SRC_FILES)))

.PHONY: all
all: $(PROG_FILES) $(BIN)12_message_hider $(BIN)22_bank_vault 

$(BIN)12_message_hider: $(MSG_HIDER_DIR)*
	$(CC) $(CFLAGS) $(LDFLAGS) $(MSG_HIDER_DIR)message_hider.c $(MSG_HIDER_DIR)encrypt.c  -o $@

$(BIN)22_bank_vault:
	# running make from another directory
	$(MAKE) -C $(SRC_FILES)22_bank_vault

$(BIN)%: $(SRC)%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(PROG_FILES)
