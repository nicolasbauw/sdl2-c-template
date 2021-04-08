CC = clang
LDFLAGS = -I /opt/homebrew/Cellar/sdl2/*/include/SDL2 -L /opt/homebrew/Cellar/sdl2/*/lib -lSDL2

all:
	$(CC) -o test main.c $(LDFLAGS)

clean:
	rm test
