public class Main {
    public static void main(String[] args) {
        // Создание нескольких объектов класса Time
        Time time1 = new Time(14, 30, 0);
        Time time2 = new Time(23, 59, 59);

        // Вывод исходных значений времени для каждого объекта
        System.out.println("Исходное время:");
        time1.displayTime();
        time2.displayTime();

        // Изменение времени на заданное количество часов, минут и секунд
        time1.addTime(5, 29, 0);
        time2.addTime(1, 1, 1);

        // Вывод времени после изменения
        System.out.println("\nВремя после изменения:");
        time1.displayTime();
        time2.displayTime();
    }
}