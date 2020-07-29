#include <stdio.h>

int invert(int, int, int);

int _invert(int x, int p, int n);

main()
{
	int a = invert(255, 0, 4);
	printf("%d\n", a);

	int b = invert(0, 4, 4);
	printf("%d\n", b);
	
	int c = invert(15, 4, 4);
	printf("%d\n", c);

    test_00_invert();
}

int invert(int x, int p, int n)
{
	return x ^ (~(~0 << n) << p);
}

int _invert(int x, int p, int n){
    return x ^ (~(~0<<n) << p);
}

void test_00_invert(){
	int a = _invert(255, 0, 4);
	printf("%d\n", a);

	int b = _invert(0, 4, 4);
	printf("%d\n", b);
	
	int c = _invert(15, 4, 4);
	printf("%d\n", c);
}
