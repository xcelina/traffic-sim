#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "sim/map.h"
#include "sim/crossing.h"
#include "sim/street.h"
#include "sim/car.h"
#include "config.h"

#ifndef NOGUI
#include "gui.h"
#endif

int main(int argc, char **argv) {
    MAP *map;

    map = map_randomize(10, 5);

#ifndef NOGUI
    WINDOW_HANDLE *handle;

    printf("Showing window...\n");
    handle = gui_open_window(map);

    while (gui_update(handle)) {
        gui_render(handle);
    }

    printf("Destroying window...\n");
    gui_close_window(handle);
#endif

    printf("Destroying map...\n");
    map_destroy(map);

    return 0;
}