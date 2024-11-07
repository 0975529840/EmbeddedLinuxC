#Makefile for static lib
CC := gcc
CFLAGS := -I./inc
OBJ_DIR := obj
SRC_DIR := src
OBJ_FILES := obj/main.o obj/hello.o
INC_FILES := inc/hello.h
BIN_DIR := bin
STATIC_LIB_DIR:= bin/static
SHARED_LIB_DIR:= bin/shared
OUTPUT_DIR := $(BIN_DIR) $(OBJ_DIR) $(STATIC_LIB_DIR) $(SHARED_LIB_DIR)
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
dynamic_lib: | $(STATIC_LIB_DIR)
	gcc -shared obj/hello.o -o bin/shared/libhello.so
all: obj/main.o
	gcc obj/main.o -L$(STATIC_LIB_DIR) -lhello -o bin/statically-linked
# Step 1
# 	Build executive file With share library
# gcc obj/main.o -L$(SHARED_LIB_DIR) -lhello -o bin/user-shared-library
# set-up LD_LIBRARY_PATH in /usr/lib
# LD_LIBRARY_PATH=$(pwd)/bin/shared bin/use-shared-library
# Step 2
#
#   Moving the shared object to a standard location
#
# sudo mv bin/shared/libtq84.so /usr/lib
# sudo chmod 755 /usr/lib/libtq84.so
$(SHARED_LIB_DIR): ; @mkdir -p $@
$(STATIC_LIB_DIR): ; @mkdir -p $@
$(BIN_DIR): ; @mkdir -p $@
$(OBJ_DIR): ; @mkdir -p $@
