#include <stdlib.h>
#include <stdio.h>

#define frand() ((double) rand()/ (RAND_MAX+1.0))

int main(){
    int i = rand();
    printf("i:%d\n", i);
    printf("rand_max:%d\n", RAND_MAX);
    printf("j:%f\n", j);
    return 0;
}
