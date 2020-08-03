#include <stdio.h>

int main(){
    double d[] = {3.14, 3.15, 3.16};
    printf("d1:%f\n", *(&d[0]));
    printf("d1:%f\n", (&d[0]));
    //double d[] = {};
//    printf("len:%ld\n", sizeof(d)/sizeof(d[0]));
    printf("hello\n");
    for(int i=0; i<sizeof(d)/sizeof(d[0]); i++){
        printf("---%f", d[i]);
    }
    printf("\n");
}
