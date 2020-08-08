#include <stdio.h>

char *strs[] = {
    "apple",
    "google",
    "amazon",
    "facebook",
    "microsoft",
    ""
};

void main(int argc, char *argv[]){
    char *ptr;
    int i=0;
    while(*(strs+i)){
        printf("--%s\n", *(strs+i));
        i += 1;
    }

    //while(*strs){
    //    printf("%s\n", **strs);
 
    char *strs[] = {
        "apple",
        "google",
        "amazon",
        "facebook",
        "microsoft",
        ""
    };

   //}
    printf("%s\n", *strs);
    printf("%s\n", *(strs+1));
    printf("%s\n", *(strs+2));
    printf("%s\n", *(strs+3));
    printf("%s\n", *(strs+4));
    printf("%d\n", strs);
    printf("%d\n", strs+1);
    printf("%d\n", strs+2);
    printf("%d\n", strs+3);
    printf("%s\n", *(strs+1));
}
