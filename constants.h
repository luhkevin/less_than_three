#include <curses.h>

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
 * GAME, menu, announcement WINDOWs
 *
 */
WINDOW* game_win;
WINDOW* menu_win;
WINDOW* announcement_win;

/* 
 * PLAYER POSITION
 *
 */
unsigned int x_pos;
unsigned int y_pos;

#endif
