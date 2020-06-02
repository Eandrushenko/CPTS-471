#include "files.h"
#include "global.h"

void parameters(char* filename)
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

	matchscore = m;
	mismatchscore = mm;
	gapscore = h;
	continuedgap = g;
}
