#include "global.h"


int main(int argc, char *argv[])
{
	char config[50];
	strcpy(config, argv[3]);

	parameters(config);

	printf("%d\n", sizeof(config));
	char* s1 = "CATTCAC";
	char* s2 = "CTCGCAGC";
	x = strlen(s1);
	y = strlen(s2);

	int z = triplemax(x, y, -1);
	char r1[z + 50];
	char r2[z + 50];

	CELL DP_table[x + 1][y + 1];

	init(DP_table);
	maketable(DP_table, s1, s2);
	printtable(DP_table);

	int test = 0;
	test = retrace(DP_table, s1, s2, r1, r2);
	printf("max: %d\n", test);
	printf("r1 = %s\n", r1);
	printf("r2 = %s\n", r2);
	
	return 0;
}
