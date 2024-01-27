#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double a;
    int n;
    double c = 1;

    printf("Enter a real number: ");
    scanf("%lf", &a);
    printf("Enter a natural number: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        c *= a-i*n;
        printf("%lf\n", c);
    }
    c *= a;
    printf("%lf\n", c);

}