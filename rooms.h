#ifndef ROOMS_H
#define ROOMS_H

#include "globals.h"

/* Map creation 
 *
 * Worlds will be traversed based on certain events. 
 * For every world, there will be a series of *rooms* connected by *doors*.
 *
 * Each room is a struct with a north, south, east, west pointer to 
 * another room. 
 *
 * Each room struct will also contain all the other information in the room:
 * interactive objects, NPCs, items, etc...
 *
 * The rooms will all be loaded into memory and free'd when Three moves 
 * between worlds
 *
 */

typedef struct room {
    //Doors only need an (x, y) position, as they will have constant length
    //(door_x[i], door_y[i]) is the (x, y) position of the i-th door
    int door_x[4];
    int door_y[4];

    //0: north, 1: south, 2: east, 3: west
    struct Room* directions[4];

    //Identification (World 1 - Room 1: 1-1)
    char id[4];
} Room;


/************ ROOM CREATION ************/
Room* init_room(char room_id[4]);

//Adds interactive objects
void add_objects(Room* rm);

void add_doors(Room* rm, int door_x[4], int door_y[4]);
void add_npcs(Room* rm);
void add_walls(Room* rm);
void add_animations(Room* rm);

#endif
