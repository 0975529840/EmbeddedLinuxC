CC := gcc
CFLAGS := -I.
OBJ_FILES := main.o hello.o
INC_FILES := hello.h
hellomake: $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES) $(CFLAGS)
%.o: %.c $(INC_FILES)
	$(CC) -c $< -o $@ $(CFLAGS)
clean:
	rm -rf *.o hellomake
