#include <stdio.h>

void printd(int n);

void main()
{
    printd(0x80000000);
    printf("\n");

    printd(-123456);
    printf("\n");
}

void printd(int n)
{
    int isMin = 0;
	if (n < 0) {
		printf("%c",'-');
        isMin = n == -n;
        if(isMin)
            n += 1;
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
    if(isMin){
    	printf("%c",n % 10 + 1 + '0');
    }
    else{
    	printf("%c",n % 10 + '0');
    }
}

