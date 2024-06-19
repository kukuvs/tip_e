// Класс товара
class Product {
    private String name; // название товара
    private int code; // код товара
    private int quantity; // количество
    private double price; // стоимость товара в рублях

    // Конструктор
    public Product(String name, int code, int quantity, double price) {
        this.name = name;
        this.code = code;
        this.quantity = quantity;
        this.price = price;
    }

    // Методы получения состояния объекта
    public String getName() {
        return name;
    }

    public int getCode() {
        return code;
    }

    public int getQuantity() {
        return quantity;
    }

    public double getPrice() {
        return price;
    }
}
