#include <curses.h>
#include <stdlib.h>
#include "render.h"
#include "player.h"
#include "world1.h"
#include "collisions.h"

//TODO: Minigames/minipuzzles must be LOADABLE and MODULAR

int main() {
    int c;

    //Create world
    World* world1 = create_world();

    initscr();

    //Initialize player '3'
    Player* three = create_player(COLS / 2, LINES / 2, '3');
    three -> cur   = world1 -> room_arr[0];
    three -> id = '3';

    //Initialize player '<'
    Player* less  = create_player(COLS / 4, LINES / 4, '<');
    less  -> cur   = world1 -> room_arr[0];
    less  -> id = '<';

    keypad(stdscr, TRUE);
    noecho();
    cbreak();

    curs_set(0); //Don't show cursor
    start_color(); 
    init_pair(1, COLOR_RED, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_RED);

    //getmaxyx(stdscr, row, col); //updates row col to max x, y of stdscr
    /*
    attron(COLOR_PAIR(1));
    mvprintw(three -> y_pos, three -> x_pos , "%c", '3');
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(less -> y_pos, less -> x_pos , "%c", '<');
    attroff(COLOR_PAIR(2));
    */

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
            case KEY_F(1):
                //menu
                break;
            default:
                break;
        }

        //Check collisions (with door/NPC/some other object)
        if(collide_player(three, less)) {
            //Open up dialogue box
            mvprintw(1, 0, "%s", "collision!");
        }
    }

    refresh();
    endwin();
    return 0;
}

