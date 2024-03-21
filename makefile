CC = g++

OBJ = src/raylib/game_ray.cpp
OBJS = $(wildcard *.cpp)

COMPILER_FLAGS = -w -g

LINKER_FLAGS = -lGL
SDL_LINKER_FLAGS = -lSDL2 -lSDL2_image
RAY_LINKER_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SFML_LINKER_FLAGS = lsfml-graphics -lsfml-window -lsfml-system

OBJ_NAME = main

all: 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(RAY_LINKER_FLAGS) $(SDL_LINKER_FLAGS) $(SFML_LINKER_FLAGS) -o $(OBJ_NAME) 
main:
	$(CC) $(OBJ) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
ray:
	$(CC) $(OBJ) $(COMPILER_FLAGS) $(RAY_LINKER_FLAGS) -o $(OBJ_NAME)
sdl:
	$(CC) $(OBJ) $(COMPILER_FLAGS) $(SDL_LINKER_FLAGS) -o $(OBJ_NAME)
sfml:
	$(CC) $(OBJ) $(COMPILER_FLAGS) $(SFML_LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	rm main