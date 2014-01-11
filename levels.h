#include <stdlib.h>
#include "globals.h"
#include "interact.h"
#include "rooms.h"

#ifndef WORLD_H
#define WORLD_H

typedef struct world {
    int world_id;
    Room* room_arr[20];
} World;


//mallocs and sets world id
World* create_world(int world_id);

//Creates n rooms
void create_rooms(World* wd, int n);

//Connects rm1 from dir1 to rm2 from dir2
void create_connections(Room* rm1, Room* rm2, Directions dir1, Directions dir2);

#endif

