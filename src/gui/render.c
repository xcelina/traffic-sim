#include "SDL.h"
#include "map/map.h"
#include "map/crossing.h"
#include "map/street.h"
#include "map/car.h"
#include "gui.h"
#include "config.h"
#include <stdio.h>

int gui_render_crossing(SDL_Renderer *renderer, CROSSING *crossing);
int gui_render_street(SDL_Renderer *renderer, STREET *street);
int gui_render_car(SDL_Renderer *renderer, CAR *car);

int gui_render(WINDOW_HANDLE *handle) {
    SDL_SetRenderDrawColor(handle->renderer, COLOR_BACKGROUND);
    SDL_RenderClear(handle->renderer);

    /* ######################
       #   render streets   #
       ###################### */

    SDL_SetRenderDrawColor(handle->renderer, COLOR_STREETS);

    for (STREET **street = &(handle->map->street_list); *street != NULL; street = &((*street)->map_next)) {
        gui_render_street(handle->renderer, *street);
    }

    /* ########################
       #   render crossings   #
       ######################## */

    SDL_SetRenderDrawColor(handle->renderer, COLOR_CROSSINGS);

    for (CROSSING **crossing = &(handle->map->crossing_list); *crossing != NULL; crossing = &((*crossing)->map_next)) {
        gui_render_crossing(handle->renderer, *crossing);
    }

    /* ###################
       #   render cars   #
       ################### */

    SDL_SetRenderDrawColor(handle->renderer, COLOR_CARS);

    for (CAR **car = &(handle->map->car_list); *car != NULL; car = &((*car)->map_next)) {
        gui_render_car(handle->renderer, *car);
    }

    SDL_RenderPresent(handle->renderer);
}

int gui_render_crossing(SDL_Renderer *renderer, CROSSING *crossing) {
    int x, y;

    SDL_Rect rect = {
            (int)(crossing->position.x * (float)WINDOW_WIDTH) - CROSSING_RADIUS,
            (int)(crossing->position.y * (float)WINDOW_HEIGHT) - CROSSING_RADIUS,
            2 * CROSSING_RADIUS,
            2 * CROSSING_RADIUS
        };

    SDL_RenderFillRect(renderer, &rect);

    return 0;
}

int gui_render_street(SDL_Renderer *renderer, STREET *street) {
    int x1, y1, x2, y2;

    x1 = (int)(street->source->position.x * (float)WINDOW_WIDTH);
    y1 = (int)(street->source->position.y * (float)WINDOW_HEIGHT);

    x2 = (int)(street->drain->position.x * (float)WINDOW_WIDTH);
    y2 = (int)(street->drain->position.y * (float)WINDOW_HEIGHT);

    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

    return 0;
}

int gui_render_car(SDL_Renderer *renderer, CAR *car) {
    
}