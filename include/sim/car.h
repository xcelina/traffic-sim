#ifndef __CAR_H__
#define __CAR_H__

typedef struct CAR CAR;

#include "sim/map.h"
#include "sim/street.h"
#include "sim/crossing.h"

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