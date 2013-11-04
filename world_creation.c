#include "world.h"

World* init_world_0() {
    /* World level */
    World* wd = create_world(0);

    //CREATE ROOMS AND THEIR CONNECTIONS
    create_rooms(wd, 5);
    create_connections(wd -> room_arr[0], wd -> room_arr[1], 0, 1);

    /* Room level */
    //ADD DOORS TO EACH ROOM


    return wd;
}

/*
World* init_world1() {
    World* wd = create_world(1);
    create_rooms(wd, 10);
    create_connections(wd -> room_arr[0], wd -> room_arr[1], 0, 1);

    return wd;
}
*/
