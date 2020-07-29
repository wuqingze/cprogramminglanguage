#include <stdio.h>
#define LEN 10
void main()
{
	int c, i, nwhite, nother;
	int ndigit[LEN];

	nwhite = nother = 0;
	for (i = 0; i < LEN; ++i)
		ndigit[i] = 0;


//    while ((c = getchar()) != EOF)
   i = 100;
	while (i-->0){
        c = '8';
		if (c >= '0' && c <= '9'){
			++ndigit[c-'0'];
        }
		else if (c== ' ' || c == '\n' || c == '\t'){
			++nwhite;
        }
		else{
			++nother;
        }
    }

	printf("digits = ");
	for (i = 0; i < LEN; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n",
		nwhite, nother);
}
