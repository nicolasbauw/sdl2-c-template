#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

struct WRenderP {
    SDL_Window* window;
    SDL_Renderer* renderer;
};

struct WRenderP init();
void quit(SDL_Window *window);
void loop();

int main(int argc, char* argv[]) {

    struct WRenderP app_sdl_pointers;                    // Declare a pointer
    app_sdl_pointers = init();

    if ((app_sdl_pointers.window) == NULL) {
        return EXIT_FAILURE;
    };
    
    loop();

    quit(app_sdl_pointers.window);
    return EXIT_SUCCESS;
}

struct WRenderP init() {
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    struct WRenderP p;

    // Create an application window with the following settings:
    p.window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_SHOWN                   // flags - see below
    );

    return p;
}

void quit(SDL_Window* window) {
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