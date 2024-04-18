public class Main {

    /**
     * Главный метод класса. Запускает приложение и вызывает методы для нахождения и
     * печати седловой точки матрицы.
     * @param args Аргументы командной строки, которые в данном случае не используются.
     */
    public static void main(String[] args) {
        int M = 4; // Количество строк в матрице
        int N = 4; // Количество столбцов в матрице
        int[][] matrix = {
                {1, 3, 5, 9},
                {8, 40, 62, 67},
                {6, 5, 9, 4},
                {7, 8, 1, 4}
        };

        SaddlePoint saddlePoint = new SaddlePoint();

        // Вывод на экран исходной матрицы перед началом поиска седловой точки.
        saddlePoint.printMatrix(matrix);

        // Поиск седловой точки в матрице и её вывод на экран.
        saddlePoint.findAndPrintSaddlePoint(matrix);
    }

}