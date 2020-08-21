#include <stdio.h>

int main()
{
	double sum, v;

	sum = 0;
	while (scanf("%f", &v) == 1){
        printf("v:%f\n", v);
		printf("\t%.2f\n", sum += v);
    }
	return 0;
}

