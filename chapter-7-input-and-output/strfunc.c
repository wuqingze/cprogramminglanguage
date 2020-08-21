#include <stdio.h>
#include <string.h>

int main(){

    void test02();
    test02();
    return 0;

    void test01();
    test01();
    return 0;

    void test00();
    test00();
    return 0;
}

void test00(){
    char *s = "¼±¼±¼±";
    int len = 0;
    while(*s++ != '\0')
        len += 1;

    printf("len:%d\n", len);
    printf("*s size:%ld\n", sizeof *s);
    printf("s size:%ld\n", sizeof s);
}

void test01(){
    char *s = "hello world";
    char *t;
    strcat(s, t);
    printf("t-s:%ld", t-s);
}


void test02(){
    char str[2048];
    //char *str;
    strcpy (str,"these ");
    strcat (str,"strings ");
    strcat (str,"are ");
    strcat (str,"concatenated.");
    puts (str);
}
