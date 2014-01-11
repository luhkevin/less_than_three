#include <curses.h>
#include "globals.h"
#include "player.h"
#include "rooms.h"

#ifndef RENDER_H
#define RENDER_H

void render_room(Room* rm);
void render_player(Player* p);
void clear_player(Player* p);

#endif
