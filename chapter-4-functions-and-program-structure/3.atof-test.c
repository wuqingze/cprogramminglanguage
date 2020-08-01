#include <stdio.h>

#define MAXLINE 100
void get_line(char line[]);

// compile with atof.c, mygetline.c
int main()
{
	double sum, atof(char []);
	char line[MAXLINE];
	int mygetline(char line[], int max);

	sum = 0;
//	while (mygetline(line, MAXLINE) > 0)
//		printf("\t%g\n", sum += atof(line));
//
    get_line(line);
    printf("\t%g\n", sum += atof(line));
	return 0;
}

void get_line(char line[]){
    char t[] = "123.45e-6";
    for(int i=0;t[i] != '\0'; i++)
        line[i] = t[i];
}
