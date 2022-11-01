#include <iostream>
#include <math.h>

int main() {
    int a,inp;
    float b, c, d,div;
    double result;
    a = 25;
    b = 100;
    c = a / b;
    inp = 70000;
    d = (float)inp+(c*(float)inp);
    div = d/(float)inp;
    double data = (float)30/(float)11;
    result = inp*(pow(div,data));
    printf("%.2f",result);

    return 0;
}
