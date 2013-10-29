#include <stdlib.h>
#include "map.h"
#ifndef PLAYER_H
#define PLAYER_H

//TODO: Inventory items will be implemented with a stack
//Only have a cash field for now
typedef struct inventory {
    int cash;
} Inventory;

typedef struct player {
    int x_pos;
    int y_pos;
    
    //Another struct that holds the player's inventory
    Inventory* inv;

    //Skills/stats i will be stored in stats[i], with right hand values from 0 - 10
    int stats[5];
    char id;

    //Current room
    Room* cur;
} Player;

Player* create_player(int x, int y, char id);
#endif 
