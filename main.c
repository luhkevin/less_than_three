#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "render.h"
#include "player.h"
#include "world.h"
#include "world_creation.h"
#include "collisions.h"
#include "dialogue.h"
#include "interact.h"

//TODO: Minigames/minipuzzles must be LOADABLE and MODULAR
//TODO: gamestate.lua type thing: what happens upon switching rooms
//TODO: init/setup in rooms
//TODO: Establish screen (i.e. limit main game screen to a 800x600 box in the middle of the screen)

#define GAMEWIN_HEIGHT 40
#define GAMEWIN_WIDTH  120

int main(int argc, char** argv) {
    int startx, starty;
    int c;

    //TODO: Put all this into init incrementally! 
    World* world = init_world_0();

    initscr();
    cbreak();
    keypad(stdscr, TRUE);

    starty = (LINES - GAMEWIN_HEIGHT) / 2;
    startx = (COLS - GAMEWIN_WIDTH) / 2;

    refresh();

    game_win = newwin(GAMEWIN_HEIGHT, GAMEWIN_WIDTH, starty, startx);
    game_pan = new_panel(game_win);

    //Initialize player '3'
    Player* three = create_player(COLS / 2, LINES / 2, "3");
    three -> cur   = world -> room_arr[0];
    strcpy(three -> id, "3");

    //Initialize player '<'
    Player* less  = create_player(COLS / 2, LINES / 4, "<");
    less  -> cur   = world -> room_arr[0];
    strcpy(less -> id, "<");
    
    noecho();
    curs_set(0); //Don't show cursor
 
    start_color(); 
    init_pair(1, COLOR_RED, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_RED);

    //DOORS move this into world_creation later
    World_obj* door = malloc(sizeof(World_obj*));
    door -> id = "dd";
    door -> x_pos = 20;
    door -> y_pos = 20; 
    world -> room_arr[0] -> door_x[0] = door -> x_pos;
    world -> room_arr[0] -> door_y[0] = door -> y_pos;
   
    world -> room_arr[1] -> door_x[0] = 5;
    world -> room_arr[1] -> door_y[0] = 5;
    wclear(game_win);

    box(game_win, 0, 0); //0, 0: default char for vert/horz lines

    //Main game loop
    while(c != 'q') {
        update_panels();
        doupdate();
        wrefresh(game_win);

        box(game_win, 0, 0); //0, 0: default char for vert/horz lines

        //Render room/world based on movement
        //AND/OR handle the appropriate event (minigame/puzzle)
        render_room(three -> cur);

        //Render players
        render_player(three);
        render_player(less);

        c = getch();

        //Player movement
        switch(c) {
            case KEY_UP:
                if(!collide_walls(three, 0)) {
                    clear_player(three);
                    (three -> y_pos)--;
                } 
                break;
            case KEY_DOWN:
                if(!collide_walls(three, 2)) {
                    clear_player(three);
                    (three -> y_pos)++;
                }
                break;
            case KEY_RIGHT:
                if(!collide_walls(three, 1)) {
                    clear_player(three);
                    (three -> x_pos)++;
                }
                break;
            case KEY_LEFT:
                if(!collide_walls(three, 3)) {
                    clear_player(three);
                    (three -> x_pos)--;
                }
                break;
            default:
                break;
        }

        mvprintw(1, 1, "%d %d", three -> x_pos, three -> y_pos);
        refresh();
        //Check collisions (with door/NPC/some other object)
        if(collide_player(three, less)) {
            //Open up dialogue box
            create_dialogue_box();            
            get_dialogue();
            mvprintw(1, 0, "%s", "collision!");
            hide_panel(dialogue_pan);
            update_panels();
            doupdate();
        }

        if(collide_object(three, door)) {
            mvprintw(2, 0, "%s", "collision with door!");
            refresh();
            three -> cur = world -> room_arr[1];
            wclear(game_win);
        }
    }

    wrefresh(game_win);
    endwin();
    return 0;
}

