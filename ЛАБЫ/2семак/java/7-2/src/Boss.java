// Класс Boss, наследник Person, представляющий руководителя
class Boss extends Person {
    public Boss(String name) {
        super(name);  // Вызываем конструктор суперкласса Person
    }

    @Override
    public String getDescription() {
        return "Boss";
    }
}