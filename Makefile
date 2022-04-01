CC = clang
LDFLAGS = `pkg-config --libs --cflags sdl2`

all:
	$(CC) -o test main.c $(LDFLAGS)

clean:
	rm test
