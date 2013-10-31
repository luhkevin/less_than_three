#include <curses.h>
#include <stdlib.h>
#include "render.h"
#include "player.h"
#include "world.h"
#include "collisions.h"
#include "dialogue.h"
#include "interact.h"

//TODO: Minigames/minipuzzles must be LOADABLE and MODULAR
//TODO: gamestate.lua type thing: what happens upon switching rooms
//TODO: init/setup in rooms
//TODO: Establish screen (i.e. limit main game screen to a 800x600 box in the middle of the screen)

int main() {
    int c;

    //Create world
    World* world = create_world();

    initscr();

    //Initialize player '3'
    Player* three = create_player(COLS / 2, LINES / 2, '3');
    three -> cur   = world -> room_arr[0];
    three -> id = '3';

    //Initialize player '<'
    Player* less  = create_player(COLS / 2, LINES / 4, '<');
    less  -> cur   = world -> room_arr[0];
    less  -> id = '<';

    keypad(stdscr, TRUE);
    noecho();
    cbreak();

    curs_set(0); //Don't show cursor
    start_color(); 
    init_pair(1, COLOR_RED, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_RED);

    //getmaxyx(stdscr, row, col); //updates row col to max x, y of stdscr

    //Main game loop
    while(c != 'q') {
        //Render room/world based on movement
        //AND/OR handle the appropriate event (minigame/puzzle)
        render_room(three -> cur);

        //Render players
        attron(COLOR_PAIR(1));
        render_player(three);
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(2));
        render_player(less);
        attroff(COLOR_PAIR(2));

        //Player movement
        c = getch();
        switch(c) {
            case KEY_UP:
                clear_player(three);
                (three -> y_pos)--;
                break;
            case KEY_DOWN:
                clear_player(three);
                (three -> y_pos)++;
                break;
            case KEY_RIGHT:
                clear_player(three);
                (three -> x_pos)++;
                break;
            case KEY_LEFT:
                clear_player(three);
                (three -> x_pos)--;
                break;
            default:
                break;
        }

        //Check collisions (with door/NPC/some other object)
        if(collide_player(three, less)) {
            //Open up dialogue box
            WINDOW* win = create_dialogue_box();            
            get_dialogue(win);
            mvprintw(1, 0, "%s", "collision!");
        }

        /*
        //Create a door...this should go in some room init file
        World_obj* door = malloc(sizeof(World_obj*));
        door -> y_pos = 40;
        door -> x_pos = 0;
        door -> id    = "dd";
        mvprintw(door -> y_pos, door -> x_pos, "%s", door -> id);
        */

        if(collide_object(three, door)) {
            mvprintw(2, 0, "%s", "collision with door!");
            three -> cur   = world -> room_arr[1];
        }
    }

    refresh();
    endwin();
    return 0;
}

