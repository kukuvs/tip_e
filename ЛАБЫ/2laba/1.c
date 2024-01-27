#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double k, m, f;

    printf("Please, enter number k and m: ");
    scanf("%lf %lf", &k, &m);

    f = (k > 0) ? (m / k) : ((k <= 0 || m < 0) ? (m + k) : (k * m));
    printf("f=%lf\n", f);


}