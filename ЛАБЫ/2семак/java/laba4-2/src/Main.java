import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Пример создания коллектора и списка книг
        List<Book> books = new ArrayList<>();
        books.add(new Book("The Great Gatsby", Theme.FICTION));
        books.add(new Book("1984", Theme.SCIENCE_FICTION));
        books.add(new Book("Sapiens", Theme.HISTORY));
        books.add(new Book("Steve Jobs", Theme.BIOGRAPHY));
        books.add(new Book("How to Win Friends and Influence People", Theme.SELF_HELP));
        books.add(new Book("The Da Vinci Code", Theme.MYSTERY));

        LibraryCollector collector = new LibraryCollector(books);

        // Распределение книг по наборам
        List<List<Book>> sets = collector.distributeBooks(3);

        // Вывод наборов книг
        for (int i = 0; i < sets.size(); i++) {
            System.out.println("Набор " + (i + 1) + ":");
            for (Book book : sets.get(i)) {
                System.out.println(book.getTitle() + " - " + book.getTheme());
            }
            System.out.println();
        }
    }
}
