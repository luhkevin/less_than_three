#include "dialogue.h"

void create_dialogue_box() {
    int lines = 10, cols = 80, y = 0, x = 45;

    dialogue_win = newwin(lines, cols, y, x);
    box(dialogue_win, 0, 0);
    dialogue_pan = new_panel(dialogue_win);

    keypad(stdscr, false);
    keypad(dialogue_win, true);
    
    update_panels();
    doupdate();
}

void get_dialogue() {
    FILE* fp = fopen("dialogue/0-0", "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int c;
    int y = 1;

    if(fp == NULL) {
        exit(0);
    } else {
        //Print two lines of dialogue
        while((c = getch()) != 'e') {
            if((read = getline(&line, &len, fp)) != -1) mvwprintw(dialogue_win, y++, 1, "%s", line);
            wrefresh(dialogue_win);
        }
    }
    wclear(dialogue_win);
    wrefresh(dialogue_win);

    //wrefresh(game_win);
    keypad(stdscr, true);
    fclose(fp);
}
    
