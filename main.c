#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#include "snake.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int score = 1;
    int x = 0, y = 0;
    int tab_x[MAXTAB], tab_y[MAXTAB];
    int max_y = 0, max_x = 0;
    int dir_x = 1, dir_y = 0;
    int rand_x = -1, rand_y = -1;
    int eaten = 1;
    int gameover = 0;

    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr,TRUE);
    keypad(stdscr, TRUE);
    mvprintw(y, x, "o");
    refresh();

    while(!gameover) {
        getmaxyx(stdscr, max_y, max_x);

        if (eaten){
            updaterandxy(&rand_x, &rand_y, max_x, max_y, &eaten);
        }
        updatexy(&x, &y, &dir_x, &dir_y, max_x, max_y);
        updateeaten(&eaten, x, y, rand_x, rand_y);
        updatetabs(tab_x, tab_y, &score, x, y, eaten);
        gameover = isgameover(x, y, tab_y, tab_x, max_x, max_y, score);

        clear();
        mvprintw(0, 0, "Your score : %d", score); 
        for (int i = 0; i < score; ++i)
        {
            mvprintw(tab_y[i], tab_x[i], "o");
        }
        mvprintw(tab_y[0], tab_x[0], "O");
        if (!eaten){
           mvprintw(rand_y, rand_x, "X"); 
        }

        refresh();
        usleep(DELAY);
    }

    clear();
    printgameover(score);
    endwin();
}