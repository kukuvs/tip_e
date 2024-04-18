import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// Класс для библиотечного коллектора
public class LibraryCollector {
    private List<Book> books;

    public LibraryCollector(List<Book> books) {
        this.books = books;
    }

    // Метод для распределения книг по наборам
    public List<List<Book>> distributeBooks(int n) {
        List<List<Book>> sets = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sets.add(new ArrayList<>());
        }

        // Сортировка списка книг по фамилиям авторов
        Collections.sort(books, (book1, book2) -> book1.getTitle().compareTo(book2.getTitle()));

        // Распределение книг по наборам
        for (int i = 0; i < books.size(); i++) {
            sets.get(i % n).add(books.get(i));
        }

        return sets;
    }
}