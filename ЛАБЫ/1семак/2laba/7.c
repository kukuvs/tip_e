#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define EPS7 1e-7


int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
     double x,s,r;
    int n;

    printf("Enter the number x: ");
    scanf("%lf", &x);

    r = x;
    s = x;

    for(n = 3; fabs(r) > EPS7; n += 2)
        s += r *= x*x/n/(n-1);

    printf("s = %lf\ne^%.0lf-e^%.0lf/2 = %lf\n", s, x, -x, sinh(x));//powf(M_E, x)-pow(M_E, -x)/2);
}