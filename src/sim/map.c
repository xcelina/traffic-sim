#include <stdlib.h>

#include "sim/map.h"

#define randf() ((float)rand() / (float)RAND_MAX)

MAP *map_create(void) {
    MAP *map = (MAP*) malloc(sizeof(MAP));

    if (map != NULL) {
        map->crossing_list = NULL;
        map->street_list = NULL;
        map->car_list = NULL;
    }

    return map;
}

void map_destroy(MAP *map) {
    while (map->crossing_list != NULL) {
        CROSSING *current = map->crossing_list;
        map->crossing_list = current->map_next;
        free(current);
    }

    while (map->street_list != NULL) {
        STREET *current = map->street_list;
        map->street_list = current->map_next;
        free(current);
    }

    while (map->car_list != NULL) {
        CAR *current = map->car_list;
        map->car_list = current->map_next;
        free(current);
    }

    free(map);
}

void map_add_crossing(MAP *map, CROSSING *crossing) {
    crossing->map_next = map->crossing_list;
    map->crossing_list = crossing;
}

void map_add_car(MAP *map, CAR *car) {
    car->map_next = map->car_list;
    map->car_list = car;
}

void map_add_street(MAP *map, STREET *street) {
    street->map_next = map->street_list;
    map->street_list = street;
}

void map_rem_crossing(MAP *map, CROSSING *crossing) {

}

void map_rem_car(MAP *map, CAR *car) {

}

void map_rem_street(MAP *map, STREET *street) {

}

MAP *map_randomize(int crossings, int streets) {
    MAP *map;

    map = map_create();

    for (int i = 0; i < crossings; i++) {
        crossing_create(map, randf(), randf(), NULL);
    }

    return map;
}

MAP *map_import(FILE *source) {

}