#include <stdio.h>
#define MAXLEN 100

void main(){
    char *a[MAXLEN] = {
        "hello",
        "world",
        "wuqingze"
    };

    int i=0;
    while(*(a+i)){
        printf("%s\n", *(a+i));
        i += 1;
    }
}

