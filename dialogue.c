#include "dialogue.h"

WINDOW* create_dialogue_box() {
    int lines = 10, cols = 80, y = 0, x = 45;
    WINDOW* win;
    PANEL* pan;

    win = newwin(lines, cols, y, x);
    box(win, 0, 0);
    pan = new_panel(win);

    keypad(stdscr, false);
    keypad(win, true);
    
    update_panels();

    doupdate();
    
    return win;
}

void get_dialogue(WINDOW* win) {
    FILE* fp = fopen("dialogue/0-0", "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    if(fp == NULL) {
        exit(0);
    } else {
        //Print two lines of dialogue
        if((read = getline(&line, &len, fp)) != -1) mvwprintw(game_win, 10, 45, "%s", line);
        if((read = getline(&line, &len, fp)) != -1) mvwprintw(game_win, 11, 45, "%s", line);
    }
    wrefresh(game_win);
}
    
