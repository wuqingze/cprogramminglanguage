#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 1024

void itob(int n, char s[], int b);
void itob2(int n, char s[], int b);
void reverse(char[]);
void test_00();
void _itob(int n, char s[], int b);
void test_01();

void main(){
//    test_00();
    test_01();
}

void test_00(){
	int n = 255;
	char s[MAX_LEN];
//	itob(n, s, 16);
//	printf("n: %d, s: %s\n", n, s);
//
//	n = INT_MAX;
//	itob(n, s, 16);
//	printf("n: %d, s: %s\n", n, s);
//
//	n = 2048;
//	itob(n, s, 2);
//	printf("n: %d, s: %s\n", n, s);
//
//	n = 2048;
//	itob(n, s, 8);
//	printf("n: %d, s: %s\n", n, s);
//
//	n = INT_MIN;
//	itob(n, s, 16);
//	printf("n: %d, s: %s\n", n, s);
//
//	n = INT_MIN;
//	itob(n, s, 10);
//	printf("n: %d, s: %s\n", n, s);

	n = 0x80000000;
	char ss[MAX_LEN];
	itob(n, ss, 2);
	printf("n: %d, ss: %s\n", n, ss);
}

void test_01(){
	int n = 255;
	char s[MAX_LEN];
	_itob(n, s, 16);
	printf("n: %d, s: %s\n", n, s);

	n = INT_MAX;
	_itob(n, s, 16);
	printf("n: %d, s: %s\n", n, s);

	n = 2048;
	_itob(n, s, 2);
	printf("n: %d, s: %s\n", n, s);

	n = 2048;
	_itob(n, s, 8);
	printf("n: %d, s: %s\n", n, s);

	n = INT_MIN;
	_itob(n, s, 16);
	printf("n: %d, s: %s\n", n, s);

	n = INT_MIN;
	_itob(n, s, 3);
	printf("n: %d, s: %s\n", n, s);

	n = INT_MIN;
	_itob(n, s, 2);
	printf("n: %d, s: %s\n", n, s);
}

void _itob(int n, char s[], int b){
    int i = 0;
    int sign = n;
    do{
        int t = abs(n % b);
        if(t<10){
            s[i++] = t+'0';
        }else{
            s[i++] = t - 10 +'a';
        }
    } while(n/=b);
    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void itob(int n, char s[], int b){
    printf("hello world-----------\n");
	int i;
	int sign = n;

	i = 0;
	do {
		char c;
		int m = abs(n % b);
		if (m < 10)
			c = m + '0';
		else 
			c = m - 10 + 'a';
		s[i++] = c;
	} while (n /= b);
	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
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

