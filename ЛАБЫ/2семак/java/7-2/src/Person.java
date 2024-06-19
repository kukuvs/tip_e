// Абстрактный класс Person, от которого будут наследовать все персоны
abstract class Person {

    private String name;  // Общий атрибут имени для всех персон

    public Person(String name) {
        this.name = name;
    }

    // Геттер для имени персоны
    public String getName() {
        return name;
    }

    // Абстрактный метод, который можно переопределить в подклассах, если необходимо
    public abstract String getDescription();
}