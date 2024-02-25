package Main;

public class Main {
    
    public static void main(String[] args) {
        // Пример использования функции
        double base = 2.0;
        int exponent = 3;
        double result = power(base, exponent);
        System.out.println(base + "^" + exponent + " = " + result);
    }

    public static double power(double a, int n) {
        // Базовый случай
        if (n == 0) {
            return 1;
        }
        // Рекурсивный случай
        return a * power(a, n - 1);
    }
}