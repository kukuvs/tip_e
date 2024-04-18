// Класс для представления книги
class Book {
    private String title;
    private Theme theme;

    public Book(String title, Theme theme) {
        this.title = title;
        this.theme = theme;
    }

    public String getTitle() {
        return title;
    }

    public Theme getTheme() {
        return theme;
    }
}
// Перечисление для тематики книг
enum Theme {
    FICTION,
    SCIENCE_FICTION,
    HISTORY,
    BIOGRAPHY,
    SELF_HELP,
    MYSTERY
}
