#include <curses.h>

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

typedef struct World {
    Room* room_arr[20];
} world;


typedef struct Room {
    //Doors only need an (x, y) position, as they will have constant length
    //(door_x[i], door_y[i]) is the (x, y) position of the i-th door
    int door_x[];
    int door_y[];

    //0: north, 1: south, 2: east, 3: west
    Room* rooms[];
} room;



/************ ROOM CREATION ************/
room create_room(int door_x[], int door_y[], Room* rooms[]);

//Connects rm1 from dir1 to rm2 from dir2
void connect_room(Room* rm1, Room* rm2, int dir1, int direction_rm2);

