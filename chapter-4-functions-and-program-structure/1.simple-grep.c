#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);
int _strindex(char s[], char t[]);
int test_00();
int test_01();

char pattern[] = "ould";

int main(){
    //test_01();
    test_00();
}

int test_00(){
	char line[MAXLINE];
	int found = 0;
    mygetline(line, MAXLINE);
    if (strindex(line, pattern) >= 0) {
        printf("%s", line);
        found++;
    }
	return found;
}

int test_01(){
	char line[MAXLINE];
	int found = 0;
    mygetline(line, MAXLINE);
    if (_strindex(line, pattern) >= 0) {
        printf("%s", line);
        found++;
    }
	return found;
}

//int mygetline(char s[], int lim)
//{
//	int c, i;
//	i =0;
//	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
//		s[i++] = c;
//	if (c == '\n')
//		s[i++] = c;
//	s[i] = '\0';
//	return i;
//}

int mygetline(char s[], int lim){
    char t[] = "hello world \n my xx\n wuqingze xx\n";
    int i = 0;
    while(t[i] != '\0'){
        s[i] = t[i];
        i += 1;
    }
    return 1;
}

int _strindex(char s[], char t[]){
    int i,k;
    for(i=0;s[i] != '\0'; i++){
        for(int j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k>0 && t[k] == '\0')
            return i;
    }

    return -1;
}

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++,k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
