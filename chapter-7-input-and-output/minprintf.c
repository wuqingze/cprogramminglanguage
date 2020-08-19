#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...);
void _minprintf(char *fmt, ...);

int main()
{
	minprintf("int: %d, int: %d, double: %f, string: %s\n", 0, 1, 0.123, "Hello");

	_minprintf("int: %d, int: %d, double: %f, string: %s\n", 0, 1, 0.123, "Hello");
	return 0;
}

void _minprintf(char *fmt, ...){
    char *c;
    int intv;
    double doublev;
    char *stringv;

    va_list ap;
    va_start(ap, fmt);
    for(c = fmt; *c; c++){
        if(*c != '%'){
            putchar(*c);
            continue;
        }

        switch(*++c){
            case 'd':
                intv  = va_arg(ap, int);
                printf("%d", intv);
                break;
            case 'f':
                doublev = va_arg(ap, double);
                printf("%f", doublev);
                break;
            case 's':
                for(stringv = va_arg(ap, char*); *stringv; stringv++)
                    putchar(*stringv);
                break;
            default:
                putchar(*c);
                break;
        }
    }
    va_end(ap);
}

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}

