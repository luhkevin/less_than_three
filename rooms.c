#include <stdlib.h>
#include <string.h>
#include "rooms.h"

/* 
 * Initializes all doors and directions to 0;
 *
 * create_room should also set the position of the doors, generate any 
 * animations, draw the walls/borders, draw the scenery, and generate the 
 * interactive objects and NPCs.
 *
 *
 * TODO: add params to create_room
 */

Room* init_room(char room_id[4]) {
    int i;

    Room* rm = malloc(sizeof(Room*));
    for(i = 0; i < 4; i++) {
        rm -> door_x[i] = -1;
        rm -> door_y[i] = -1;

        rm -> directions[i] = malloc(sizeof(Room*));
        rm -> directions[i] = 0;
    }

    strcpy(rm -> id, room_id);
    return rm;
}
    
