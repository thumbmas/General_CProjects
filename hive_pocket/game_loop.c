#include <stdio.h>
#include <stdlib.h>
#include "game_loop.h"
#include "bugs.h"

static game_state_e game_state;
static game_event_queue_s game_event_queue;

game_state_e get_game_state(void)
{
    return game_state;
}

bool evt_queue_full(void)
{
    if ((game_event_queue.head == game_event_queue.tail) && (game_event_queue.capacity == REQUEST_QUEUE_SIZE)) {
       return true; 
    }
    return false;
}

bool evt_queue_empty(void)
{
    if ((game_event_queue.head == game_event_queue.tail) && (game_event_queue.capacity != REQUEST_QUEUE_SIZE)) {
       return true; 
    }
    return false;
}

bool evt_enqueue(request_packet_s evt_request)
{
    if (!evt_queue_full()) {
        game_event_queue.request_queue[game_event_queue.head] = evt_request;
        if(++game_event_queue.head >= REQUEST_QUEUE_SIZE) {
            game_event_queue.head = 0;
        }
        ++game_event_queue.capacity;
        return true;
    }
    return false;
}

static bool evt_read_queue(request_packet_s* next_event)
{
    if (!evt_queue_empty()) {
        request_packet_s latest_event = game_event_queue.request_queue[game_event_queue.tail];
        if(++game_event_queue.tail >= REQUEST_QUEUE_SIZE) {
            game_event_queue.tail = 0;
        }
        --game_event_queue.capacity;
        return true;
    }
    return false;
}

static void init_event_queue(game_event_queue_s* queue)
{
    queue->head = 0;
    queue->tail = 0;
}

static void setup_game()
{
    init_event_queue(&game_event_queue);
    //
    //
    //
    //

    game_loop();
}

static void game_loop() {

    switch(game_state) {
        case GAME_PENDING:
            break;
        case GAME_SETUP:
            break;
        case GAME_START:
            break;
        case GAME_WHITE_TURN:
            break;
        case GAME_BLACK_TURN:
            break;
        case GAME_END:
            break;
        case GAME_EXIT:
            break;
        default:
            break;
    }
}

void start_game() {
    game_state = GAME_SETUP;
    system("clear");
    setup_game();
}