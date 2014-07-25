CFLAGS=-Wall -g -pipe 
#CFLAGS=-pipe -O2

CC=gcc
RM=rm -f

SOURCE_DIR=./src/
PROGRAM_DIR=./bin/
TEST_DIR=./test/

MSG_HIDER_DIR=$(SOURCE_DIR)/12_message_hider/
BANK_VAULT_SRC=$(SOURCE_DIR)/22_bank_vault/

SOURCE_FILES = $(wildcard $(SOURCE_DIR)*.c)
PROGRAM_FILES = $(patsubst %.c,%,$(patsubst $(SOURCE_DIR)%,$(PROGRAM_DIR)%,$(SOURCE_FILES)))

.PHONY: all
all: $(PROGRAM_FILES) $(PROGRAM_DIR)12_message_hider $(PROGRAM_DIR)22_bank_vault

$(PROGRAM_DIR)12_message_hider: $(MSG_HIDER_DIR)/*
	$(CC) $(CFLAGS) $(LDFLAGS) $(MSG_HIDER_DIR)/message_hider.c $(MSG_HIDER_DIR)/encrypt.c  -o $@


$(BANK_VAULT_SRC)encrypt.o: $(BANK_VAULT_SRC)encrypt.c 
	gcc -c $< -o $@

$(BANK_VAULT_SRC)checksum.o: $(BANK_VAULT_SRC)checksum.c 
	gcc -c $< -o $@

$(BANK_VAULT_SRC)libhfsecurity.a: $(BANK_VAULT_SRC)encrypt.o $(BANK_VAULT_SRC)checksum.o
	ar -rcs $@ $(BANK_VAULT_SRC)encrypt.o $(BANK_VAULT_SRC)checksum.o

$(PROGRAM_DIR)22_bank_vault: $(BANK_VAULT_SRC)bank_vault.c $(BANK_VAULT_SRC)libhfsecurity.a
	gcc $< -I $(BANK_VAULT_SRC) -L $(BANK_VAULT_SRC) -lhfsecurity -o $@


$(PROGRAM_DIR)%: $(SOURCE_DIR)%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(PROGRAM_FILES)

.PHONY: test
test:
	@bash $(TEST_DIR)/*.sh
