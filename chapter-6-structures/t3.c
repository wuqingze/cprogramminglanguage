#include <stdio.h>
#include <ctype.h>

#define alen 100
#define NKEYS (sizeof keytab / sizeof keytab[0])
int main(int argc, char *argv[]){
    //char *data[alen] = {"hello", "world", "i", "am", "wuqingze"};
    //char *data[] = {"hello", "world", "i", "am", "wuqingze"};
    //char *data[alen] = {"hello", "world", "i", "am", "wuqingze"};
    char *data[] = {"hello", "world", "i", "am", "wuqingze"};

    printf("sizeof data:%ld\n", sizeof data);
    printf("sizeof data[0]:%ld\n", sizeof data[0]);

    int len = sizeof data / sizeof data[0];
    printf("len:%d\n", len);

    char *t[0];
    len = sizeof t / sizeof t[0];
    printf("len:%d\n", len);

    len = sizeof data / sizeof data[0];
    for(int i=0;i<len; i++){
        printf("i:%d, s:%s\n", i, data[i]);
    }

    return 0;
    char **ptr = data;
    while(*ptr != NULL){
        printf("%s\n", *ptr);
        ptr++;
        printf("---\n");
    }
    printf("end\n");
    return 0;
}
