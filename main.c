#include <curses.h>
#include <stdlib.h>
#include "render.h"
#include "player.h"
#include "world1.h"

//TODO: Minigames/minipuzzles must be LOADABLE and MODULAR

int main() {
    int i, c;
    //Menu window...TODO: This should be a panel/menu.
    
    //Create world
    World* world1 = create_world();

    //Initialize player '3'
    Player* three = malloc(sizeof(Player*));
    Inventory* three_inv = malloc(sizeof(Inventory*));

    initscr();

    //Start 3 in the middle of the screen
    three -> x_pos = COLS / 2;
    three -> y_pos = LINES / 2;
    three -> inv   = three_inv;
    for(i = 0; i < 5; i++) {
        three -> stats[i] = 0;
    }
    three -> cur   = malloc(sizeof(Room*));
    three -> cur   = world1 -> room_arr[0];

    keypad(stdscr, TRUE);
    noecho();
    cbreak();

    curs_set(0); //Don't show cursor
    start_color(); 
    init_pair(1, COLOR_RED, COLOR_GREEN);

    //getmaxyx(stdscr, row, col); //updates row col to max x, y of stdscr
    attron(COLOR_PAIR(1));
    mvprintw(three -> y_pos, three -> x_pos , "%c", '3');
    attroff(COLOR_PAIR(1));

    //Main game loop
    while(c != 'q') {
        //Check collisions (with door/NPC/some other object)
        
        c = getch();

        //Player movement
        switch(c) {
            case KEY_UP:
                (three -> y_pos)--;
                break;
            case KEY_DOWN:
                (three -> y_pos)++;
                break;
            case KEY_RIGHT:
                (three -> x_pos)++;
                break;
            case KEY_LEFT:
                (three -> x_pos)--;
                break;
            case KEY_F(1):
                //menu
                break;
            default:
                break;
        }

        //Render room/world based on movement
        //AND/OR handle the appropriate event (minigame/puzzle)
        //TODO: function pointers?
        render_player(three);
        render_room(three -> cur);
    }

    refresh();
    endwin();
    return 0;
}

