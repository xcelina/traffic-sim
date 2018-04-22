#include "SDL.h"
#include "sim/map.h"
#include "sim/crossing.h"
#include "sim/street.h"
#include "sim/car.h"
#include "gui.h"
#include "config.h"
#include <stdio.h>

int gui_render_crossing(WINDOW_HANDLE *handle, CROSSING *crossing);
int gui_render_street(WINDOW_HANDLE *handle, STREET *street);
int gui_render_car(WINDOW_HANDLE *handle, CAR *car);

int gui_render(WINDOW_HANDLE *handle) {
    SDL_SetRenderDrawColor(handle->renderer, COLOR_BACKGROUND);
    SDL_RenderClear(handle->renderer);

    /* ######################
       #   render streets   #
       ###################### */

    SDL_SetRenderDrawColor(handle->renderer, COLOR_STREETS);

    for (STREET **street = &(handle->map->street_list); *street != NULL; street = &((*street)->map_next)) {
        gui_render_street(handle, *street);
    }

    /* ########################
       #   render crossings   #
       ######################## */

    SDL_SetRenderDrawColor(handle->renderer, COLOR_CROSSINGS);

    for (CROSSING **crossing = &(handle->map->crossing_list); *crossing != NULL; crossing = &((*crossing)->map_next)) {
        gui_render_crossing(handle, *crossing);
    }

    /* ###################
       #   render cars   #
       ################### */

    SDL_SetRenderDrawColor(handle->renderer, COLOR_CARS);

    for (CAR **car = &(handle->map->car_list); *car != NULL; car = &((*car)->map_next)) {
        gui_render_car(handle, *car);
    }

    SDL_RenderPresent(handle->renderer);
}

int gui_render_crossing(WINDOW_HANDLE *handle, CROSSING *crossing) {
    int x, y;

    SDL_Rect rect = {
            (int)((crossing->position.x - handle->top_left.x) * handle->zoom) - CROSSING_RADIUS,
            (int)((crossing->position.y - handle->top_left.y) * handle->zoom) - CROSSING_RADIUS,
            2 * CROSSING_RADIUS,
            2 * CROSSING_RADIUS
        };

    SDL_RenderFillRect(handle->renderer, &rect);

    return 0;
}

int gui_render_street(WINDOW_HANDLE *handle, STREET *street) {
    int x1, y1, x2, y2;

    x1 = (int)((street->source->position.x - handle->top_left.x) * handle->zoom);
    y1 = (int)((street->source->position.y - handle->top_left.y) * handle->zoom);

    x2 = (int)((street->drain->position.x - handle->top_left.x) * handle->zoom);
    y2 = (int)((street->drain->position.y - handle->top_left.y) * handle->zoom);

    SDL_RenderDrawLine(handle->renderer, x1, y1, x2, y2);

    return 0;
}

int gui_render_car(WINDOW_HANDLE *handle, CAR *car) {
    
}