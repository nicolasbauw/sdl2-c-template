CC = clang
LDFLAGS = `pkg-config --libs sdl2`
INCFLAGS = `pkg-config --cflags sdl2`

all: main.o square.o
	$(CC) -o sdltest main.o square.o $(LDFLAGS)

main.o:
	$(CC) -c main.c $(INCFLAGS)

square.o:
	$(CC) -c square.c $(INCFLAGS)

clean:
	rm sdltest main.o square.o
