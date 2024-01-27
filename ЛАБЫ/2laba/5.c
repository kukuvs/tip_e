#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

int main() {
   SetConsoleOutputCP(CP_UTF8);
   SetConsoleCP(CP_UTF8);
   double W;
   double Pr;
   double Sum;
   double asum;
   double a;
   bool cap;

   // Ввод начального вклада и процента
   printf("Введите начальный вклад: ");
   scanf("%lf", &W);
   printf("Введите годовой процент: ");
   scanf("%lf", &Pr);

   // Ввод суммы накопления и капитализации
   printf("Введите сумму накопления: ");
   scanf("%lf", &Sum);
   printf("Введите капитализация по вкладу? (да - 1, нет - 0): ");
   scanf("%d", &cap);

   // Инициализация переменных
   a = W;
   int i = 0;

   // Цикл по накоплению
   while (a < Sum) {
       // Если капитализация по вкладу, то сумма накопления = вклад + вклад * процент / 100
       if (cap) {
           a += a * Pr / 100;
       }
       // Иначе сумма накопления = W + W * процент / 100
       else {
           a += W * Pr / 100;
       }
       // Увеличение счетчика лет
       i++;
   }

   // Вывод количества лет
   printf("%d\n", i);

   return 0;
}
