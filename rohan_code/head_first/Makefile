CFLAGS=-Wall -g -pipe 
#CFLAGS=-pipe -O2

CC=gcc
RM=rm -f

SOURCE_DIR=./src/
PROGRAM_DIR=./bin/
TEST_DIR=./test/

MSG_HIDER_DIR=$(SOURCE_DIR)/12_message_hider/

SOURCE_FILES = $(wildcard $(SOURCE_DIR)*.c)
PROGRAM_FILES = $(patsubst %.c,%,$(patsubst $(SOURCE_DIR)%,$(PROGRAM_DIR)%,$(SOURCE_FILES)))

.PHONY: all
all: $(PROGRAM_FILES) bin/12_message_hider

bin/12_message_hider: $(MSG_HIDER_DIR)/*
	$(CC) $(CFLAGS) $(LDFLAGS) $(MSG_HIDER_DIR)/message_hider.c $(MSG_HIDER_DIR)/encrypt.c  -o $@

$(PROGRAM_DIR)%: $(SOURCE_DIR)%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(PROGRAM_FILES)

.PHONY: test
test:
	@bash $(TEST_DIR)/*.sh
