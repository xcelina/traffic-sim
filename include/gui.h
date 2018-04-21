#ifndef __GUI_H__
#define __GUI_H__

#include "SDL.h"
#include "map/map.h"

typedef struct WINDOW_HANDLE {
    SDL_Window *window;
    SDL_Renderer *renderer;
    MAP *map;
} WINDOW_HANDLE;

WINDOW_HANDLE *gui_open_window(MAP *map);
void gui_close_window(WINDOW_HANDLE *handle);

int gui_render(WINDOW_HANDLE *handle);

#endif