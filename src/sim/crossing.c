#include <stddef.h>
#include <stdlib.h>

#include <math.h>

#include "sim/crossing.h"

#include "config.h"

int crossing_add_source(CROSSING *crossing, STREET *source) {
    for (int i = 0; i < MAX_CROSSINGS; i++) {
        if (crossing->source[i] == NULL) {
            crossing->source[i] = source;
            return 0;
        }
    }

    return 1;
}

int crossing_add_drain(CROSSING *crossing, STREET *drain) {
    for (int i = 0; i < MAX_CROSSINGS; i++) {
        if (crossing->drain[i] == NULL) {
            crossing->drain[i] = drain;
            return 0;
        }
    }

    return 1;
}

CROSSING *crossing_create(MAP *map, float x, float y, CROSSING_POLICY *policy) {
    CROSSING *crossing = (CROSSING*) malloc(sizeof(CROSSING));

    if (crossing != NULL) {
        crossing->position.x = x;
        crossing->position.y = y;
        crossing->policy = policy;

        for (int i = 0; i < MAX_CROSSINGS; i++) {
            crossing->source[i] = NULL;
            crossing->drain[i] = NULL;

            crossing->passable[i] = 0;

            for (int j = 0; j < MAX_CROSSINGS; j++) {
                crossing->adjacency[i][j] = 0;
            }
        }

        map_add_crossing(map, crossing);
    }

    return crossing;
}

float crossing_get_distance(CROSSING *a, CROSSING *b) {
  if (a != NULL && b != NULL) {
    float delta_x = b->position.x - a->position.x,
          delta_y = b->position.y - a->position.y;
    return (float) sqrt(delta_x * delta_x + delta_y * delta_y);
  } else {
    return -1.0f;
  }
}
