// Класс Employee, наследник Person, представляющий сотрудника компании
class Employee extends Person {
    private String departmentName;  // Название отдела, в котором работает сотрудник

    public Employee(String name, String departmentName) {
        super(name);  // Вызываем конструктор суперкласса Person
        this.departmentName = departmentName;
    }

    // Переопределение метода getDescription
    @Override
    public String getDescription() {
        return "Employee in " + departmentName;
    }
}