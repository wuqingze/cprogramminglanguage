#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[]);
void _itoa(int n);
void test01();

int main()
{
    test01();
    return 0;
}

void test00(){

	char s[1024];
	int n = INT_MAX;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = -2147483647;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = -INT_MAX;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = -0;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

	n = 0;
	itoa(n, s);
	printf("s: %s, n: %d\n", s, n);

}

void test01(){
	int n = INT_MAX;
	_itoa(n);
	printf("\n");

	n = -2147483647;
	_itoa(n);
	printf("\n");

	n = -INT_MAX;
	_itoa(n);
	printf("\n");

	n = -0;
	_itoa(n);
	printf("\n");

	n = 0;
	_itoa(n);
	printf("\n");

}

void _itoa(int n){
    int isMin = 0;
    if(n<0){
        printf("-");
        if(n == -n){
            n += 1;
            isMin = 1;
        }
        n = -n;
    }
    if(n/10)
        _itoa(n /10);
    printf("%d", isMin?(n%10+1):(n%10));
}

void itoa(int n, char s[])
{
	if (n < 0) {
		s[0] = '-';
		n = -n;
	}
	if (n / 10)
		itoa(n / 10, s);
	
	int digits = 0;
	int t = n;
	while (t = t / 10)
		digits++;
	if (s[0] == '-')
		digits++;

	s[digits++] = n % 10 + '0';
	s[digits] = '\0';
}

