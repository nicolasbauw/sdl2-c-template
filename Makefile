CC = clang
LDFLAGS = -I /opt/homebrew/Cellar/sdl2/2.0.14_1/include/SDL2 -L /opt/homebrew/Cellar/sdl2/2.0.14_1/lib -lSDL2

all:
	$(CC) -o test main.c $(LDFLAGS)

clean:
	rm test
