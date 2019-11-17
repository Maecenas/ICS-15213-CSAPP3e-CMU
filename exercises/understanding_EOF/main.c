/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    char a = EOF;
    char b = 255;
    char c = 127;
    char d = 127 + 1;
    printf("the EOF is %x in Hexidecimal\n", EOF);
    printf("we can tell from the warning message that the type of EOF is int\n");
    // printf("%s\n", EOF);
    printf("signed char can truncate EOF and represent it as %d\n", a);
    printf("overflow: the bit representation of 255 will be interpreted as %d with signed char\n", b);
    printf("the max value signed char can represent is %d\n", c);
    printf("overflow: the bit representation of 128 will be interpreted as %d with signed char\n", d);
    printf("the truncated EOF is %sequal to the representation of 255 with signed char\n", (a == b) ? "" : "not ");
    printf("convert a to int with sign extension: %d\n", (int)a);
    printf("since EOF is int, a will be converted to int then compare, and the result is %s, both of which is %d\n", (a == EOF) ? "true" : "false", a);
    
    unsigned char e = EOF;
    unsigned char f = 255;
    printf("unsigned char can truncate EOF and represent it as %d\n", e);
    printf("the max value unsigned char can represent is %d\n", f);
    printf("the truncate EOF is %sequal to the representation of 255 with unsigned char\n", (e == f) ? "" : "not ");
    printf("since EOF is int, e will be converted to int then compare, and the result is %s, becase e is %d, EOF is %d\n", (e == EOF) ? "true" : "false", e, EOF);

    return 0;
}
