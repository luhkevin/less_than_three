#include "player.h"

Player* create_player(int x, int y) {
    int i;
    Player* p = malloc(sizeof(Player*));
    p -> inv  = malloc(sizeof(Inventory*));
    p -> x_pos = x;
    p -> y_pos = y;

    for(i = 0; i < 6; i++) {
        stats[i] = 0;
    }

    p -> cur   = malloc(sizeof(Room*));

    return p;
}

