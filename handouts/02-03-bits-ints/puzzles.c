#include <stdio.h>
#include <limits.h>

void right_shift() {
    printf("int is represented with %zu bytes, %lu bits\n", sizeof(int), sizeof(int) * 8);
    printf("number 4 right shift 65 bits, we have %d\n", (int)4 >> 65);
}

void unsigned2twoscomplement() {
    int x = (int)2147483648U;
    printf("convert unsigned 2147483648U to int, we have %d\n", x);
}

void tmax_plus_one() {
    printf("increment TMax with one, we have: %d\n", INT_MAX + 1);
}

void negative_tmin() {
    printf("add negative sign to TMin, we have: %d\n", -INT_MIN);
}

int abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}

void absolute_tmin() {
    printf("the absolute value (with our implementation of the absolute function) of TMin is: %d\n", abs(1 << 31));
}

int main() {
    right_shift();   // expected 2
    unsigned2twoscomplement(); // expected TMin
    tmax_plus_one(); // expected TMin
    negative_tmin(); // expected TMin
    absolute_tmin(); // expected TMin
    return 0;
}