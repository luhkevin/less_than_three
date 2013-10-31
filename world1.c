/*
 * This will generate all the rooms in a particular world.
 * I.e. load all of these rooms into memory.
 * 
 * TODO: Perhaps load into memory room-by-room, instead of
 * world-by-world
 *
 * "create_world" does initial malloc-ing
 * "create_connections" runs connect_room on the rooms
 *
 * TODO: But shouldn't these be in map.h?
 * "create_doors" creates the door positions
 * "create_objects" creates the interactive objects
 * "create_npcs" creates the npcs
 * ...
 * TODO: more to come?
 */

#include "world.h"

//TODO: Function pointers here? for "inheriting" the create_world function?
//Because they need to be different per world
//Same with rooms, for that matter
World* create_world() {
    World* wd = malloc(sizeof(World*));

    wd -> room_arr[0] = create_room("0-0");
    wd -> room_arr[1] = create_room("0-1");
    wd -> room_arr[2] = create_room("0-2");
    wd -> room_arr[3] = create_room("0-3");
    wd -> room_arr[4] = create_room("0-4");

    //Connect rm0 to rm1 from the north
    connect_room(wd -> room_arr[0], wd -> room_arr[1], 0, 1);

    //Create a door...this should go in some room init file
    World_obj* door = malloc(sizeof(World_obj*));
    door -> y_pos = 40;
    door -> x_pos = 0;
    door -> id    = "dd";

    return wd;
}
