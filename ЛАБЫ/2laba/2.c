#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_E 2.71828182845904


int main(void)
{
    double a,b;
    double c,d;
    double D;

    printf("function definition scope: (-oo;0), (0;+oo)\n");
    printf("Enter numbers a and b: ");
    scanf("%lf %lf", &a, &b);
    fflush(stdin);

    if(a == 0 || b == 0)
    {
        printf("The values do not belong to the scope of the function definition!\n");
        main();
    }
    else
    {
    c = powf(M_E, -1./6)*powf(pow(a, 2)+logf(abs(b)), 1./2)-tanf(a);
    d = 2*powf(cosf(powf(a, 3)), 2);

    D = c/d;

    printf("D = %lf\n", D);

    }
}