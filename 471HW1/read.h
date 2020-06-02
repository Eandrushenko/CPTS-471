#include "align.h"
#include <stdlib.h>

int matchscore;
int mismatchscore;
int gapscore;
int continuedgap;

void removeSpaces(char *str);
int read(char* filename, char* s1, char* s2);
int countnewlines(char* s);
void matchstring(char* ms, char* a1, char* a2);
void output(char* ms, char* a1, char* a2, int m, int mm, int h, int g, int max, char type);
int parameters(char* filename, int p);
