#include "gui.h"
#include "SDL.h"
#include <stdio.h>

#define MIN(x, y) (x < y ? x : y)

WINDOW_HANDLE *gui_open_window(MAP *map) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    WINDOW_HANDLE *handle;
    
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "traffic-sim",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        return NULL;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        return NULL;
    }

    handle = (WINDOW_HANDLE*) malloc(sizeof(WINDOW_HANDLE));

    if (handle == NULL) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }

    handle->window = window;
    handle->renderer = renderer;
    handle->map = map;

    handle->zoom = (float)MIN(WINDOW_WIDTH, WINDOW_HEIGHT);
    handle->top_left.x = 0.0;
    handle->top_left.y = 0.0;

    return handle;
}

void gui_close_window(WINDOW_HANDLE *handle) {
    SDL_DestroyWindow(handle->window);
    SDL_Quit();
    free(handle);
}