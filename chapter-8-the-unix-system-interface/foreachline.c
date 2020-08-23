#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *f = fopen("t", "r");

    char *line = (char *) malloc(20);
    char c;
    char *ptr = line;
    int count = 0;
    while((c=fgetc(f)) != EOF){
        if(c != '\n'){
            *ptr++ = c;
            continue;
        }else{
            *ptr = '\0';
            ptr = line;
        }
        count += 1;
        printf("%d, %s\n",count, line);
    }

    return 0;
}
