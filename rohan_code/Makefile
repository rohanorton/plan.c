CFLAGS=-Wall -g -pipe 
#CFLAGS=-pipe -O2

CC=gcc
RM=rm -f

SOURCE_DIR=./src/
PROGRAM_DIR=./bin/
TEST_DIR=./test/

SOURCE_FILES = $(wildcard $(SOURCE_DIR)*.c)
PROGRAM_FILES = $(patsubst %.c,%,$(patsubst $(SOURCE_DIR)%,$(PROGRAM_DIR)%,$(SOURCE_FILES)))

.PHONY: all
all: $(PROGRAM_FILES)

$(PROGRAM_DIR)%: $(SOURCE_DIR)%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(PROGRAM_FILES)

.PHONY: test
test:
	@bash $(TEST_DIR)/*.sh
