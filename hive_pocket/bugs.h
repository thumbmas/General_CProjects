#ifndef __BUGS_H__
#define __BUGS_H__

#include <stdbool.h>

typedef enum {
    BEE = 0,
    ANT = 1,
    GRASSHOPER = 2,
    SPIDER = 3,
    LADYBUG = 4,
    BEETLE = 5,
    MOSQUITO = 6,
    PILLBUG = 7,
} bug_type_e;

typedef enum {
    INFINITE_STEP = 0, // ant grasshoper
    SINGLE_STEP = 1,
    TRIPLE_STEP = 3, // ladybug and spider
} step_sizes_e;

typedef enum {
    EDGE_STEP = 1, // Must skirt around the edge of the field,
    LINEAR_STEP = 2, // Must travel in a straight line to 
    FREE_STEP = 3,
} step_type_e;

typedef enum {
    CANT_CLIMB = 0,
    CAN_CLIMB = 1,
} climb_type_e;

typedef enum {
    BLACK_TEAM = 0,
    WHITE_TEAM = 1,
} team_e;

struct bug_stats {
    const step_sizes_e step_size;
    const step_type_e step_type;
    const climb_type_e climb_type;
    const bool skill_drain;    
};

typedef struct {
    team_e team;
    const bug_type_e bug_type;
    struct bug_stats bug_stats;
} bug_s;

bug_s bee = {
    .bug_type = BEE,
    .bug_stats = {
        .step_size = SINGLE_STEP,
        .step_type = EDGE_STEP,
        .climb_type = CANT_CLIMB,
        .skill_drain = false,
    }
};

bug_s ant = {
    .bug_type = ANT,
    .bug_stats = {
        .step_size = INFINITE_STEP,
        .step_type = EDGE_STEP,
        .climb_type = CANT_CLIMB,
        .skill_drain = false,
    }
};

bug_s grasshopeer = {
    .bug_type = GRASSHOPER,
    .bug_stats = {
        .step_size = INFINITE_STEP,
        .step_type = LINEAR_STEP,
        .climb_type = CAN_CLIMB,
        .skill_drain = false,
    }
};

bug_s spider = {
    .bug_type = SPIDER,
    .bug_stats = {
        .step_size = TRIPLE_STEP,
        .step_type = EDGE_STEP,
        .climb_type = CANT_CLIMB,
        .skill_drain = false,
    }
};

bug_s ladybug = {
    .bug_type = LADYBUG,
    .bug_stats = {
        .step_size = TRIPLE_STEP,
        .step_type = FREE_STEP,
        .climb_type = CAN_CLIMB,
        .skill_drain = false,
    }
};

bug_s beetle = {
    .bug_type = BEETLE,
    .bug_stats = {
        .step_size = SINGLE_STEP,
        .step_type = FREE_STEP,
        .climb_type = CAN_CLIMB,
        .skill_drain = false,
    }
};

bug_s mosquito = {
    .bug_type = MOSQUITO,
    .bug_stats = {
        .step_size = SINGLE_STEP,
        .step_type = EDGE_STEP,
        .climb_type = CANT_CLIMB,
        .skill_drain = true,
    }
};

#endif /*__BUGS_H__*/