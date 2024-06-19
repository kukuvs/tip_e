import java.util.ArrayList;

public class MethodExtractor {

    /* Метод для извлечения описаний методов из текста класса на C# */
    public static String[] extractMethodDescriptions(String classDescription) {
        ArrayList<String> methods = new ArrayList<>(); // Создание списка для хранения описаний методов
        StringBuilder method = new StringBuilder(); // Используется для построения строки описания метода
        char[] textArray = classDescription.toCharArray(); // Преобразование текста класса в массив символов

        boolean methodFound = false; // Флаг для обнаружения начала метода

        // Цикл проходит по всем символам текста класса
        for (int i = 0; i < textArray.length; i++) {
            if (textArray[i] == '{') {
                // Если находим открывающую скобку, начинаем запись метода
                methodFound = true;
                method.setLength(0); // Очищаем StringBuilder для нового метода
            } else if (textArray[i] == '}' && methodFound) {
                // Если находим закрывающую скобку и перед этим был метод, заканчиваем его запись
                methodFound = false;
                methods.add(method.toString().trim()); // Добавляем метод в список, удаляя лишние пробелы
            }

            // Если флаг methodFound активен, записываем символы в StringBuilder
            if (methodFound) {
                method.append(textArray[i]);
            }
        }

        // Преобразуем список описаний методов в массив строк
        String[] methodArray = new String[methods.size()];
        return methods.toArray(methodArray);
    }

    public static void main(String[] args) {
        // Исходный текст класса на C# для анализа
        String classDescription = "public class ExampleClass { "
                + "public void method1() { } "
                + "public void method2() { } "
                + "public void method3() { } }";

        // Получение массива строк с описаниями методов
        String[] methods = extractMethodDescriptions(classDescription);

        // Вывод каждого описания метода в консоль
        for (String method : methods) {
            System.out.println(method);
        }
    }
}
