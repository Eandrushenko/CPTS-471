#include <stdio.h>
#include <string.h>

int x; //string length 1
int y; //string length 2
int matchscore;
int mismatchscore;
int gapscore;
int continuedgap;

typedef struct cell
{
        int score;
        int direction;
}CELL;


void printtable(CELL table[x + 1][y + 1]);
void init(CELL table[x+1][y+1]);
void maketable(CELL table[x+1][y+1], char* s1, char* s2);
int triplemax(int S, int I, int D);
int retrace(CELL table[x+1][y+1], char* s1, char* s2, char* r1, char* r2);
