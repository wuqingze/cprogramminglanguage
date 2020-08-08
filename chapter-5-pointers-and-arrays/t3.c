#include <stdio.h>

char *strs[] = {
    "apple",
    "google",
    "amazon",
    "facebook",
    "microsoft",
    ""
};

char **str1 = {
    "apple",
    "google",
    "amazon",
    "facebook",
    "microsoft",
    ""
};

void main(int argc, char *argv[]){
//    while( --argc > 0){
//        printf("%s%s", *++argv, (argc>1) ? " ": "");
//    }
//    printf("\n");
//    return 0;

    int i =0;
    while(strs[i]){
        printf("%s\n",  strs[i]);
        i += 1;
    }
}
