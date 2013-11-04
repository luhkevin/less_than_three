/* Renders the world and/or room 
 * 
 * Draws Three and all the NPCs and objects
 */

#include "render.h"

//Will print the room id
void render_room(Room* rm) {
    int i;
    mvwprintw(game_win, 1, 1, "%s", "0-0");

    //for(i = 0; i < 4; i++) {
        //if((rm -> door_x[i]) > 0) 
            //TODO:Eventually, initialize World_obj with the rooms, put them
            //inside the room struct
            mvwprintw(game_win, 20, 20, "%s", "dd");
    //}

    wrefresh(game_win);
}


//Special function to redraw the player specifically
void render_player(Player* p) {
    init_pair(1, COLOR_RED, COLOR_GREEN);
    wattron(game_win, COLOR_PAIR(1));
    mvwprintw(game_win, p -> y_pos, p -> x_pos, "%s", "3");
    wattroff(game_win, COLOR_PAIR(1));

    wrefresh(game_win);
}

//Clears the player by filling position with 'blank'
//TODO: store next x/y position within the clear_player function
void clear_player(Player* p) {
    mvwprintw(game_win, p -> y_pos, p -> x_pos, "%s", " ");
    wrefresh(game_win);
}
