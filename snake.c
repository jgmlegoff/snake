#include "snake.h"

void updatexy(int* x, int* y, int* dir_x, int* dir_y, int max_x, int max_y){
    int next_x = 0, next_y = 0;
    int c = getch();
    switch(c){
        case KEY_UP:
            *dir_y = -1;
            *dir_x = 0;
            break;
        case KEY_DOWN:
            *dir_y = 1;
            *dir_x = 0;
            break;
        case KEY_RIGHT:
            *dir_y = 0;
            *dir_x = 1;
            break;
        case KEY_LEFT:
            *dir_y = 0;
            *dir_x = -1;
            break;
        case ERR:
            break;
    }

    *x += *dir_x;
    *y += *dir_y;
}

void updaterandxy(int* rand_x, int* rand_y, int max_x, int max_y, int* eaten){
    *rand_x = (rand() % (max_x - 1));
    *rand_y = (rand() % (max_y - 1));
    *eaten = 0;
}

void updateeaten(int* eaten, int x, int y, int rand_x, int rand_y){
    if (x==rand_x && y==rand_y){
        *eaten = 1;
    }
}

void updatetabs(int *tab_x, int *tab_y, int *score, int x, int y, int eaten){
    if (eaten){
        *score += 1;
    }
        
    for (int i = *score-1 ; i > 0 ; i--)
    {
        *(tab_x + i) = *(tab_x + i - 1);
        *(tab_y + i) = *(tab_y + i - 1);
    }
    *tab_x = x;
    *tab_y = y;

}

int isgameover(int x, int y, int *tab_y, int *tab_x, int max_x, int max_y, int score){
    for (int i = 1; i<score ; i++){
        if (*(tab_x+i) == x && *(tab_y+i) == y){
            return(1);
        }
    }
    if (x >= max_x || x<0) {
        return(1);
    }
    if (y >= max_y || y<0) {
        return(1);
    }
    return(0);

}

void printgameover(int score){
    mvprintw(0, 0, " #####");
    mvprintw(1, 0, "#     #   ##   #    # ######  ####  #    # ###### ##### ");
    mvprintw(2, 0, "#        #  #  ##  ## #      #    # #    # #      #    #");
    mvprintw(3, 0, "#  #### #    # # ## # #####  #    # #    # #####  #    #");
    mvprintw(4, 0, "#     # ###### #    # #      #    # #    # #      #####");
    mvprintw(5, 0, "#     # #    # #    # #      #    #  #  #  #      #   #");
    mvprintw(6, 0, " #####  #    # #    # ######  ####    ##   ###### #    #");
    mvprintw(7, 0, "Your score : %d", score); 
    mvprintw(8, 0, "You're about to quit."); 
    refresh();
    usleep(100*DELAY);
}