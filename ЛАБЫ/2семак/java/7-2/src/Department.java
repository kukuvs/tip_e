import java.util.ArrayList;

// Класс Department, представляющий отдел внутри фирмы
class Department {
    private String name;  // Название отдела
    private Boss boss;  // Руководитель отдела
    private ArrayList<Employee> employees;  // Список сотрудников отдела

    public Department(String name, Boss boss) {
        this.name = name;
        this.boss = boss;
        this.employees = new ArrayList<Employee>();
    }

    // Метод для добавления сотрудника в отдел
    public void addEmployee(Employee emp) {
        employees.add(emp);
    }

    // Геттер для названия отдела
    public String getName() {
        return name;
    }

    // Геттер для руководителя отдела
    public Boss getBoss() {
        return boss;
    }

    // Геттер для списка сотрудников
    public ArrayList<Employee> getEmployees() {
        return employees;
    }
}