#include <stdio.h>

void swap(int *px, int *py);
void _swap(int px, int py);

int main()
{
    int x = 1,y=2;
    swap(&x, &y);
    printf("--------x=%d,y=%d\n", x, y);
    x = 1,y=2;
    _swap(x,y);
    printf("--------x=%d,y=%d\n", x, y);
}

void swap(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

void _swap(int px, int py)
{
	int temp;

	temp = px;
	px = py;
	py = temp;
}
