import java.util.ArrayList;
import java.util.function.UnaryOperator;

public class StringArrayListApp {

    public static void main(String[] args) {
        // Создание коллекции ArrayList
        ArrayList<String> strings = new ArrayList<>();

        // Добавление нескольких строк
        strings.add("Пример строки / со знаками препинания, числами 123 и пробелами   .");
        strings.add("Ещё одна строка, которая включает / и другие/знаки");

        // Добавление строк в начало списка
        strings.add(0, "Строка в начале");

        // Изменение размера списка, если требуется, происходит автоматически в ArrayList

        // Просмотр всех элементов списка с указанием числа элементов и ёмкости
        System.out.println("Список содержит " + strings.size() + " элементов.");
        for (int i = 0; i < strings.size(); i++) {
            System.out.println("Элемент " + i + ": " + strings.get(i));
        }

        // Создание и применение функций для изменения строк в списке
        UnaryOperator<String> replaceSpaces = s -> s.replace(" ", "_");
        UnaryOperator<String> replaceForwardSlashWithBackSlash = s -> s.replace("/", "\\");
                UnaryOperator<String> replaceForwardSlashWithDouble = s -> s.replace("/", "//");
        UnaryOperator<String> toUpperCase = String::toUpperCase;

        // Применение функций к элементам списка
        strings.replaceAll(replaceSpaces);
        strings.replaceAll(replaceForwardSlashWithBackSlash);
        strings.replaceAll(replaceForwardSlashWithDouble);
        strings.replaceAll(toUpperCase);

        // Вывод измененного списка
        System.out.println("Измененный список:");
        strings.forEach(System.out::println);
    }
}
