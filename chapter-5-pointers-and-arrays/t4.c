#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int _getline(char *line, int max);
void test00();
char *strs[] = {
    "apple",
    "google",
    "amazon"
};
int clen = 3;

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    printf("argc:%d\n", argc);
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    while (--argc > 0 && (*++argv)[0] == '-'){
        printf("argv:%s\n", *argv);
        while (c = *++argv[0]) switch (c) {
                case 'x':
                    printf("case 'x'\n");
                    except = 1;
                    break;
                case 'n':
                    printf("case 'n'\n");
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
    }
    if (argc != 1){
        printf("Usage: find -x -n pattern\n");
    }
    else{
        printf("-------\n");
        while (_getline(line, MAXLINE) > 0) {
            printf("line:%s\n", line);
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("number:%ld:\n", lineno);
                printf("line---%s\n", line);
                found++;
            }
        }

    }
    return found;
}

void test00(){
    char line[MAXLINE];
    while (_getline(line, MAXLINE) >= 0) {
        printf("%s\n", line);
    }
}

int _getline(char *line, int max){
    if(clen >0){
        char *ptr = strs[--clen];
        while(*ptr){
            *line++ = *ptr++;
        }
        *line = '\0';
        return 1;
    }
    return -1;
}
