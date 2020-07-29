#include <stdio.h>

unsigned rightrot(unsigned, unsigned);

unsigned _rightrot(unsigned, unsigned);

void test_00_rightrot();

void test_01_binary();

void test_02_();

unsigned mid = ~(~0U>>1);

void main()
{
	int a = rightrot(255, 32);
	printf("%d\n", a);

	int b = rightrot(1, 30);
	printf("%d\n", b);
    test_00_rightrot();
    test_01_binary();
    test_02_();
}

unsigned rightrot(unsigned x, unsigned n)
{
	while (n-- > 0) {
		if (x & 1 == 1) {
			x = (x >> 1) | ~(~0U >> 1);
		} else {
			x = x >> 1;
		}
	}

	return x;
}

unsigned _rightrot(unsigned x, unsigned n){
    while(n-- > 0){
        if(x & 1 == 1){
            x = mid | (x>>1);
        }else{
            x = x >> 1;
        }
    }
    return x;
}

void test_00_rightrot(){
	int a = _rightrot(255, 32);
	printf("%d\n", a);

	int b = _rightrot(1, 30);
	printf("%d\n", b);
}

void test_01_binary(){
    printf("%d\n", bitcount(-1));
}

int bitcount(int x)
{
	int b = 1;
	
	if (x == 0)
		b--;

	while (x &= (x-1))
		b++;


	return b;
}

void test_02_(){
    for(int i=0xffffffff;i<0x7ffffff;i++){
        printf("%d\t%d\n", ~i+1, ~(i-1));
    }
}
