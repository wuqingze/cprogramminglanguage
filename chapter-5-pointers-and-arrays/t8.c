#include <stdio.h>

void f(int i);
void ff(void *i);

void f(int i){
    printf("int i:%d\n", i);
}

void ff(void *i){
    printf("hello\n");
}

void main(){
    int *i;
    i = 1;
//    ff(i);
}
