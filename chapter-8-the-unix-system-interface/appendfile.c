#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]){
    void test00();
    void test01();

    test01();
    return 0;
}


void test00(){
    FILE *f = fopen("t", "a");
    char *line = "hello";
    char *ptr;
    char c;
    for(int i=0;i<100;i++){
        ptr = line;
        while((c=*ptr++) != '\0'){
            putc(c, f);
        }
        putc('\n', f);
    }
}

void test01(){
    int fp = open("t", O_WRONLY, 0);
    lseek(fp, 0L, 2);
    char s[] = "hello world";
    write(fp, s, 11);
}

int get(int fd, long pos, char *buf, int n){
    if(lseek(fd, pos, 0) >=0){
        return read(fd, buf, n);
    }else {
        return -1;
    }
}
