#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

int init(SDL_Window *window);
void quit(SDL_Window *window);
void loop();

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer

    if (init(window) == -1) {
        return EXIT_FAILURE;
    };
    
    loop();

    quit(window);
    return EXIT_SUCCESS;
}

int init(SDL_Window *window) {
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_SHOWN                   // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void quit(SDL_Window *window) {
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}

void loop() {
    // The window is open: could enter program loop here
    SDL_Event e;
    int quit = 0;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = 1;
            }
            if (e.type == SDL_KEYDOWN){
                quit = 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = 1;
            }
        }
    }
}