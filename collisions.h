#include "player.h"
#include "interact.h"

#ifndef COLLISIONS_H
#define COLLISIONS_H

/* Primitive collision library */

int check_nbd(int x1, int x2, int y1, int y2);
int collide_player(Player* p1, Player* p2);
int collide_object(Player* p,  World_obj* wo);

//Detects collision between any other object: NPC, walls, etc
//int collide_object(Player* p1, interact......);
//


#endif
