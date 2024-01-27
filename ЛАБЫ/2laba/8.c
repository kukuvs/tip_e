#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS8 1e-4
#define M_E 2.71828182845904

int main(void)
{
    double a,c,b,x,s,d,t;
    int n = 1;

    printf("Enter the number x(0.1-1): ");
    scanf("%lf", &x);
    fflush(stdin);

        if(x < 0.1 || x > 1)
        {
            printf("You have entered an invalid value.\n");
            main();
        }

    a = 1;
    s = 1;
    d = 1;
    b = 1;
    c = 1;

    while(fabs(d) > EPS8)
    {
        c = n-1;
        b = factorial(c)*n;
        //a = ((2*n+1)/f)*powf(x, 2*n);
        t = (2*n-1);
        a = ((2*n+1)/t)*x*x;
        d *= a/b;
        s += d;
        n++;
        printf("a = %lf, b = %lf, d = %lf, s = %lf\n", a, b, d, s);
    }

    printf("s = %.6lf\n(1+2%.1lf^2)e^%.1lf^2 = %.6lf\n", s, x, x, (1+2*x*x)*pow(M_E, powf(x, 2)));

}