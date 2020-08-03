#include <regex.h>        
#include <stdio.h>

void test00();
void test01();
void test02();

void main(){
    test02();
}

void test00(){
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, "^a.*d$", 0);
    if (reti) {
        printf("Could not compile regex\n");
        return;
    }

    /* Execute regular expression */
    reti = regexec(&regex, "abc", 0, NULL, 0);
    if (!reti) {
            puts("Match");
    }
    else if (reti == REG_NOMATCH) {
            puts("No match");
    }
    else {
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            printf("Regex match failed\n");
            return;
    }

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
}

void test01(){
    regex_t regex;
    regcomp(&regex, "^hello.*", 0);
    int reti = regexec(&regex, "hello world", 0, NULL, 0);
    if(! reti){
        printf("match--\n");
    }else{
        printf("unmatch--\n");
    }
    regfree(&regex);
}

void test02(){
    regex_t reg;
    regcomp(&reg, "^hello world$", 0);
    int result = regexec(&reg, "hell9o world", 0, NULL, 0);
    printf("result=%d\n", result);
}
