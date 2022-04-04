#include "SDL.h"

struct WRenderP {
    SDL_Window* window;
    SDL_Renderer* renderer;
};

struct WRenderP init();
void quit(struct WRenderP);
void loop();
void do_square(struct WRenderP p);

int main(int argc, char* argv[]) {

    struct WRenderP app_sdl_pointers;                    // Declare a pointer
    app_sdl_pointers = init();

    if ((app_sdl_pointers.window) == NULL) {
        return EXIT_FAILURE;
    };
    
    loop(app_sdl_pointers);

    quit(app_sdl_pointers);
    return EXIT_SUCCESS;
}

struct WRenderP init() {
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    struct WRenderP p;

    // Create an application window with the following settings:
    SDL_CreateWindowAndRenderer(     
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_SHOWN|SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC,
        &p.window,
        &p.renderer
    );
    SDL_SetWindowTitle(p.window, "SDL2 C Template");

    return p;
}

void quit(struct WRenderP p) {
    // Close and destroy the window
    SDL_DestroyRenderer(p.renderer);
    SDL_DestroyWindow(p.window);

    // Clean up
    SDL_Quit();
}

void loop(struct WRenderP p) {
    // The window is open: could enter program loop here
    SDL_Event e;
    int quit = 0;
    while (!quit){
        SDL_SetRenderDrawColor( p.renderer, 0, 0, 0, 255 );
        SDL_RenderClear( p.renderer );
        do_square(p);
        SDL_RenderPresent(p.renderer);
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