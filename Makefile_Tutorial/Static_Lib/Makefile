#Makefile for static lib
CC := gcc
CFLAGS := -I./inc
OBJ_DIR := obj
SRC_DIR := src
OBJ_FILES := obj/main.o obj/hello.o
INC_FILES := inc/hello.h
BIN_DIR := bin
STATIC_LIB_DIR:= bin/static
OUTPUT_DIR := $(BIN_DIR) $(OBJ_DIR) $(STATIC_LIB_DIR)
OUTPUT_NAME := main

build: $(INC_FILES) | $(OUTPUT_DIR)
	$(CC) -c main.c -o obj/main.o $(CFLAGS)
	$(CC) -c src/hello.c -o obj/hello.o $(CFLAGS)
clean:
	rm -rf obj bin
dir_create: 
	@for dir in $(OUTPUT_DIR); do\
		mkdir -p $$dir; \
	done
static_lib: | $(STATIC_LIB_DIR)
	ar rcs bin/static/libhello.a obj/hello.o
all: obj/main.o
	gcc obj/main.o -L$(STATIC_LIB_DIR) -lhello -o bin/statically-linked
$(STATIC_LIB_DIR): ; @mkdir -p $@
$(BIN_DIR): ; @mkdir -p $@
$(OBJ_DIR): ; @mkdir -p $@
