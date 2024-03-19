CC = g++

OBJS = src/raylib/hello_inputs.cpp

COMPILER_FLAGS = -w -g

LINKER_FLAGS = -lGL
SDL_LINKER_FLAGS = -lSDL2 -lSDL2_image
RAY_LINKER_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

OBJ_NAME = main

main:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
ray:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(RAY_LINKER_FLAGS) -o $(OBJ_NAME)
sdl:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(SDL_LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	rm main