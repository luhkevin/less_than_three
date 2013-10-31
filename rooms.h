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


/************ ROOM CREATION ************/
Room* init_room(char* room_id);

//Adds doors to a room
void add_doors(Room* rm, int door_x[4], int door_y[4]);

//Adds interactive objects
void add_objects(Room* rm);

//Adds the npcs
void add_npcs(Room* rm);

//Adds the walls/borders
void add_walls(Room* rm);

//Adds the animations
void add_animations(Room* rm);

#endif
