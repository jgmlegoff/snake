#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#define DELAY 50000
#define MAXTAB 1000

void updatexy(int* x, int* y, int* dir_x, int* dir_y, int max_x, int max_y);
void updaterandxy(int* rand_x, int* rand_y, int max_x, int max_y, int* eaten);
void updateeaten(int* eaten, int x, int y, int rand_x, int rand_y);
void updatetabs(int *tab_x, int *tab_y, int *score, int x, int y, int eaten);
int isgameover(int x, int y, int *tab_y, int *tab_x, int max_x, int max_y, int score);
void printgameover(int score);

typedef struct Coord Coord;
struct Coord
{
    int x;
    int y;
};