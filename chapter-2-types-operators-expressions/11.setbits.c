#include <stdio.h>

int setbits(int, int, int, int);

int invert(int x, int p, int n);

void test_00_setbits();

main()
{
	int a = setbits(255, 0, 4, 0);
	printf("%d\n", a);

	int b = setbits(1, 1, 3, 4);
	printf("%d\n", b);

	int c = setbits(218, 2, 4, 9);
	printf("%d\n", c);

    test_00_setbits();
}

int setbits(int x, int p, int n, int y)
{
	x = x & (~((~(~0 << n)) << p));
	y = (y & (~(~0 << n))) << p;

	return x | y;
}

void test_00_setbits(){

	int a = _setbits(255, 0, 4, 0);
	printf("%d\n", a);

	int b = _setbits(1, 1, 3, 4);
	printf("%d\n", b);

	int c = _setbits(218, 2, 4, 9);
	printf("%d\n", c);
}

int _setbits(int x, int p, int n, int y){
    y = (y &  ~(~0<<n))<<p;
    x = x & ~(~( ~0 << n) << p);
    return x | y;
}

int invert(int x, int p, int n){
    return 0;
}
