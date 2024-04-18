import java.util.Random;


public class Main {
    public static void main(String[] args) {
        int M = 5; // Количество строк
        int N = 5; // Количество столбцов
        int[][] matrix = new int[M][N];
        Random rand = new Random();

        // Инициализация матрицы случайными числами
        fillMatrixWithRandomNumbers(matrix, rand);

        // Вывод матрицы в консоль
        printMatrix(matrix);

        // Нахождение и вывод максимального элемента в каждом столбце
        printMaxElementsInColumns(matrix);

        // Расчет и вывод среднего значения среди всех нечетных элементов
        printAverageOfOddNumbers(matrix);
    }

    /**
     * Заполняет матрицу случайными числами.
     * @param matrix матрица для заполнения.
     * @param rand генератор случайных чисел.
     */
    public static void fillMatrixWithRandomNumbers(int[][] matrix, Random rand) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = rand.nextInt(100); // Диапазон 0-99
            }
        }
    }

    /**
     * Печатает матрицу в читаемом виде.
     * @param matrix матрица для печати.
     */
    public static void printMatrix(int[][] matrix) {
        System.out.println("Матрица:");
        for (int[] row : matrix) {
            for (int num : row) {
                System.out.printf("%4d ", num);
            }
            System.out.println();
        }
    }

    /**
     * Находит и печатает максимальные элементы в каждом столбце матрицы.
     * @param matrix матрица для поиска максимальных значений.
     */
    public static void printMaxElementsInColumns(int[][] matrix) {
        System.out.println("\nМаксимальные элементы в столбцах:");
        for (int j = 0; j < matrix[0].length; j++) {
            int maxInColumn = matrix[0][j];
            for (int[] row : matrix) {
                if (row[j] > maxInColumn) {
                    maxInColumn = row[j];
                }
            }
            System.out.printf("%4d ", maxInColumn);
        }
    }

    /**
     * Рассчитывает и печатает среднее значение всех нечетных чисел в матрице.
     * @param matrix матрица, содержащая нечетные числа для расчета.
     */
    public static void printAverageOfOddNumbers(int[][] matrix) {
        int sumOdd = 0;
        int countOdd = 0;
        for (int[] row : matrix) {
            for (int num : row) {
                if (num % 2 != 0) {
                    sumOdd += num;
                    countOdd++;
                }
            }
        }
        double averageOdd = countOdd > 0 ? (double) sumOdd / countOdd : 0;
        System.out.println("\nСреднее значение среди всех нечетных элементов: " + String.format("%.2f", averageOdd));
    }
}