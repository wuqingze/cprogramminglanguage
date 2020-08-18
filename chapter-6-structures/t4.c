#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *_newstr(char *s){
    char *p = (char*) malloc(strlen(s));
    char *t = p;
    while(*t++ = *s++)
        ;
    return p;
}
char *mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);

	return p;
}

char *newstr(char* s){
    char* p = (char*) malloc(strlen(s));
    char* t = p;
    while(*t++ = *s++)
        ;
//    int len = strlen(s);
//    char *p = (char*) malloc(len);
//    for(int i=0; i<len; i++){
//        p[i] = s[i];
//    }
    return p;
}

int main(int argc, char* argv[]){
    char* s3 = "aldjf";
    char* s4 = _newstr(s3);
    printf("s3:%s, s4:%s\n", s3, s4);
    return 0;

    char *s1 ,*s2 = "hello world";
    return 0;
    char *s = "hello world";
    char *rs = newstr(s);
    printf("s:%s\n", s);
    printf("rs:%s\n", rs);
    return 0;


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

