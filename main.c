#include <curses.h>

//TODO: Inventory items will be implemented with a stack
//Only have a cash field for now
typedef struct Inventory {
    int cash;
} inventory;

typedef struct Player {
    int x_pos;
    int y_pos;
    
    //Another struct that holds the player's inventory
    inventory* inv;

    //Skills/stats i will be stored in stats[i], with right hand values from 0 - 10
    int stats[5];
} player;

int main() {
    int i, c;
    //Menu window...TODO: This should be a panel/menu.

    //Initialize player '3'
    player* three;
    inventory* three_inv;

    initscr();

    //Start 3 in the middle of the screen
    three -> x_pos = COLS / 2;
    three -> y_pos = LINES / 2;
    three -> inv   = three_inv;
    for(i = 0; i < 5; i++) {
        three -> stats[i] = 0;
    }

    keypad(stdscr, TRUE);
    noecho();
    cbreak();

    curs_set(0); //Don't show cursor
    start_color(); 
    init_pair(1, COLOR_RED, COLOR_GREEN);

    //getmaxyx(stdscr, row, col); //updates row col to max x, y of stdscr
    attron(COLOR_PAIR(1));
    mvprintw(three -> y_pos, three -> x_pos , "%c", '3');
    attroff(COLOR_PAIR(1));

    //Main game loop
    while(c != 'q') {
        c = getch();

        attron(COLOR_PAIR(1));
        switch(c) {
            case KEY_UP:
                clear();
                mvprintw(--(three -> y_pos), three -> x_pos, "%c", '3');
                refresh();
                break;
            case KEY_DOWN:
                clear();
                mvprintw(++(three -> y_pos), three -> x_pos, "%c", '3');
                refresh();
                break;
            case KEY_RIGHT:
                clear();
                mvprintw(three -> y_pos, ++(three -> x_pos), "%c", '3');
                refresh();
                break;
            case KEY_LEFT:
                clear();
                mvprintw(three -> y_pos, --(three -> x_pos), "%c", '3');
                refresh();
                break;
            case KEY_F(1):
                //menu
                break;
            default:
                break;
        }
        attroff(COLOR_PAIR(1));
    }

    refresh();
    endwin();
    return 0;
}

