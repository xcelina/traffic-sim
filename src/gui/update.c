#include "SDL.h"
#include "gui.h"
#include "config.h"

float ofx, ofy;

int gui_update(WINDOW_HANDLE *handle) {
    int x, y;
    float fx, fy;
    float rx, ry;
    uint32_t mouse_state;
    SDL_Event event;
    float delta_zoom = 1.0;
    
    SDL_PumpEvents();
    mouse_state = SDL_GetMouseState(&x, &y);
    fx = (float)x / handle->zoom;
    fy = (float)y / handle->zoom;
    rx = handle->top_left.x + fx;
    ry = handle->top_left.y + fy;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEWHEEL) {
            delta_zoom = MOUSEWHEEL_ZOOM_SPEED;
            delta_zoom = (event.wheel.y > 0) ? delta_zoom : 1 / delta_zoom;
            delta_zoom = (event.wheel.direction == SDL_MOUSEWHEEL_NORMAL) ? delta_zoom : 1 / delta_zoom;
        } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
            return 0;
        }
    }

    /* ############
       #   drag   #
       ############ */

    if (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        handle->top_left.x += ofx - fx;
        handle->top_left.y += ofy - fy;
    }

    /* ############
       #   zoom   #
       ############ */
    
    if (delta_zoom != 1.0) {
        handle->top_left.x -= fx - fx * delta_zoom;
        handle->top_left.y -= fy - fy * delta_zoom;
        handle->zoom *= delta_zoom;
    }

    ofx = fx;
    ofy = fy;

    return 1;
}