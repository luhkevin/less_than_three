#include <stdlib.h>
#include "map.h"

//Initializes all doors and directions to 0;
Room* create_room(char* room_id) {
    int i;

    Room* rm = malloc(sizeof(Room*));
    for(i = 0; i < 4; i++) {
        rm -> door_x[i] = 0;
        rm -> door_y[i] = 0;

        rm -> directions[i] = malloc(sizeof(Room*));
        rm -> directions[i] = 0;
    }

    rm -> id = room_id;
    return rm;
}
    
void connect_room(Room* rm1, Room* rm2, int dir1, int dir2) {
    (rm1 -> directions[dir1]) = rm2;
    (rm2 -> directions[dir2]) = rm1;
}

