#include "global.h"

void printtable(CELL table[x+1][y+1])
{
	int i = 0;
	int j = 0;
	while (i < (x+1))
	{
		while (j < (y+1))
		{
			printf("[");
			printf("%d", table[i][j].score);
			printf("] ");
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

void init(CELL table[x+1][y+1])
{
	table[0][0].score = 0;
	int i = 1;
	int j = 1;
	while (i < (x+1))
	{
		table[i][0].score = table[i-1][0].score + gapscore;
		table[i][0].direction = 3; 
		i++;
	}
	while(j < (y+1))
	{
		table[0][j].score = table[0][j-1].score + gapscore;
		table[0][j].direction = 2;
		j++;
	}
			
}

int triplemax(int S, int I, int D)
{
	int max = -10000;
	if (S >= I && S >= D)
	{
		max = S;
	}
	else if(I >= S && I >= D)
	{
		max = I;
	}
	else
	{
		max = D;
	}
	return max;
}

void maketable(CELL table[x+1][y+1], char* s1, char* s2)
{

	int up = 0;
	int left = 0;
	int diagonal = 0;

	int i = 1;
	int j = 1;
	while (i < (x+1))
	{
		while(j < (y+1))
		{
			if (s1[i-1] == s2[j-1])
			{
				diagonal = table[i-1][j-1].score + matchscore;
			}
			else
			{
				diagonal = table[i-1][j-1].score + mismatchscore;
			}
			left = table[i-1][j].score + gapscore;
			up = table[i][j-1].score + gapscore;
			table[i][j].score = triplemax(diagonal, left, up);
			if (table[i][j].score == diagonal)
			{
				table[i][j].direction = 1;
			}
			else if (table[i][j].score == left)
			{
				table[i][j].direction = 2;
			}
			else if (table[i][j].score == up)
			{
				table[i][j].direction = 3;
			}
			j++;
		}
		j = 1;
		i++;
	}
	
}

int retrace(CELL table[x+1][y+1], char* s1, char* s2, char* r1, char* r2)
{
	int maxi = 0;
	int maxj = 0;
	int max = -99999;
	int i = 0;
	int j = 0;
	while (i < (x+1))
	{
		while( j < (y+1))
		{
			if (table[i][j].score > max)
			{
				max = table[i][j].score;
				maxi = i;
				maxj = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (maxi != 0 || maxj != 0)
	{
		if (table[maxi][maxj].direction == 1)//diagonal
		{
			r1[i] = s1[maxi-1];
			r2[j] = s2[maxj-1];
			maxi--;
			maxj--;
		}
		else if (table[maxi][maxj].direction == 2) //left
		{
			r1[i] = '-';
			r2[j] = s2[maxj-1];
			maxj--;
		}
		else if (table[maxi][maxj].direction == 3) //up
		{
			r1[i] = s1[maxi-1];
			r2[j] = '-';
			maxi--;
		}
		i++;
		j++;
	}
	r1[i] = '\0';
	r2[j] = '\0';
	

	
	return max;
}
