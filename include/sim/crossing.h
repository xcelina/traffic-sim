#ifndef __CROSSING_H__
#define __CROSSING_H__

typedef struct CROSSING_POLICY CROSSING_POLICY;
typedef struct CROSSING CROSSING;

#include "sim/map.h"
#include "sim/street.h"
#include "config.h"

typedef void (*crossing_update)(MAP *map, CROSSING *crossing, float delta);

struct CROSSING_POLICY {

};

struct CROSSING {
    struct {
        float x, y;
    } position;

    STREET *source[MAX_CROSSINGS];
    STREET *drain[MAX_CROSSINGS];

    int adjacency[MAX_CROSSINGS][MAX_CROSSINGS];
    int passable[MAX_CROSSINGS];

    CROSSING_POLICY *policy;

    CROSSING *map_next;
};

CROSSING *crossing_create(MAP *map, float x, float y, CROSSING_POLICY *policy);

int crossing_add_source(CROSSING *crossing, STREET *source);
int crossing_add_drain(CROSSING *crossing, STREET *drain);

#endif