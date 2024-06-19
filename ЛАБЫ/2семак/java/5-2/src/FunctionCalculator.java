// 2. Windows-приложение: графический интерфейс пользователя
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FunctionCalculator extends JFrame {
    private JLabel label1; // Поле для ввода x1
    private JLabel label2; // Поле для ввода x2
    private JLabel label3; // Поле для ввода Δx
    private JLabel label4; // Поле для ввода ε
    private JTextField textField1; // Поле для ввода x1
    private JTextField textField2; // Поле для ввода x2
    private JTextField textField3; // Поле для ввода Δx
    private JTextField textField4; // Поле для ввода ε
    private JButton calculateButton; // Кнопка для вычисления
    private JTable table; // Таблица для отображения результатов

    /**
     * Конструктор окна
     */
    public FunctionCalculator() {
        setTitle("Расчет значений функции"); // Название окна
        setSize(600, 400); // Размер окна
        setDefaultCloseOperation(EXIT_ON_CLOSE); // Закрыть при выходе из окна

        JPanel panel = new JPanel(); // Пanel для размещения полей ввода
        panel.setLayout(new GridLayout(0, 2)); // Сетка из двух столбцов

        label1.setText("1x:"); // Подпись к полю ввода x1
        panel.add(label1);
        textField1.setText("0"); // Значение по умолчанию в поле x1
        panel.add(textField1);

        label2.setText("2x:"); // Подпись к полю ввода x2
        panel.add(label2);
        textField2.setText("1"); // Значение по умолчанию в поле x2
        panel.add(textField2);

        label3.setText("Δx:"); // Подпись к полю ввода Δx
        panel.add(label3);
        textField3.setText("0.1"); // Значение по умолчанию в поле Δx
        panel.add(textField3);

        label4.setText("ε:"); // Подпись к полю ввода ε
        panel.add(label4);
        textField4.setText("0.001"); // Значение по умолчанию в поле ε
        panel.add(textField4);

        calculateButton.setText("Рассчитать"); // Подпись к кнопке
        calculateButton.addActionListener(new ActionListener() { // Обработчик нажатия на кнопку
            @Override
            public void actionPerformed(ActionEvent e) {
                calculate();
            }
        });
        panel.add(calculateButton);


        table.setModel(new DefaultTableModel()); // Создание модели таблицы
        JScrollPane scrollPane = new JScrollPane(table); // Создание scroll-области для таблицы
        getContentPane().add(panel, BorderLayout.NORTH); // Размещение panel в верхней части окна
        getContentPane().add(scrollPane, BorderLayout.CENTER); // Размещение scroll-области в центре окна
    }


    public static void main(String[] args) {
        FunctionCalculator calculator = new FunctionCalculator(); // Создание экземпляра окна
        calculator.setVisible(true); // Отображение окна на экране
    }

// 3. Сравнение результатов и отображение в таблице
private void calculate() {
    long startTime = System.nanoTime();
    // Получение значений из полей ввода
    double x1 = Double.parseDouble(textField1.getText());
    double x2 = Double.parseDouble(textField2.getText());
    double deltaX = Double.parseDouble(textField3.getText());
    // Получите значение epsilon
    double epsilon = Double.parseDouble(textField4.getText());

    // Создание модели таблицы
    DefaultTableModel model = new DefaultTableModel();
    model.addColumn("Значение аргумента");
    model.addColumn("Значение функции (Тейлор)");
    model.addColumn("Значение функции (Math)");
    model.addColumn("Разница");
    model.addColumn("Кол-во членов ряда");

    // Вычисление и отображение результатов в таблице
    for (double x = x1; x <= x2; x += deltaX) {
        double taylorResult = TaylorSeries.computeFunction(x, epsilon);
        double mathResult = Math.exp(x); // Пример для экспоненциальной функции, замените на свою
        double difference = Math.abs(taylorResult - mathResult);
        int terms = TaylorSeries.getTermsUsed(); // Предполагается, что у вас есть метод для получения количества использованных членов ряда

        model.addRow(new Object[]{x, taylorResult, mathResult, difference, terms});
    }
    long endTime = System.nanoTime(); // Запоминаем текущее время в наносекундах после завершения расчетов
    long duration = (endTime - startTime) / 1000000; // Вычисляем разницу во времени и переводим ее в миллисекунды
    System.out.println("Время выполнения: " + duration + " мс"); // Выводим время выполнения в консоль
    table.setModel(model);
}

// 4. Оценка времени работы программы



}

