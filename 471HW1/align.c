#include "align.h"

void init(CELL table[L1+1][L2+1], int g)
{
	int i = 1;
	
	table[0][0].score = 0;
	table[0][0].I = 0;
	table[0][0].S = 0;
	table[0][0].D = 0;
	table[0][0].parent = 'X';

	while (i < (L1+1))
	{
		table[i][0].score = table[i-1][0].score + g;
		table[i][0].I = table[i-1][0].I + g;
		table[i][0].S = -999;
		table[i][0].D = -999;
		table[i][0].parent = 'I';
		i++;
		
	}
	i = 1;
	while (i < (L2+1))
	{
		table[0][i].score = table[0][i-1].score + g;
		table[0][i].D = table[0][i-1].D + g;
		table[0][i].S = -999;
		table[0][i].I = -999;
		table[0][i].parent = 'D';
		i++;
	}
}

void print(CELL table[L1+1][L2+1])
{
	int i = 0;
	int j = 0;
	while (j < (L2+1))
	{
		while (i < (L1+1))
		{
			printf("[%d] ", table[i][j].score);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

int max3(int i, int j, int k)
{
	int max = 0;
	if ((i >= j) && (i >= k))
	{
		max = i;
	}
	else if ((j >= i) && (j >= k))
	{
		max = j;
	}
	else if ((k >= i) && (k >= j))
	{
		max = k;
	}
	else
	{
		printf("ERROR in max3 function\n");
	}
	return max;
}

void score(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2, int i, int j)
{
	table[i][j].I = table[i-1][j].score + g;
	table[i][j].D = table[i][j-1].score + g;
	if (s1[i-1] == s2[j-1])
	{
		table[i][j].S = table[i-1][j-1].score + m;
	}
	else if (s1[i-1] != s2[j-1])
	{
		table[i][j].S = table[i-1][j-1].score + mm;
	}
	else
	{
		printf("ERROR 1 in score function\n");
	}
	table[i][j].score = max3(table[i][j].S, table[i][j].D, table[i][j].I);
	if (table[i][j].score == table[i][j].S)
	{
		table[i][j].parent = 'S';
	}
	else if (table[i][j].score == table[i][j].D)
	{
		table[i][j].parent = 'D';
	}
	else if (table[i][j].score == table[i][j].I)
	{
		table[i][j].parent = 'I';
	}
	else
	{
		printf("ERROR 2 in score function\n");
	}
}

void fill(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2)
{
	int i = 1;
	int j = 1;
	while (j < (L2+1))
	{
		while (i < (L1+1))
		{
			score(table, m, mm, g, s1, s2, i, j);
			i++;
		}
		i = 1;
		j++;
	}
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void traceback(CELL table[L1+1][L2+1], char* s1, char* s2, char* a1, char* a2)
{
	int i = L1;
	int j = L2;
	while((i != 0) && (j != 0))
	{
		//printf("coordinates = [%d,%d]\n", i, j);
		if (table[i][j].parent == 'S')
		{
			append(a1, s1[i-1]);
			append(a2, s2[j-1]);
			i--;
			j--;
		}
		else if (table[i][j].parent == 'I')
		{
			append(a1, s1[i-1]);
			append(a2, '-');
			i--;
		}
		else if (table[i][j].parent == 'D')
		{
			append(a1, '-');
			append(a2, s2[j-1]);
			j--;
		}
		else if (table[i][j].parent == 'X')
		{
			printf("Origin Reached\n");
		}
		else
		{
			printf("ERROR in traceback function\n");
		}
	}
	strrev(a1);
	strrev(a2);
}

//local alignment scoring
void init2(CELL table[L1+1][L2+1], int g)
{
        int i = 1;

        table[0][0].score = 0;
        table[0][0].I = 0;
        table[0][0].S = 0;
        table[0][0].D = 0;
        table[0][0].parent = 'X';

        while (i < (L1+1))
        {
                table[i][0].score = 0;
                table[i][0].I = 0;
                table[i][0].S = -999;
                table[i][0].D = -999;
                table[i][0].parent = 'I';
                i++;

        }
        i = 1;
        while (i < (L2+1))
        {
                table[0][i].score = 0;
                table[0][i].D = 0;
                table[0][i].S = -999;
                table[0][i].I = -999;
                table[0][i].parent = 'D';
                i++;
        }
}

void score2(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2, int i, int j)
{
        table[i][j].I = table[i-1][j].score + g;
        table[i][j].D = table[i][j-1].score + g;
        if (s1[i-1] == s2[j-1])
        {
                table[i][j].S = table[i-1][j-1].score + m;
        }
        else if (s1[i-1] != s2[j-1])
        {
                table[i][j].S = table[i-1][j-1].score + mm;
        }
        else
        {
                printf("ERROR 1 in score2 function\n");
        }
        int score = max3(table[i][j].S, table[i][j].D, table[i][j].I);
	if (score > 0)
	{
		table[i][j].score = score;
	}
	else if (score <= 0)
	{
		table[i][j].score = 0;
	}
	else
	{
		printf("ERROR 3 in score2 function\n");
	}

        if (table[i][j].score == table[i][j].S)
        {
                table[i][j].parent = 'S';
        }
        else if (table[i][j].score == table[i][j].D)
        {
                table[i][j].parent = 'D';
        }
        else if (table[i][j].score == table[i][j].I)
        {
                table[i][j].parent = 'I';
        }
}

void fill2(CELL table[L1+1][L2+1], int m, int mm, int g, char* s1, char* s2)
{
        int i = 1;
        int j = 1;
        while (j < (L2+1))
        {
                while (i < (L1+1))
                {
                        score2(table, m, mm, g, s1, s2, i, j);
                        i++;
                }
                i = 1;
                j++;
        }
}

int findmax(CELL table[L1+1][L2+1])
{
	int max = -999;
	int i = 0;
	int j = 0;
	while (j < (L2+1))
	{
		while (i < (L1+1))
		{	
			if (max < table[i][j].score)
			{
				max = table[i][j].score;
			}
			i++;
		}
		j++;
		i=0;
	}
	return max;
}

void traceback2help(CELL table[L1+1][L2+1], char* s1, char* s2, char* a1, char* a2, int i, int j)
{
        while(table[i][j].score != 0)
        {
                //printf("coordinates = [%d,%d]\n", i, j);
                if (table[i][j].parent == 'S')
                {
                        append(a1, s1[i-1]);
                        append(a2, s2[j-1]);
                        i--;
                        j--;
                }
                else if (table[i][j].parent == 'I')
                {
                        append(a1, s1[i-1]);
                        append(a2, '-');
                        i--;
                }
                else if (table[i][j].parent == 'D')
                {
                        append(a1, '-');
                        append(a2, s2[j-1]);
                        j--;
                }
                else if (table[i][j].parent == 'X')
                {
                        printf("Origin Reached\n");
                }
                else
                {
                        printf("ERROR in traceback function\n");
                }
        }
        strrev(a1);
        strrev(a2);
}

void traceback2(CELL table[L1+1][L2+1], char* s1, char* s2, char* a1, char* a2, int max)
{
	int i = 1;
	int j = 1;
	int savei;
	int savej;
	while (j < (L2+1))
	{
		while (i < (L1+1))
		{
			if (table[i][j].score == max)
			{
				savei = i;
				savej = j;
			}
			i++;
		}
		j++;
		i=1;
	}
	//printf("saved coordinates = [%d,%d]\n", savei, savej);
	traceback2help(table, s1, s2, a1, a2, savei, savej);
	
}
