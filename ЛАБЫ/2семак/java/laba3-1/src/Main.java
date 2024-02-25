import java.util.Random;

public class Main {

    public static void main(String[] args) {
        // Создаем массив из 15 элементов
        int[] array = new int[15];
        // Заполняем массив случайными числами от -100 до 100
        fillArrayWithRandomNumbers(array, -100, 100);

        // Выполняем методы над массивом
        int countNonNegative = countNonNegativeNumbers(array);
        int sumNegative = sumNegativeNumbers(array);
        int indexMinNegative = indexOfMinNegativeNumber(array);
        
        // Выводим результаты
        System.out.println("Количество неотрицательных чисел: " + countNonNegative);
        System.out.println("Сумма отрицательных чисел: " + sumNegative);
        System.out.println("Номер минимального отрицательного числа: " + indexMinNegative);
        
        // Выводим ячейки с нечетными индексами
        printOddIndexedElements(array);
    }

    // Метод для заполнения массива случайными числами
    public static void fillArrayWithRandomNumbers(int[] array, int min, int max) {
        Random random = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt(max - min + 1) + min;
        }
    }

    // Метод расчета количества неотрицательных чисел
    public static int countNonNegativeNumbers(int[] array) {
        int count = 0;
        for (int j : array) {
            if (j >= 0) {
                count++;
            }
        }
        return count;
    }

    // Метод расчета суммы отрицательных чисел
    public static int sumNegativeNumbers(int[] array) {
        int sum = 0;
        for (int j : array) {
            if (j < 0) {
                sum += j;
            }
        }
        return sum;
    }

    // Метод нахождения номера минимального отрицательного числа
    public static int indexOfMinNegativeNumber(int[] array) {
        int index = -1;
        int minNegative = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] < 0 && (index == -1 || array[i] < minNegative)) {
                minNegative = array[i];
                index = i;
            }
        }
        return index;
    }

    // Метод вывода ячеек с нечетными индексами
    public static void printOddIndexedElements(int[] array) {
        for (int i = 1; i < array.length; i += 2) {
            System.out.println("a[" + i + "] = " + array[i]);
        }
    }
}