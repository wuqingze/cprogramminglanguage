#include <stdio.h>

int strlen(char*);

int main()
{

	char array[100];
    array[0] = 'c';
	char *ptr = "Hello";

	int l = strlen("hello, world");
	printf("hello world len:%d\n", l);

	l = strlen(array);
	printf("array len:%d\n", l);

	l = strlen(ptr);
	printf("ptr len:%d\n", l);
	printf("ptr len:%ld\n", sizeof(ptr));
    ptr = "kjkdjf";
    for(int i=0;i<sizeof(ptr); i++){
        printf("i=%d, c=%c\n", i, *(ptr+i));
    }

    return 0;
}

int strlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;

	return n;
}
