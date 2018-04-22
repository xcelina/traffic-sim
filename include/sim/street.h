#ifndef __STREET_H__
#define __STREET_H__

typedef struct STREET STREET;

#include "sim/map.h"
#include "sim/crossing.h"
#include "sim/car.h"

struct STREET {
    CROSSING *source;
    CROSSING *drain;

    float length;
    float tempo_limit;

    CAR *first_car;

    STREET *map_next;
};

STREET *street_create(MAP *map, CROSSING *source, CROSSING *drain, float tempo_limit);

#endif