#include <stdio.h>

struct p{
    int x;
    int y;
};

struct p copy(struct p *ptr);
struct p copy(struct p *ptr){
    struct p t;
    t.x = ptr->x+1;
    t.y = ptr->y+1;
    return t;
}

int main(){
    struct p p1  = {1,2};
    struct p p2 = copy(&p1);
    printf("p1.x:%d, p1.y:%d\n", p1.x, p1.y);
    printf("p2.x:%d, p2.y:%d\n", p2.x, p2.y);

    return 0;
}
