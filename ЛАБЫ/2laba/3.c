#include <stdio.h>
#include <stdlib.h>
#include <math.h> // для использования sqrt() и hypot()

int main(void)
{
   double ax, ay, bx, by; // координаты точек a и b
   double x, y; // разница между координатами x и y
   double a, b; // длины отрезков а и b
   double c, d; // длина вычисляемого расстояния между точками a и b

   printf("Enter coordinates of the point a: "); // спросить координаты точки a
   scanf("%lf %lf", &ax, &ay);
   printf("Enter coordinates of the point b: "); // спросить координаты точки b
   scanf("%lf %lf", &bx, &by);

   if(ax == 0 || ay == 0 || bx == 0 || by == 0) // если хотя бы одна из координат 0
   {
       if(ax == 0 && ay == 0) // обе координаты точки a равны 0
           printf("Both points a lies on the coordinate line\n");
       else if(ax == 0 || ay == 0) // одна из координат точки a равна 0
       {
           if(ax == 0) // координата x точки a равна 0
               printf("Point a lies on the coordinate line\n");
           else // координата y точки a равна 0
               printf("Point a lies on the coordinate line\n");
       } else if(bx == 0 && by == 0) // обе координаты точки b равны 0
           printf("Both points b lies on the coordinate line\n");
       else if(bx == 0 || by == 0) // одна из координат точки b равна 0
       {
           if(bx == 0) // координата x точки b равна 0
               printf("Point b lies on the coordinate line\n");
           else // координата y точки b равна 0
               printf("Point b lies on the coordinate line\n");
       }
   } else if(ax > 0 && ay > 0 && bx > 0 && by > 0 || // если обе точки на плоскости
             ax < 0 && ay > 0 && bx < 0 && by > 0 ||
             ax < 0 && ay < 0 && bx < 0 && by < 0 ||
             ax < 0 && ay > 0 && bx < 0 && by < 0) // и их направления совпадают
   {
       if(ax > bx) // если координата x точки a больше координаты x точки b
           x = ax-bx;
       else if(ax < bx) // иначе
           x = bx-ax;
       if(ay > by) // если координата y точки a больше координаты y точки b
           y = ay-by;
       else if(ay < by) // иначе
           y = by-ay;

       d = hypot(x, y); // вычислить длину отрезка между точками a и b

       printf("The distance between a and b: %lf\n", d); // вывести длину отрезка
   } 
   else
   {
       a = hypot(ax, ay); // вычислить длину отрезка а
       b = hypot(bx, by); // вычислить длину отрезка b

       printf("a = %lf, b = %lf\n", a, b); // вывести длины отрезков
       if(a > b)
       {
                    printf("Point a is more distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by); // вывести, что точка a ближе
       }else{
                printf("Points equally distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by); // вывести, что точки равноотстоят
        }
    }
}