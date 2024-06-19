import java.util.ArrayList;

// Класс Firm, представляющий компанию
class Firm {
    private String name;  // Название компании
    private ArrayList<Department> departments;  // Список отделов компании

    public Firm(String name) {
        this.name = name;
        this.departments = new ArrayList<Department>();
    }

    // Метод для добавления отдела в компанию
    public void addDepartment(Department dept) {
        departments.add(dept);
    }

    // Геттер для названия компании
    public String getName() {
        return name;
    }

    // Геттер для списка отделов
    public ArrayList<Department> getDepartments() {
        return departments;
    }
}