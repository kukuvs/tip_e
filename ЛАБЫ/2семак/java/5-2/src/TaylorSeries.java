public class TaylorSeries {
    private static int termsUsed; // Переменная для хранения количества использованных членов ряда

    public static double computeFunction(double x, double epsilon) {
        double result = 1; // Начальное значение ряда Тейлора
        double term = 1; // Значение текущего члена ряда
        termsUsed = 1; // Изначально используется один член ряда

        for (int n = 1; Math.abs(term) > epsilon; n++) {
            term *= x / n; // Рекурсивно вычисляем следующий член ряда
            result += term; // Добавляем член ряда к результату
            termsUsed++; // Увеличиваем количество использованных членов ряда
        }

        return result;
    }

    public static int getTermsUsed() {
        return termsUsed;
    }
}
