#include <stdlib.h>
#include "map.h"

/* 
 * Initializes all doors and directions to 0;
 *
 * create_room should also set the position of the doors, generate any 
 * animations, draw the walls/borders, draw the scenery, and generate the 
 * interactive objects and NPCs.
 *
 * It should also create the new window and destroy the previous one
 *
 * TODO: add params to create_room
 */

Room* create_room(char* room_id) {
    int i;

    Room* rm = malloc(sizeof(Room*));
    for(i = 0; i < 4; i++) {
        rm -> door_x[i] = 0;
        rm -> door_y[i] = 0;

        rm -> directions[i] = malloc(sizeof(Room*));
        rm -> directions[i] = 0;
    }

    rm -> id = room_id;
    return rm;
}
    
void connect_room(Room* rm1, Room* rm2, int dir1, int dir2) {
    (rm1 -> directions[dir1]) = rm2;
    (rm2 -> directions[dir2]) = rm1;
}

