#include <stdio.h>
#include <string.h>
#include <time.h>
#include "6.alloc.c"

#define MAXLINES 50000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int _readlines(char *lineptr[], int maxlines);
void test00();
void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();
int _mygetline(char *s, int lim);
void qsort(char *lineptr[], int left, int right);
void _strcpy(char *p, char *line);
void _qsort(char v[], int left, int right);
int partition(char v[], int left, int right);
void _swap(char *v, int i, int j);
void swap(char *v[], int i, int j);
void __qsort(char v[], int left, int right);
void test06();
void _qsortstr(char *v[], int left, int right);
void strswap(char *v[], int i, int j);
void printarr(char *a[]);

char *strs[] = {
    "apple1",
    "apple5",
    "apple2",
    "apple4",
    "apple3",
    ""
};


char *strs1[] = {
    "apple",
    "google",
    "amazon",
    "facebook",
    "microsoft",
    ""
};

int clen = 5;
int si = 0;

int main()
{
    test07();
	return 0;
}

void test00(){
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		//writelines(lineptr, nlines);
	} else {
		printf("error: input too big to sort\n");
	}
}

void test01(){
	int nlines;
	if ((nlines = _readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
        //int i=0;
        //while(*(lineptr+i)){
        //    printf("lineptr %d: %s\n", i, *(lineptr+i));
        //    i+=1;
        //}
	} else {
		printf("error: input too big to sort\n");
	}
}

void test02(){
    char s[MAXLEN];
    _mygetline(s, 10);
    printf("---%s\n", s);
}


int mygetline(char *, int);
char *alloc(int);

int _readlines(char *lineptr[], int maxlines){

	clock_t start, finish;
	start = clock();

	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = _mygetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
            //*(line+len) = '\0';
//            printf("p address:%d\n", &p);
		    _strcpy(p, line);
			lineptr[nlines++] = p;
		}

	finish = clock();
	printf("alloc: %f\n", ((double)(finish - start)) / CLOCKS_PER_SEC);
	return nlines;
}

int readlines(char *lineptr[], int maxlines)
{
	clock_t start, finish;
	start = clock();

	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}

	finish = clock();
	printf("alloc: %f\n", ((double)(finish - start)) / CLOCKS_PER_SEC);
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

int mygetline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*t++ = c;

	if (c == '\n')
		*t++ = c;

	*t = '\0';
	return t - s;
}

int _mygetline(char *s, int lim){
    if(si<clen){

        char *ptr = *(strs+si);
        char *t = s;
        while(*ptr){
            *t++ = *ptr++;
        }
        *t = '\0';
        si += 1;
        return t-s+1;
    }
    return 0;
}

void _qsort(char v[], int left, int right){
//    printf("value:%s, left:%d, right:%d\n", v, left, right);
    if(left >= right){
        return;
    }

    int index = partition(v, left, right);
//    printf("value:%s, left:%d, right:%d, index:%d\n", v, left, right, index);
    _qsort(v, left, index-1);
    _qsort(v, index+1, right);
}

void __qsort(char v[], int left, int right){
    if(v == NULL || left >= right){
        return;
    }

    int i = left -1;
    char gap = v[right];
    int j = left;
    while(j<=right){
        if(v[j] <= gap){
            i += 1;
            _swap(v, i, j);
        }
        j += 1;
    }
    __qsort(v, left , i-1);
    __qsort(v, i+1, right);
}

void _qsortstr(char *v[], int left, int right){
   if(v == NULL || left >= right){
       return;
   }

   int i = left -1;
   char *gap = v[right];
   int j = left;
   while(j<=right){
       if(strcmp( v[j], gap) <=0 ){
           i += 1;
           strswap(v, i, j);
       }
       j += 1;
   }
   _qsortstr(v, left, i-1);
   _qsortstr(v, i+1, right);
}

int partition(char v[], int left, int right){
    int i = left -1;
    char x = v[right];
    int j = left;
    while(j<=right){
        if(v[j] <= x){
            i += 1;
            _swap(v, i, j);
        }
        j += 1;
    }
    return i;
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void _swap(char *v, int i, int j){
    char t ;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void _strcpy(char *p, char *line){
    while(*p++ = *line++)
        ;
    *p = '\0';
}

void strswap(char *v[], int i, int j){
    char *t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void test03(){
    char a[] ={'e', 'f', 'g', 'a', 'b', 'c', 'd'};
    void _swap(char *v, int i, int j);
    _swap(a, 0, 6);
    printf("%s\n", a);
}

void test04(){
    char a[] ={'e', 'f', 'g', 'a', 'b', 'c', 'd'};
    printf("-------%s\n", a);
    int i = partition(a, 0, sizeof(a)-1);
    printf("size:%ld\n", sizeof(a));
    printf("a str:%s\n", a);
    printf("i :%d\n", i);
}


void test05(){
    char a[] = {'e', 'f', 'g', 'a', 'b', 'c', 'd'};
    printf("-------%s\n", a);
    _qsort(a, 0, sizeof(a)-1);
    printf("-------%s\n", a);
}

void test06(){
    //char a[] = {'e', 'f', 'g', 'a', 'b', 'c', 'd'};
    //char a[] = {'e'};
    //char a[] = {'a', 'b', 'c'};
    char a[] = {'c', 'b', 'a'};
    //char a[] = {};
    printf("-------%s\n", a);
    __qsort(a, 0, sizeof(a)-1);
    printf("-------%s\n", a);
}


void test07(){
    printf("-------------\n");
    char *a[MAXLINES] = {
        "hello3",
        "hello2",
        "hello1",
    };
    char **ptr = a;
    while(*ptr){
        printf("--%s\n", *ptr++);
    }

    //printarr(a);
    printf("-------------\n");
    _qsortstr(a, 0, 2);
    printarr(a);
}

void test08(){
    char *a[MAXLINES] = {
        "hello",
        "world",
        "wuqingze"
    };
    printarr(a);
}

void printarr(char *a[]){
    while(*a){
        printf("%s\n", *a++);
    }
}
