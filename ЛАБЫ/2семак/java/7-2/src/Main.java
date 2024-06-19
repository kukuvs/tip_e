public class Main {
    public static void main(String[] args) {

        // Создание руководителя (Boss)
        Boss boss = new Boss("Алексей");

        // Создание сотрудников (Employee)
        Employee employee1 = new Employee("Иван", "Разработка");
        Employee employee2 = new Employee("Мария", "Разработка");

        // Создание отдела (Department)
        Department developmentDepartment = new Department("Разработка", boss);

        // Добавление сотрудников в отдел
        developmentDepartment.addEmployee(employee1);
        developmentDepartment.addEmployee(employee2);

        // Создание компании (Firm) и добавление в неё отдела
        Firm firm = new Firm("Tech Solutions");
        firm.addDepartment(developmentDepartment);

        // Вывод информации о компании и её сотрудниках
        System.out.println("Компания: " + firm.getName());
        for (Department dept : firm.getDepartments()) {
            System.out.println("Отдел: " + dept.getName());
            System.out.println("Руководитель отдела: " + dept.getBoss().getName());
            System.out.println("Сотрудники отдела: ");
            for (Employee emp : dept.getEmployees()) {
                System.out.println(emp.getName() + " - " + emp.getDescription());
            }
        }
    }
}
