#include "player.h"
#include "interact.h"

#ifndef COLLISIONS_H
#define COLLISIONS_H

/* Primitive collision library */
typedef enum {NORTH, EAST, SOUTH, WEST} Directions;

int check_nbd(int x1, int x2, int y1, int y2);
int collide_player(Player* p1, Player* p2);
int collide_object(Player* p,  World_obj* wo);

//TODO: Use the Directions enum everywhere...
int collide_walls(Player* p, Directions dir);

#endif
