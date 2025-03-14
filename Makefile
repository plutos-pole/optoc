CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g -O0
SRC_DIR := src
OBJ_DIR := obj
BIN := optoc

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN)

debug: CFLAGS += -DDEBUG 
debug: $(BIN)            

.PHONY: clean