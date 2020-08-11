#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int _readlines(char *lineptr, int x);
void qsort(void *lineptr[], int left, int right,
			int (*comp)(void *, void *));

int numcmp(const char *, const char *);

char *a[] = {
    "hello1",
    "hello2",
    "hello3"

};
int clen = 3;
// gcc 38.pointers-to-functions.c numcmp.c readlines-writelines.c 6.alloc.c
int main(int argc, char *argv[])
{

    char *cc;
    printf("-----\n");
    while(_readlines(cc, 0)>=0){
        printf("--%s\n", cc);
    }
    return 0;

	int nlines;
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **) lineptr, 0, nlines-1,
			(int (*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right,
			int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int _readlines(char *lineptr, int m){
    printf("clen:%d\n", clen);
    if(clen<=0){
        return -1;
    }
    clen -= 1;
    char *ptr = a[clen];
    int i = 0;
    *lineptr = *ptr;
    printf("%c\n", *ptr++);
//    while((*lineptr++ = *ptr++) != '\0'){
//        printf("i%d\n", i);
//        i += 1;
//    }
    return i;
}
