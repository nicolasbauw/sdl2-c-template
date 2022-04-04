#include "SDL.h"

struct WRenderP {
    SDL_Window* window;
    SDL_Renderer* renderer;
};
void do_square(struct WRenderP p);

void do_square(struct WRenderP p) {
    SDL_Rect r;
    r.x = 0;
    r.y = 0;
    r.w = 32;
    r.h = 32;

    SDL_SetRenderDrawColor( p.renderer, 255, 255, 255, 255 );
    SDL_RenderFillRect( p.renderer, &r );
}