public class SaddlePoint {

    /**
     * Выводит заданную двухмерную матрицу на экран.
     * @param matrix Матрица, которую необходимо напечатать.
     */
    public void printMatrix(int[][] matrix) {
        System.out.println("Исходный массив:");
        for (int[] row : matrix) {
            for (int num : row) {
                // Форматированный вывод чисел матрицы для лучшей читаемости
                System.out.printf("%4d ", num);
            }
            System.out.println();
        }
    }

    /**
     * Находит и выводит на экран седловую точку в матрице. Если седловая точка не найдена,
     * выводится число 0. Поиск седловой точки выполняется путем проверки каждого элемента
     * массива на соответствие определению седловой точки.
     * @param matrix Двухмерный массив чисел, в котором нужно найти седловую точку.
     */
    public void findAndPrintSaddlePoint(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            int minRowValue = matrix[i][0]; // Самое маленькое число в строке i.
            int minRowIndex = 0; // Индекс столбца с минимальным значением в строке i.

            // Поиск минимального значения в строке i.
            for (int j = 1; j < matrix[i].length; j++) {
                if (matrix[i][j] < minRowValue) {
                    minRowValue = matrix[i][j];
                    minRowIndex = j;
                }
            }

            // Проверка, является ли элемент седловой точкой.
            boolean isSaddlePoint = true;
            for (int k = 0; k < matrix.length; k++) {
                if (matrix[k][minRowIndex] > minRowValue) {
                    isSaddlePoint = false;
                    break; // Выход из цикла, если это не седловая точка.
                }
            }

            // Если элемент является седловой точкой, выводим его координаты и значение.
            if (isSaddlePoint) {
                System.out.println("Седловая точка находится в строке " + (i + 1) + " и столбце " + (minRowIndex + 1) + " со значением " + minRowValue);
                return; // Завершаем выполнение программы после нахождения седловой точки.
            }
        }

        // Если в матрице нет седловой точки, выводим 0.
        System.out.println("0");
    }
}
