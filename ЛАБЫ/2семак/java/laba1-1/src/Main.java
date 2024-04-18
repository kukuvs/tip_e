import java.lang.Math;

public class Main {

    public static void main(String[] args) {
        // Пример значений переменных
        double x = 1.0;  // Значение x
        double z = 10.0; // Значение z должно быть > 0
        double d = 1.0;  // Значение d
        double b = 2.71; // Значение b должно быть > 0

        // Вычисляем исходное и оптимизированное выражения
        double[] originalResult = calculateOriginalExpression(x, z, d, b);
        double[] optimizedResult = calculateOptimizedExpression(x, z, d, b);

        // Проверяем совпадение результатов
        boolean resultsMatch = Math.abs(originalResult[0] - optimizedResult[0]) < 1e-9;

        // Вычисляем выигрыш во времени
        double timeSavings = originalResult[1] - optimizedResult[1];

        // Выводим результаты
        System.out.println("Исходное выражение: " + originalResult[0]);
        System.out.println("Оптимизированное выражение: " + optimizedResult[0]);
        System.out.println("Результаты совпадают: " + resultsMatch);
        System.out.println("Исходная стоимость в у.е.: " + originalResult[1]);
        System.out.println("Оптимизированная стоимость в у.е.: " + optimizedResult[1]);
        System.out.println("Выигрыш во времени вычисления в у.е.: " + timeSavings);
    }

    // Функция для вычисления исходного выражения и подсчета времени в у.е.
    public static double[] calculateOriginalExpression(double x, double z, double d, double b) {
        if (z <= 0 || b <= 0) {
            throw new IllegalArgumentException("z and b must be greater than 0");
        }

        // 13 у.е.
        double log10_z = Math.log10(z);
        // 13 у.е.
        double ln_b = Math.log(b);
        // 13 у.е.
        double exp_d2 = Math.exp(Math.pow(d, 2));

        // 13 у.е.
        double cos_val = Math.cos(2 * x * log10_z);
        // 13 у.е.
        double sin_val_1 = Math.sin(2 * exp_d2 - ln_b);
        // 13 у.е.
        double sin_val_2 = Math.sin(2 * exp_d2 + ln_b);

        // 7 у.е.
        double originalExpression = (2 * cos_val) / (sin_val_1 + sin_val_2);

        // Стоимость операций
        double operationsCost = (4 * 13) + 7;
        return new double[]{originalExpression, operationsCost};
    }

    // Функция для вычисления оптимизированного выражения и подсчета времени в у.е.
    public static double[] calculateOptimizedExpression(double x, double z, double d, double b) {
        if (z <= 0 || b <= 0) {
            throw new IllegalArgumentException("z and b must be greater than 0");
        }

        // 13 у.е.
        double log10_z = Math.log10(z);
        // 13 у.е.
        double ln_b = Math.log(b);
        // 13 у.е.
        double exp_d2 = Math.exp(Math.pow(d, 2));

        // 13 у.е.
        double cos_val = Math.cos(2 * x * log10_z);
        // 13 у.е.
        double sin_val = Math.sin(2 * exp_d2);
        // 13 у.е.
        double cos_ln_b = Math.cos(ln_b);

        // 7 у.е.
        double optimizedExpression = cos_val / (sin_val * cos_ln_b);

        // Стоимость операций
        double operationsCost = (3 * 13) + 7;
        return new double[]{optimizedExpression, operationsCost};
    }
}