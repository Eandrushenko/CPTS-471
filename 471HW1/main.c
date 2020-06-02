#include "align.h"
int main(int argc, int *argv[])
{
	char type = argv[2][0];
	int filesize;
	//printf("argv[2] = %c\n", type);

	char s1[100000] = ""; //sequence 1
	char s2[100000] = ""; //sequence 2

	read(argv[1], s1, s2);
	removeSpaces(s1);
	removeSpaces(s2);
	//printf("%s\n", s1);
	//printf("newlines = %d\n", countnewlines(s1));
	//printf("%s\n", s2);
	//printf("newlines=%d\n", countnewlines(s2));

	L1 = strlen(s1);
	L2 = strlen(s2);
	//printf("length of L1 & L2 = %d & %d\n", L1, L2);

	char a1[1000000] = "";
	char a2[1000000]= "";


	int match = parameters(argv[3], 0);
	int mismatch = parameters(argv[3], 1);
	int h = parameters(argv[3], 2);
	int g = parameters(argv[3], 3);

	int max;
	CELL table[L1+1][L2+1];

	if (type == '0')
	{
		init(table, g);
		fill(table, match, mismatch, g, s1, s2);
		//print(table);
		traceback(table, s1, s2, a1, a2);
		max = table[L1][L2].score;
		//printf("max = %d\n", max);
		//printf("string1 = %s\n", a1);
		//printf("string2 = %s\n", a2);
	}
	else
	{
		init2(table, g);
		fill2(table, match, mismatch, g, s1, s2);
		//print(table);
		max = findmax(table);
		traceback2(table, s1, s2, a1, a2, max);
		//printf("max = %d\n", findmax(table));
		//printf("string1 = %s\n", a1);
		//printf("string2 = %s\n", a2);
	}

	char* ms[10000];
	matchstring(ms, a1, a2);
	//printf("matchstring\n\n\n");
	//printf("%s\n", a1);
	//printf("%s\n", ms);
	//printf("%s\n", a2);
	//printstrings(ms, a1, a2);
	output(ms, a1, a2, match, mismatch, h, g, max, type);
	return 0;
}
