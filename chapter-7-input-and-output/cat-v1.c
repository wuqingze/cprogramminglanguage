#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    
    void test01();
    test01();
    return 0;

    void test00(char *);
    test00(argv[1]);
    return 0;

	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	
	return 0;
}

void test00(char *file){
    char *readfile(char *);
    char *s = readfile("t1.c");
    if(s != NULL){
        printf("read file ---\n");
        printf("%s", s);
    }
    printf("end file-----");
}

void test01(){
    struct stat fileStat;
    int _readfile(char *, char *);
    stat("t1.c", &fileStat);
    char *s = (char *) malloc(fileStat.st_size);
    int len = _readfile("t1.c", s);
    if(len<0){
        printf("can't open file %s\n", "t1.c");
    }else{
        printf("start read file-----\n");
        printf("%s\n", s);
        printf("end read file-------\n");
    }
}

int _readfile(char *file, char *result){
    FILE *fp = fopen(file, "r");
    if(fp == NULL){
        return -1;
    }

    int len = 0;
    for(char c; (c=fgetc(fp)) != EOF; *result++=c, len++)
        ;

    return len;
}

char *readfile(char *file){
    char *result;
    FILE *fp = fopen(file, "r");
    if(NULL == fp){
       printf("can't open %s\n", file);
        free(result);
    }else{
//        char *t = result;
        result = (char *) malloc(2048);
        char *t = result;
        char *s = "hello world";
       // while((*t++ = *s++))
       //     ;
       char c;
       while((c = (char) getc(fp)) != EOF){
           *t++ = c;
       }
//       while((*t++ = (char)getc(fp)) != EOF)
//            ;
//       *t = '\0';
    }
    fclose(fp);
    return result;
}


void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF){
		putc(c, ofp);
        printf("------\n");
    }
}

