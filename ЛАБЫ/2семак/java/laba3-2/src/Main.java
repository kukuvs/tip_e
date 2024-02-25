import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        // Инициализация массива для демонстрации
        int[] array = {1, 2, 3, 4, 5, 6, 7};
        System.out.println("Original array: " + Arrays.toString(array));

        // Вызов метода для обмена соседними элементами
        swapAdjacentElements(array);

        // Вывод обновленного массива
        System.out.println("Array after swapping: " + Arrays.toString(array));
    }

    /**
     * Метод для обмена соседними элементами массива.
     * @param array массив, в котором необходимо выполнить обмен.
     */
    public static void swapAdjacentElements(int[] array) {
        // Проходим по массиву и обмениваем элементы парами
        for (int i = 0; i < array.length - 1; i += 2) {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
}