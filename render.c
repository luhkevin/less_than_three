/* Renders the world and/or room 
 * 
 * Draws Three and all the NPCs and objects
 */

#include <curses.h>
#include "render.h"

//Will print the room id
void render_room(Room* rm) {
    mvprintw(0, 0, "%s", rm -> id);
    refresh();
}


//Special function to redraw the player specifically
void render_player(Player* p) {
    mvprintw(p -> y_pos, p -> x_pos, "%c", p -> id);
    refresh();
}

//Clears the player by filling position with 'blank'
//TODO: store next x/y position within the clear_player function
void clear_player(Player* p) {
    mvprintw(p -> y_pos, p -> x_pos, "%c", ' ');
    refresh();
}
