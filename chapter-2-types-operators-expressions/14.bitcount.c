#include <stdio.h>

int bitcount(unsigned);

main()
{
	//printf("255:%d\n", bitcount(255));
	printf("2:%d\n", bitcount(5));
//	printf("15:%d\n", bitcount(15));
//	printf("1:%d\n", bitcount(1));
//	printf("0:%d\n", bitcount(0));
//	printf("~0U:%d\n", bitcount(~0U));
}

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1){
		if (x & 1)
			b++;
    }

	return b;
}
