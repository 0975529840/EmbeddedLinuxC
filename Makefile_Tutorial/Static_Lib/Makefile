CC := gcc
CFLAGS := -I./inc
OBJ_DIR := obj
SRC_DIR := src
OBJ_FILES := obj/main.o obj/hello.o
INC_FILES := inc/hello.h
BIN_DIR := bin
OUTPUT_DIR := $(BIN_DIR) $(OBJ_DIR)
OUTPUT_NAME := main
build: $(OBJ_FILES) | $(BIN_DIR)
	$(CC) -o $(BIN_DIR)/$(OUTPUT_NAME) $(OBJ_FILES) $(CFLAGS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES) | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJ_DIR)/%.o: %.c $(INC_FILES) | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)
clean:
	rm -rf obj bin
dir_create: 
	@for dir in $(OUTPUT_DIR); do\
		mkdir -p $$dir; \
	done
$(BIN_DIR): ; @mkdir -p $@
$(OBJ_DIR): ; @mkdir -p $@
