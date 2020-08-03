#include <stdio.h>

int main()
{
	void mystrcpy(char*, char*);

	char t[] = "Hello, World!";
	char s[100];
	mystrcpy(s, t);
	printf("%s\n", s);


    char *ptrt = t;
    while(*ptrt != '\0'){
        printf("%c", *ptrt++);
    }
    printf("\n");

	return 0;
}

void mystrcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

