#include "collisions.h"

//TODO: USE FUNCTION POINTERS HERE?
int check_nbd(int x1, int y1, int x2, int y2) {
    int i, j;
    for(i = -1; i < 2; i++) {
        for(j = -1; j < 2; j++) {
            if((i || j) && (x2 == x1 + i && y2 == y1 + j)) {
                return 1;
            }
        }
    }

    return 0;
}

int collide_player(Player* p1, Player* p2) {
    int p1_x = p1 -> x_pos;
    int p1_y = p1 -> y_pos;

    int p2_x = p2 -> x_pos;
    int p2_y = p2 -> y_pos;

    return check_nbd(p1_x, p1_y, p2_x, p2_y);
}


int collide_object(Player* p, World_obj* wo) {
    int p_x = p -> x_pos;
    int p_y = p -> y_pos;

    int o_x = wo -> x_pos;
    int o_y = wo -> y_pos;

    return check_nbd(p_x, p_y, o_x, o_y);
}

int collide_walls(Player* p, Directions dir) {
    int p_x = p -> x_pos;
    int p_y = p -> y_pos;

    if(dir == NORTH) return (p_y == 1);
    if(dir == EAST) return (p_x == 118);
    if(dir == SOUTH) return (p_y == 38);
    if(dir == WEST) return (p_x == 1);

    return 1;
}
