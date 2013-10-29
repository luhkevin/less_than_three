#include "world1.h"

World* create_world() {
    World* wd = malloc(sizeof(World*));

    wd -> room_arr[0] = create_room("0-0");
    wd -> room_arr[1] = create_room("0-1");
    wd -> room_arr[2] = create_room("0-2");
    wd -> room_arr[3] = create_room("0-3");
    wd -> room_arr[4] = create_room("0-4");

    //Connect rm0 to rm1 from the north
    connect_room(wd -> room_arr[0], wd -> room_arr[1], 0, 1);

    return wd;
}
