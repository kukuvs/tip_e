import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

// Демонстрация использования класса Shuttle
public class Main {
    public static void main(String[] args) {
        Shuttle shuttle1 = new Shuttle(2020, 15000.0);
        shuttle1.addPassenger("Alice");
        shuttle1.addPassenger("Bob");

        Shuttle shuttle2 = new Shuttle(2025, 20000.0);
        shuttle2.addPassenger("Charlie");

        // Сравнение шаттлов
        int comparison = shuttle1.compareTo(shuttle2);
        System.out.println("Comparison: " + comparison);

        // Вывести всех пассажиров шаттла 1
        for (String passenger : shuttle1) {
            System.out.println(passenger);
        }
    }
}
