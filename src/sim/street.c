#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "sim/street.h"
#include "sim/crossing.h"

STREET *street_create(MAP *map, CROSSING *source, CROSSING *drain, float tempo_limit) {
    if (source == NULL || drain == NULL || map == NULL) { 
        fprintf(stderr, "Argument null exception in street_create\n");
        return NULL;
    }
    
    STREET *street = (STREET*) malloc(sizeof(STREET));

    if (street == NULL) {
        fprintf(stderr, "Out of memory exception in street_create\n");
        return NULL; 
    }

    street->tempo_limit = tempo_limit;
    street->source = source;
    street->drain = drain;
    street->length = crossing_get_distance(source, drain);

    if (crossing_add_source(drain, street) || crossing_add_drain(source, street)) {
        fprintf(stderr, "Could not connect street in street_create\n");
        free(street);
        return NULL;
    }

    map_add_street(map, street);

    return street;
}
