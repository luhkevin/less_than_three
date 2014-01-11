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

Room* init_room(char id[4]) {
    int i;

    Room* rm = malloc(sizeof(Room*));
    for(i = 0; i < 4; i++) {
        rm -> door_x[i] = -1;
        rm -> door_y[i] = -1;

        rm -> directions[i] = malloc(sizeof(Room*));
        rm -> directions[i] = 0;
    }

    strcpy(rm -> id, id);
    return rm;
}
    

void add_doors(Room* rm, int door_x[4], int door_y[4]) {
    int i;
    for(i = 0; i < 4; i++) {
        rm -> door_x[i] = door_x[i];
        rm -> door_y[i] = door_x[i];
    }
}

void add_objects(Room* rm);

void add_npcs(Room* rm);

void add_walls(Room* rm);

void add_animations(Room* rm);

