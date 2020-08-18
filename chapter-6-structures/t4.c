#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);

	return p;
}

int main(int argc, char* argv[]){

    char *s = "hello world";



    char* ts = (char*) malloc(strlen(s));
    strcpy(ts, s);
    printf("s:%s\n", s);
    printf("ts:%s\n", ts);
    return 0;

    int len = strlen(s);
    char *p = (char *) malloc(len);
    char *pp = p;

 //   for(int i=0; i<len; i++){
 //       *p = s[i];
 //       p ++;
 //   }
    for(int i=0; i<len; i++){
        p[i] = s[i];
    }
   
    printf("%s\n", s);
    printf("--p value:%s\n", pp);
    free(pp);
    printf("--p value:%s\n", pp);
    printf("sizeof s:%ld\n", sizeof s);
    printf("%s size:%ld\n", s, strlen(s));
    return 0;
}

