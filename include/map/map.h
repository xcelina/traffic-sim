#ifndef __MAP_H__
#define __MAP_H__

typedef struct MAP MAP;

#include "map/crossing.h"
#include "map/street.h"
#include "map/car.h"

struct MAP {
    CROSSING *crossing_list;
    CAR *car_list;
    STREET *street_list;
};

MAP *map_create(void);
void map_destroy(MAP *map);

void map_update(MAP *map, float delta);

void map_add_crossing(MAP *map, CROSSING *crossing);
void map_add_car(MAP *map, CAR *car);
void map_add_street(MAP *map, STREET *street);

#endif