#include <stdio.h>

int main(){
    int i=0, x=0, y=0;
    do{
        ++i;
        if(i%2 !=0){
            x = x+i;
            i ++;
        }
        y = y+i++;

        printf("-----i=%d,x=%d,y=%d\n",i, x,y);
    }while(i<=7);
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
