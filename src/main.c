#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "map/map.h"
#include "map/crossing.h"
#include "map/street.h"
#include "map/car.h"
#include "config.h"

#ifndef NOGUI
#include "gui.h"
#endif

#define CROSSING_COUNT 10

#define randf() ((float)rand() / (float)RAND_MAX)

int main(int argc, char **argv) {
    MAP *map;
    CROSSING *crossings[CROSSING_COUNT];

#ifndef NOGUI
    WINDOW_HANDLE *handle;
#endif

    printf("Creating map...\n");
    map = map_create();

    printf("Creating crossings...\n");
    srand(time(0));
    
    for (int i = 0; i < CROSSING_COUNT; i++) {
        crossings[i] = crossing_create(map, randf(), randf(), NULL);
    }

    printf("Linking crossings...\n");
    for (int i = 0; i < CROSSING_COUNT; i++) {
        for (int j = 1; j < MAX_CROSSINGS + 1; j++) {
            street_create(map, crossings[i], crossings[(i + j) % CROSSING_COUNT], 100);
        }
    }

#ifndef NOGUI
    printf("Showing window...\n");
    handle = gui_open_window(map);

    gui_render(handle);

    sleep(3);

    printf("Destroying window...\n");
    gui_close_window(handle);
#endif

    printf("Destroying map...\n");
    map_destroy(map);

    return 0;
}