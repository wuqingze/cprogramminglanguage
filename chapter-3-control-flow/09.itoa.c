#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char[]);
void _itoa(int n, char s[]);
void test_00();

void main()
{
	int a = 0;
	char s[11];

	itoa(a, s);
	printf("%s\n", s);

	a = INT_MIN;
	itoa(a, s);
	printf("%s\n", s);

	a = INT_MAX;
	itoa(a, s);
	printf("%s\n", s);

    test_00();
}

void test_00(){
	printf("---------------------test_00\n");
	int a = 0;
	char s[11];

	_itoa(a, s);
	printf("%s\n", s);

	a = INT_MIN;
	_itoa(a, s);
	printf("%s\n", s);

	a = INT_MAX;
	_itoa(a, s);
	printf("%s\n", s);

	a = -1;
	_itoa(a, s);
	printf("%s\n", s);
}

void _itoa(int n, char s[]){

    int i = 0;
    int isNegative = n < 0;
    int isMin = n !=0 && n == -n;

    if(isNegative){
        if(isMin){
            n += 1;
        }
        n = 0 - n;
    }

    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) != 0);

    if(isNegative){
        if(isMin){
            s[0] += 1;
        }
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void itoa(int n, char s[])
{
	int i, sign;
	int preN = n;
	int nIsMinNagetive = n != 0 && n == -n;
	if ((sign = n) < 0) {
		if (nIsMinNagetive) {
			n += 1;
			n = -n;
		} else {
			n = -n;
		}
	}

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);

	if (nIsMinNagetive)
		s[strlen(s) - 1] += 1;
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
