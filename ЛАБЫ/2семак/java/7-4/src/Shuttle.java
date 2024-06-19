import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

// Класс Shuttle наследует интерфейсы Comparable и Iterable
public class Shuttle implements Comparable<Shuttle>, Iterable<String> {

    private int year;
    private double maxSpeed;
    private List<String> passengers; // List для хранения пассажиров

    // Конструктор
    public Shuttle(int year, double maxSpeed) {
        this.year = year;
        this.maxSpeed = maxSpeed;
        this.passengers = new ArrayList<>();
    }

    // Добавить пассажира
    public void addPassenger(String passenger) {
        passengers.add(passenger);
    }

    // Метод для сравнения двух Шаттлов
    @Override
    public int compareTo(Shuttle other) {
        // Простое сравнение года выпуска шаттла
        return Integer.compare(this.year, other.year);
    }

    // Получить итератор для списка пассажиров
    @Override
    public Iterator<String> iterator() {
        return passengers.iterator();
    }

    // Геттеры и сеттеры
    public int getYear() {
        return year;
    }

    public double getMaxSpeed() {
        return maxSpeed;
    }

    // ... дополнительные геттеры и сеттеры при необходимости
}
