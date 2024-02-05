#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#define dx (double)(b-a)/N

double in(double a, double b, int N, double (*f)(double x))
{
    double s, x, y;
    int i;

    for(s = 0, x = a, i = 1; i<=N; i++)
    {
        y = -f(x);
        s += y*dx;
        x += dx;
    }
    return s;
}

double f1(double x)
{
    double y;
        y = 2*x*(x*x+1);
    return y;
}
double f2(double x)
{
    double y;
        y = log(x*x+1);
    return y;
}


int main(void)
{
    int i, N;
    double a, b, y, s;

    printf("Enter a, b, N: ");
    scanf("%lf %lf %d", &a, &b, &N);

    s = in(a, b, N, f1);

    printf("\ns = %.2lf\n", s);

    printf("\nEnter a, b, N: ");
    scanf("%lf %lf %d", &a, &b, &N);

    s = in(a, b, N, f2);

    printf("\ns = %.2lf\n\n", s);


}