import java.util.Random;

public class JaggedArray {

    public static void main(String[] args) {
        // Создаем ступенчатый массив с тремя матрицами разного размера
        int[][][] jaggedArray = {
                new int[2][2], // Матрица 2x2
                new int[3][2], // Матрица 3x2
                new int[2][3]  // Матрица 2x3
        };

        // Заполняем массив случайными числами
        Random random = new Random();
        for (int[][] matrix : jaggedArray) {
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[i].length; j++) {
                    matrix[i][j] = random.nextInt(100); // Случайные числа от 0 до 99
                }
            }
        }

        // Определение минимума в каждой строке и расчет суммы минимумов
        int sumOfMinima = 0;
        for (int[][] matrix : jaggedArray) {
            for (int[] row : matrix) {
                int minInRow = findMin(row);
                sumOfMinima += minInRow; // Суммируем минимумы
                System.out.println("Минимум в строке: " + minInRow);
            }
        }

        System.out.println("Сумма всех минимумов в строках: " + sumOfMinima);
    }

    //минимум в строке
    private static int findMin(int[] row) {
        int min = row[0];
        for (int value : row) {
            if (value < min) {
                min = value;
            }
        }
        return min;
    }
}
