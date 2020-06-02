#include <stdio.h>
#include <string.h>

typedef struct DP_cell
{
	int score;
	int S; //Diagonal
	int D; //up
	int I; //Left
	char parent; //For Traceback Purposes
}CELL;

int L1; //Length of Sequence 1
int L2; //Length of Sequence 2

void init(CELL table[L1+1][L2+1], int g);
void print(CELL table[L1+1][L2+1]);
int max3(int i, int j, int k);
void score(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2, int i, int j);
void fill(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2);
void append(char* s, char c);
char *strrev(char *str);
void traceback(CELL table[L1+1][L2+1], char* s1, char* s2, char* a1, char* a2);
//local alignment
void init2(CELL table[L1+1][L2+1], int g);
void score2(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2, int i, int j);
void fill2(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2);
int findmax(CELL table[L1+1][L2+1]);
void traceback2help(CELL table[L1+1][L2+1], char* s1, char* s2, char* a1, char* a2, int i, int j);
void traceback2(CELL table[L1+1][L2+1], char* s1, char* s2, char* a1, char* a2, int max);
