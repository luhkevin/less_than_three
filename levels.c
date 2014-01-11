/*
 * This will generate all the rooms in a particular world.
 * I.e. load all of these rooms into memory.
 * 
 * TODO: Perhaps load into memory room-by-room, instead of
 * world-by-world
 *
 * "create_world" does initial malloc-ing
 * "create_rooms" creates the rooms
 * "create_connections" runs connect_room on the rooms
 *
 * TODO: But shouldn't these be in rooms.h?
 * "add_doors" adds the door positions
 * "add_objects" adds the interactive objects
 * "add_npcs" adds the npcs
 * ...
 * TODO: more to come?
 */

#include "world.h"

//TODO: Function pointers here? for "inheriting" the create_world function?
//Because they need to be different per world
//Same with rooms, for that matter
World* create_world(int world_id) {
    World* wd = malloc(sizeof(World*));
    wd -> world_id = world_id;

    //Connect rm0 to rm1 from the north
 //   connect_room(wd -> room_arr[0], wd -> room_arr[1], 0, 1);

    //Create a door...this should go in some room init file
    /*
    World_obj* door = malloc(sizeof(World_obj*));
    door -> y_pos = 40;
    door -> x_pos = 0;
    door -> id    = "dd";
*/
    return wd;
}

void create_rooms(World* wd, int n) {
    int i;
    char room_id[4];

    int world_id = wd -> world_id;
    for(i = 0; i < n; i++) {
        room_id[0] = world_id + '0';
        room_id[1] = '-';
        room_id[2] = i + '0';
        room_id[3] = '\0';
        wd -> room_arr[i] = init_room(room_id);
    }
}

void create_connections(Room* rm1, Room* rm2, Directions dir1, Directions dir2) {
    (rm1 -> directions[dir1]) = rm2;
    (rm2 -> directions[dir2]) = rm1;
}
