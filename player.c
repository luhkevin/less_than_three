#include "player.h"
#include <curses.h>

Player* create_player(int x, int y, char name[2]) {
    int i;
    Player* p = malloc(sizeof(Player*));
    p -> inv  = malloc(sizeof(Inventory*));
    p -> x_pos = x;
    p -> y_pos = y;
    //mvprintw(1, 1, "THE NAME IS: %s", name);
    strcpy(p -> id, name);

    for(i = 0; i < 6; i++) {
        p -> stats[i] = 0;
    }

    p -> cur   = malloc(sizeof(Room*));
    return p;
}

