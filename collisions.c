#include "collisions.h"


int collide_player(Player* p1, Player* p2) {
    int i, j;

    int p1_x = p1 -> x_pos;
    int p1_y = p1 -> y_pos;

    int p2_x = p2 -> x_pos;
    int p2_y = p2 -> y_pos;


    //Check the neighborhood
    for(i = -1; i < 2; i++) {
        for(j = -1; j < 2; j++) {
            if((i || j) && (p2_x == p1_x + i && p2_y == p1_y + j)) {
                return 1;
            }
        }
    }

    return 0;
}

