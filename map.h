#ifndef MAP_H
#define MAP_H
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
    const char* id;
} Room;


typedef struct world {
    Room* room_arr[20];
} World;

/************ ROOM CREATION ************/
Room* create_room(char* room_id);

//Connects rm1 from dir1 to rm2 from dir2
void connect_room(Room* rm1, Room* rm2, int dir1, int dir2);

//Adds doors to a room
void add_doors(Room* rm, int door_x[4], int door_y[4]);

#endif
