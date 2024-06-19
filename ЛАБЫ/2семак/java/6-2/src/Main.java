import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Пример использования классов
        Product[] products = {
                new Product("Молоко", 123, 50, 80.0),
                new Product("Хлеб", 456, 100, 50.0),
                new Product("Яйца", 789, 30, 120.0)
        };

        Warehouse warehouse = new Warehouse(products);

        Scanner scanner = new Scanner(System.in);

        // Вывод информации о товаре по номеру с помощью индекса
        warehouse.displayProductByIndex(0);

        // Вывод информации о товаре по названию
        System.out.print("Введите название товара для поиска: ");
        String productName = scanner.nextLine();
        warehouse.displayProductByName(productName);

        // Сортировка товаров по наименованию и вывод отсортированного списка
        warehouse.sortByProductName();
        System.out.println("\nТовары после сортировки по наименованию:");
        for (Product product : products) {
            System.out.println(product.getName());
        }

        // Сортировка товаров по количеству и вывод отсортированного списка
        warehouse.sortByQuantity();
        System.out.println("\nТовары после сортировки по количеству:");
        for (Product product : products) {
            System.out.println(product.getQuantity());
        }

        // Сортировка товаров по цене и вывод отсортированного списка
        warehouse.sortByPrice();
        System.out.println("\nТовары после сортировки по цене:");
        for (Product product : products) {
            System.out.println(product.getPrice());
        }

        scanner.close();
    }
}