#include <stdio.h>
#include <assert.h> 
#include <limits.h> 

int g1();
void test_01_limit();

void main(){
//    short i1 = 127;
//    long i2 = 999999999999999L;
//    printf("%d\n", i1);
//    printf("%ld\n", i2);
//    assert( 1==g1());
//    printf("hello world\n");
    test_01_limit();
}

int g1(){
    return 1;
}

void test_01_limit(){
    printf("1. CHAR_BIT\t%d\n",   CHAR_BIT);
    printf("2. SCHAR_MIN\t%d\n",  SCHAR_MIN);
    printf("3. SCHAR_MAX\t%d\n",  SCHAR_MAX);
    printf("4. UCHAR_MAX\t%d\n",  UCHAR_MAX);
    printf("5. CHAR_MIN\t%d\n",   CHAR_MIN);
    printf("6. CHAR_MAX\t%d\n",   CHAR_MAX);
    printf("7. SHRT_MIN\t%d\n",   SHRT_MIN);
    printf("8. SHRT_MAX\t%d\n",   SHRT_MAX);
    printf("9. USHRT_MAX\t%d\n",  USHRT_MAX);
    printf("10. INT_MIN\t%d\n",   INT_MIN);
    printf("11. INT_MAX\t%d\n",   INT_MAX);
    printf("12. UINT_MAX\t%d\n",  UINT_MAX);
    printf("13. LONG_MIN\t%ld\n", LONG_MIN);
    printf("14. LONG_MAX\t%ld\n", LONG_MAX);
}
