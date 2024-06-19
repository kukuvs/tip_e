public class Main {
    public static void main(String[] args) {
        // Задаем размеры массива
        int n = 2;
        int m = 2;

        // Создаем двумерный массив
        int[][] A = new int[n][m];

        // Заполняем массив
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = (i + j) % m;
            }
        }

        // Выводим массив
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }
}