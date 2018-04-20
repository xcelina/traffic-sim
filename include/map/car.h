#ifndef __CAR_H__
#define __CAR_H__

typedef struct CAR CAR;

#include "map/map.h"
#include "map/street.h"
#include "map/crossing.h"

struct CAR {
    float top_speed;
    float speed;
    float acc;
    float deacc;

    STREET *current_street;
    float position;

    CROSSING *destination;

    CAR *street_next;
    CAR *map_next;
};

#endif