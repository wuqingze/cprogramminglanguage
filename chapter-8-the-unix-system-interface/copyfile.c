#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 

#define PERMS 0666

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("params error\n");
        return 1;
    }

    int copyfile(char *src, char *desc);
    int len = copyfile(argv[1], argv[2]);
    if(len<0){
        printf("copy file failure\n");
    }else {
        printf("file %s copy successfully, size %d byte\n", argv[1], len);
    }
    return 0;

    int f1, f2, n;
    char buf[BUFSIZ];

    if((f1 = open(argv[1], O_RDONLY, 0)) == -1){
        printf("can't open file %s\n", argv[1]);
        return 1;
    }
    if((f2 = open(argv[2], PERMS, 0)) == -1){
        printf("file %s does'nt exit, create new one...\n", argv[2]);
        creat(argv[2], PERMS);
        f2 = open(argv[2], PERMS, 0);
    }

    while((n = read(f1, buf, BUFSIZ)) > 0){
        if(write(f2, buf, n) != n){
            printf("cp: write error on file %s", argv[2]);
            return 1;
        }
    }
    printf("copy file %s to file %s successlly!", argv[1], argv[2]);
    return 0;
}

int copyfile(char *src, char *desc){
    int f1, f2, n;
    char buf[BUFSIZ];
    int filesize = 0;

    if((f1=open(src, O_RDONLY, 0)) == -1){
        printf("can't open file %s\n", src);
        return -1;
    }
    if((f2=open(desc, O_RDONLY, 0)) == -1){
        creat(desc, PERMS);
        f2 = open(desc, PERMS, 0);
    }

    while((n = read(f1, buf, BUFSIZ)) >0){
        if(write(f2, buf, n) != n){
                printf("write to file %s error\n", desc);
                return -1;
        }
        filesize += n;
    }

    return filesize;
}
