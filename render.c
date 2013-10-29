/* Renders the world and/or room 
 * 
 * Draws Three and all the NPCs and objects
 */

#include <curses.h>
#include "render.h"

//Will print the room id
void render_room(Room* rm) {
    //printw(rm -> id);
}


//Special function to redraw the player specifically
void render_player(Player* p) {
    init_pair(1, COLOR_RED, COLOR_GREEN);

    //TODO: can be more efficient with clrtoeol and moving the cursor cleverly
    clear();
    attron(COLOR_PAIR(1));
    mvprintw(p -> y_pos, p -> x_pos, "%c", '3');
    attroff(COLOR_PAIR(1));

    refresh();
}

