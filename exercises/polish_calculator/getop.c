#include <stdio.h>
#include <ctype.h>

#define NUMBER '0' /* signal that a number was found */

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* if c is not a number */
    if (!isdigit(c) && c != '.') {
        return c;
    }

    /* collect integer part */
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    /* collect fractional part */
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}
