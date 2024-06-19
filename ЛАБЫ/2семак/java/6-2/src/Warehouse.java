import  java.util.Arrays;
// Класс склада
class Warehouse {
    private Product[] products; // массив товаров

    // Конструктор
    public Warehouse(Product[] products) {
        this.products = products;
    }

    // Метод для вывода информации о товаре по номеру с помощью индекса
    public void displayProductByIndex(int index) {
        if (index >= 0 && index < products.length) {
            Product product = products[index];
            System.out.println("Информация о товаре по номеру " + index + ":");
            System.out.println("Название: " + product.getName());
            System.out.println("Код: " + product.getCode());
            System.out.println("Количество: " + product.getQuantity());
            System.out.println("Стоимость: " + product.getPrice() + " руб.");
        } else {
            System.out.println("Товар с номером " + index + " не найден.");
        }
    }

    // Метод для вывода на экран информации о товаре по названию
    public void displayProductByName(String name) {
        boolean found = false;
        for (Product product : products) {
            if (product.getName().equalsIgnoreCase(name)) {
                System.out.println("Информация о товаре с названием '" + name + "':");
                System.out.println("Код: " + product.getCode());
                System.out.println("Количество: " + product.getQuantity());
                System.out.println("Стоимость: " + product.getPrice() + " руб.");
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Товар с названием '" + name + "' не найден.");
        }
    }

    // Метод для сортировки товаров по наименованию
    public void sortByProductName() {
        Arrays.sort(products, (p1, p2) -> p1.getName().compareToIgnoreCase(p2.getName()));
    }

    // Метод для сортировки товаров по количеству
    public void sortByQuantity() {
        Arrays.sort(products, (p1, p2) -> p1.getQuantity() - p2.getQuantity());
    }

    // Метод для сортировки товаров по цене
    public void sortByPrice() {
        Arrays.sort(products, (p1, p2) -> Double.compare(p1.getPrice(), p2.getPrice()));
    }
}