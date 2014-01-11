#include <curses.h>
#include <panel.h>

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define GAMEWIN_HEIGHT 40
#define GAMEWIN_WIDTH  120

/* Defines some of the constants in the world (door length, etc...) */

WINDOW* game_win;
PANEL* game_pan;

WINDOW* dialogue_win;
PANEL* dialogue_pan;

/* 
 * CURRENT ROOM ID
 * A room_id of xx means room x-x
 * So room_id = 21 meeans room 2-1
 *
 */
unsigned int room_id;

/* 
 * PLAYER POSITION
 *
 */
unsigned int x_pos;
unsigned int y_pos;

/*
 * DIALOGUE STATE
 *
 */
//TODO: 'foo' and 'bar' are obviously placeholders
typedef enum {foo, bar} dialogue_state;

typedef enum {NORTH, EAST, SOUTH, WEST} Directions;
#endif
