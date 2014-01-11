#include "world.h"
#include "world_creation.h"

World* init_world_0() {
    /* World level */
    World* wd = create_world(0);

    //CREATE ROOMS AND THEIR CONNECTIONS
    create_rooms(wd, 5);
    create_connections(wd -> room_arr[0], wd -> room_arr[1], NORTH, SOUTH);

    /* Room level */
    World_obj* door = malloc(sizeof(World_obj*));
    door -> id = "dd";
   
    //ADD DOORS TO EACH ROOM
    int door_x[4] = {1, GAMEWIN_WIDTH/2, GAMEWIN_WIDTH - 1, GAMEWIN_WIDTH/2};
    int door_y[4] = {GAMEWIN_HEIGHT/2, 1, GAMEWIN_HEIGHT/2, GAMEWIN_HEIGHT - 1};

    add_doors(wd -> room_arr[0], door_x, door_y); 

    return wd;
}

/*
World* init_world1() {
    World* wd = create_world(1);
    create_rooms(wd, 10);
    create_connections(wd -> room_arr[0], wd -> room_arr[1], 0, 1);

    //world -> room_arr[1] -> door_x[0] = 5;
    //world -> room_arr[1] -> door_y[0] = 5;
    return wd;
}
*/
