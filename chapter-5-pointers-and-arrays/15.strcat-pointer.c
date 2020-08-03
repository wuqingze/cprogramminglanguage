#include <stdio.h>

void _mystrcat(char *s, char *t);
void test00();
void test01();

int main()
{
    test01();
	return 0;
}

void test00(){
	void mystrcat(char*, char*);

	char s[100] = "Hello";
	char *t = ", World!";
	mystrcat(s, t);
	printf("%s\n", s);
}

void test01(){
	char s[100] = "Hello";
	char *t = ", World!";
	_mystrcat(s, t);
	printf("%s\n", s);
}

void _mystrcat(char *s, char *t){
	while (*s)
		s++;
    while((*s++ = *t++) != '\0')
        ;
}

void mystrcat(char *s, char *t)
{
	while (*s)
		s++;

	while ((*s++ = *t++))
		;
}

