public class Main {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 1, 1, 1, 2, 2, 9, 8, 7, 6, 5, 4, 3}; // Пример массива
        int[] counts = new int[10]; // Индексы от 0 до 9 для подсчета повторений чисел от 1 до 9

        // Подсчет количества каждой цифры
        for (int number : array) {
            if (number >= 1 && number <= 9) {
                counts[number]++;
            }
        }

        // Вывод результатов от 1 до 9
        for (int i = 1; i < counts.length; i++) {
            System.out.println("Число " + i + " встречается " + counts[i] + " раз(а).");
        }
    }
}
