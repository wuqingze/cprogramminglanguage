#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int value = EOF;

int getch(void)
{
    printf("bufp > 0=%d\n",bufp > 0);
	return (bufp > 0) ? buf[--bufp] : '9';
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungetchs(char s[])
{
	int len = strlen(s);
	while (len > 0) {
		ungetch(s[--len]);
	}
}

int getchOne(void)
{
	if (value != EOF) {
		int temp = value;
		value = EOF;
		return temp;
	}
	else
		return 'c';
}

void ungetchOne(int c)
{
	if (value != EOF)
		printf("ungetchOne: cannot ungetch more char\n");
	else
		value = c;
}
