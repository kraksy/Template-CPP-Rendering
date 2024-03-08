CC = g++
OBJS = src/hello_image.cpp
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = cdc

main:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	rm cdc