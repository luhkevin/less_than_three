#ifndef INTERACT_H
#define INTERACT_H
/* Data structures to represent the interactive objects (doors, boxes, books, 
 * etc...) 
 * */

typedef struct object {
    //Name: door, box, book, wall, etc...
    char* id;

    int x_pos;
    int y_pos;

} World_obj;

#endif
