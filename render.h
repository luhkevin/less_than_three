#include <curses.h>
#include "constants.h"
#include "player.h"
#include "rooms.h"

void render_room(Room* rm);
void render_player(Player* p);
void clear_player(Player* p);
