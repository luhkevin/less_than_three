#include <curses.h>
#include <panel.h>

#ifndef CONSTANTS_H
#define CONSTANTS_H
/* Defines some of the constants in the world (door length, etc...) */


/* 
 * CURRENT ROOM ID
 * A room_id of xx means room x-x
 * So room_id = 21 meeans room 2-1
 *
 */
unsigned int room_id;

/*
 * GAME WINDOW
 *
 */
WINDOW* game_win;
WINDOW* dialogue_win;
/*
 * GAME PANEL
 *
 */
PANEL* game_pan;
PANEL* dialogue_pan;

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

#endif
