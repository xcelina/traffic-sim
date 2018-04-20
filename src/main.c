#include <stdio.h>

#include "map/map.h"
#include "map/crossing.h"
#include "map/street.h"
#include "map/car.h"
#include "config.h"

#define CROSSING_COUNT 10

int main(int argc, char **argv) {
    printf("Creating map...\n");
    MAP *map = map_create();

    printf("Creating crossings...\n");
    CROSSING *crossings[CROSSING_COUNT];
    
    for (int i = 0; i < CROSSING_COUNT; i++) {
        crossings[i] = crossing_create(map, 0, 0, NULL);
    }

    printf("Linking crossings...\n");
    for (int i = 0; i < CROSSING_COUNT; i++) {
        for (int j = 1; j < MAX_CROSSINGS + 1; j++) {
            street_create(map, crossings[i], crossings[(i + j) % CROSSING_COUNT], 100);
        }
    }

    printf("Destroying map...\n");
    map_destroy(map);

    return 0;
}