CC = g++
OBJS = src/hello_graphics.cpp
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2
OBJ_NAME = main

main:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	rm main