#include "world.h"

void init_world0() {
    World* wd = create_world(0);
    create_rooms(wd, 5);
    create_connections(wd -> room_arr[0], wd -> room_arr[1], 0, 1);
}

void init_world1() {
    World* wd = create_world(1);
    create_rooms(wd, 10);
    create_connections(wd -> room_arr[0], wd -> room_arr[1], 0, 1);
}
