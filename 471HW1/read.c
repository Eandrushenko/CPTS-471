#include "read.h"
void removeSpaces(char *str) 
{ 
    // To keep track of non-space character count 
    int count = 0;
    int i = 0; 
  
    // Traverse the given string. If current character 
    // is not space, then place it at index 'count++' 
    for (i = 0; str[i]; i++) 
        if (str[i] != '\n' && str[i] != ' ') 
            str[count++] = str[i]; // here count is 
                                   // incremented 
    str[count] = '\0'; 
} 

int read(char* filename, char* s1, char* s2)
{
	FILE* fp;
	char buffer[10000];
	fp = fopen(filename, "r");
	int count = 0;
	while(fgets(buffer, 10000, (FILE*) fp))
	{
		if (buffer[0] == '>')
		{
			count++;
		}
		else if (count == 1)
		{
			strcat(s1, buffer);
		}
		else if (count == 2)
		{
			strcat(s2, buffer);
		}
	}
	fclose(fp);
}

int countnewlines(char* s)
{
	int len = strlen(s);
	int i = 0;
	int count = 0;
	while (i < len)
	{
		if (s[i] == '\n')
		{
			count++;
		}
		i++;
	}
	return count;
}

void matchstring(char* ms, char* a1, char* a2)
{
	int i = 0;
	int len = strlen(a1);
	while (i < len)
	{
		if (a1[i] == a2[i])
		{
			ms[i] = '|';
		}
		else if (a1[i] != a2[i])
		{
			ms[i] = ' ';
		}
		else
		{
			printf("ERROR in matchstring function");
		}
		i++;
	}
}

void printstrings(char* ms, char* a1, char* a2)
{
	int count1 = 0;
	int count2 = 0;

	int i = 0;
	int j = 0;
	while (j < strlen(ms))
	{
		printf("s1  %06d    ", count1 + 1);
		i = 0;
		while (i < 59)
		{
			printf("%c", a1[i]);
			if (a1[i] != '-')
			{
				count1++;
			}
			i++;
		}
		printf("  %06d\n              ", count1 + 1);
		i = 0;
		while (i < 59)
		{
			printf("%c", ms[i]);
			i++;
			j++;
		}
		printf("\n");
		i = 0;
		printf("s2  %06d    ", count2 + 1);
		while (i < 59)
		{
			printf("%c", a2[i]);
			if (a2[i] != '-')
			{
				count2++;
			}
			i++;
		}
		printf("  %06d\n\n", count2 + 1);
	}
}

void output(char* ms, char* a1, char* a2, int m, int mm, int h, int g, int max, char type)
{
	printf("Scores:    match = %d, mismatch = %d, h = %d, g = %d\n\n", m, mm, h, g);
	int i = 0;
	int b1 = 0; //length of a1
	int b2 = 0; //length of a2
	while (i < strlen(a1))
	{
		if (a1[i] != '-')
		{
			b1++;
		}
		i++;
	}
	i = 0;	
	while (i < strlen(a2))
	{
		if (a2[i] != '-')
		{
			b2++;
		}
		i++;
	}
	printf("Sequence 1 = \"s1\", length = %d characters\n", b1);
	printf("Sequence 2 = \"s2\", length = %d characters\n\n", b2);

	printstrings(ms, a1, a2);
	printf("\n\n");
	printf("Report:\n\n");
	if (type == '0')
	{
		printf("Global optimal score = %d\n\n", max);
	}
	else
	{
		printf("Local optimal score = %d\n\n", max);
	}
	char statstring[10000] = "";
	i = 0;
	while(i < strlen(a1))
	{
		if (a1[i] == a2[i])
		{
			statstring[i] = '|';
		}
		else if (a1[i] == '-' || a2[i] == '-')
		{
			statstring[i] = '-';
		}
		else if (a1[i] != a2[i])
		{
			statstring[i] = 'X';
		}
		else
		{
			printf("ERROR in output function");
		}
		i++;
	}
	i = 0;
	int mcount = 0;
	int mmcount = 0;
	int gcount = 0;
	int ogcount = 0;
	while (i < strlen(statstring))
	{
		if (statstring[i] == '|')
		{
			mcount++;
		}
		else if (statstring[i] == 'X')
		{
			mmcount++;
		}
		else if (statstring[i] == '-')
		{
			gcount++;
			if (statstring[i-1] != '-')
			{
				ogcount++;
			}
		}
		i++;
	}
	printf("Number of: matches = %d, mismatches = %d, gaps = %d, opening gaps = %d\n\n", mcount, mmcount, gcount, ogcount); 
	double id = mcount;
	double gs = gcount;
	id = id/(strlen(a1));
	gs = gs/(strlen(a1));
	printf("Identities = %d/%d (%f%), Gaps = %d/%d (%f%)\n\n", mcount, strlen(a1), id*100, gcount, strlen(a1), gs*100);
}

int parameters(char* filename, int p)
{
        char buff[500];
        int m = 0;
        int mm = 0;
        int h = 0;
        int g = 0;

        FILE *f;
        f = fopen(filename, "r");
        fscanf(f,"%s", &buff);
        fscanf(f,"%d", &m);
        fscanf(f,"%s", &buff);
        fscanf(f,"%d", &mm);
        fscanf(f,"%s", &buff);
        fscanf(f,"%d", &h);
        fscanf(f,"%s", &buff);
        fscanf(f,"%d", &g);

        fclose(f);

	if (p == 0)
	{
		return m;
	}
	else if (p == 1)
	{
		return mm;
	}
	else if (p == 2)
	{
		return h;
	}
	else
	{
		return g;
	}
}

