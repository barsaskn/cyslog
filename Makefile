CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 
INCLUDE_DIR = include

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o,$(SRCS))
EXEC = $(BIN_DIR)/cyslog

TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o,$(TEST_SRCS))
TEST_EXEC = $(BIN_DIR)/test_cyslog
TEST_INCLUDE_DIR = test

.PHONY: all clean test

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $^

test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS) $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(TEST_INCLUDE_DIR) -c -o $@ $^

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
