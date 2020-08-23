#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *f = fopen("t", "a");
    char *line = "hello";
    char *ptr;
    char c;
    for(int i=0;i<100;i++){
        ptr = line;
        while((c=*ptr++) != '\0'){
            putc(c, f);
        }
        putc('\n', f);
    }
    return 0;
}
