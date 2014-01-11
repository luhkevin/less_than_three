#ifndef INTERACT_H
#define INTERACT_H
/* Data structures to represent the interactive objects (doors, boxes, books, 
 * etc...) 
 * */
enum object_state {UNTOUCHED, TOUCHED};

typedef struct object {
    //Name: door, box, book, wall, etc...
    char* id;

    int x_pos;
    int y_pos;

    enum object_state state;

} World_obj;

#endif
