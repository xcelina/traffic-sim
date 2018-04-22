#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>

typedef struct MAP MAP;

#include "sim/crossing.h"
#include "sim/street.h"
#include "sim/car.h"

struct MAP {
    CROSSING *crossing_list;
    CAR *car_list;
    STREET *street_list;
};

MAP *map_create(void);
void map_destroy(MAP *map);

void map_add_crossing(MAP *map, CROSSING *crossing);
void map_add_car(MAP *map, CAR *car);
void map_add_street(MAP *map, STREET *street);

void map_rem_crossing(MAP *map, CROSSING *crossing);
void map_rem_car(MAP *map, CAR *car);
void map_rem_street(MAP *map, STREET *street);

MAP *map_randomize(int crossings, int streets);
MAP *map_import(FILE *source);

#endif