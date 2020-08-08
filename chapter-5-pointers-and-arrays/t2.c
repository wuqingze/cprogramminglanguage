#include <stdio.h>
#include <string.h>

int main(){
    char *strs[] = {"hello world", "wuqingze", "what do you think of trump", "hhahha"};
//    while(*strs){
//        printf("%s\n", *strs);
//        strs ++;
//    }
    for(int i=0; i<3; i++){
        printf("%s\n", *(strs+i));
    }

    char *t = "hello";
    printf("strlen=%d", strlen(t));
    return 0;
}
