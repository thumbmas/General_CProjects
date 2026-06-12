#ifndef __GAME_LOOP_H__
#define __GAME_LOOP_H__

#include <stdint.h>
#include <stdbool.h>
#include "bugs.h"

#define REQUEST_QUEUE_SIZE 5

typedef enum {
    GAME_PENDING,
    GAME_SETUP,
    GAME_START,
    GAME_UPDATE_BOARD,
    GAME_WHITE_TURN_START,
    GAME_WHITE_TURN_END,
    GAME_BLACK_TURN_START,
    GAME_BLACK_TURN_END,
    GAME_END,
    GAME_EXIT,
} game_state_e;

typedef struct {
    int8_t x_coord;
    int8_t y_coord;
} hex_coord_s;

typedef struct {
    game_state_e state_request;
    hex_coord_s coord;
    bug_type_e bug;
} request_packet_s;

typedef struct {
    request_packet_s request_queue[REQUEST_QUEUE_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t capacity;
} game_event_queue_s;

game_state_e get_game_state(void);

bool evt_queue_full(void);

bool evt_queue_empty(void);

bool evt_enqueue(request_packet_s evt_request);

void start_game(void);

#endif // __GAME_LOOP_H__