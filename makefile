CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_image
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
EXEC = bin/MemeStorm

all: dirs $(EXEC) clean

dirs:
	mkdir -p build bin

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/

mrproper:
	rm -rf build/* bin/*