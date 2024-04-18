public class Main {
    public static void main(String[] args) {
        String text = "Пример строки с различными словами и пробелами";
        String[] words = text.split("\s+"); // Разбиение строки на слова через пробелы

        String longestWord = "";
        int longestLength = 0;

        for (String word : words) {
            if (word.length() > longestLength) {
                longestWord = word;
                longestLength = word.length();
            }
        }

        System.out.println("Самое длинное слово: " + longestWord);
        System.out.println("Длина слова: " + longestLength);
    }
}
