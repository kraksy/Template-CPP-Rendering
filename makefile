CC = g++
OBJS = src/cdc.cpp
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2
OBJ_NAME = cdc

main:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	rm cdc