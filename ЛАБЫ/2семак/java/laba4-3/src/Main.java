import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        File studentsFile = new File("in.txt"); // файл с данными о учащихся и их оценках
        if (!studentsFile.exists()) {
            System.err.println("File in.txt is not found");
            System.exit(1);
        }

        Scanner scanner = new Scanner(studentsFile);
        int studentsCount = scanner.nextInt(); // количество учащихся
        double[] mathGrades = new double[studentsCount]; // массив оценок по математике
        double[] physicsGrades = new double[studentsCount]; // массив оценок по физике
        double[] informaticsGrades = new double[studentsCount]; // массив оценок по информатике
        String bestStudentName = ""; // фамилия и имя участника с максимальным средним баллом
        double bestStudentAverage = 0; // максимальный средний балл

        for (int i = 0; i < studentsCount; i++) {
            String name = scanner.next(); // имя
            String surname = scanner.next(); // фамилия
            mathGrades[i] = scanner.nextDouble(); // оценка по математике
            physicsGrades[i] = scanner.nextDouble(); // оценка по физике
            informaticsGrades[i] = scanner.nextDouble(); // оценка по информатике

            double currentAverage = (mathGrades[i] + physicsGrades[i] + informaticsGrades[i]) / 3; // средний балл по трём предметам
            if (currentAverage > bestStudentAverage) { // если текущий учащийся имеет лучшую успеваемость
                bestStudentAverage = currentAverage; // то запоминаем его имя и средний балл
                bestStudentName = name + " " + surname;
            }
        }

        double mathAverage = arrayAverage(mathGrades); // средний балл по математике
        double physicsAverage = arrayAverage(physicsGrades); // средний балл по физике
        double informaticsAverage = arrayAverage(informaticsGrades); // средний балл по информатике

        System.out.printf("Средний балл по математике: %.2f\n", mathAverage); // выводим в консоль
        System.out.printf("Средний балл по физике: %.2f\n", physicsAverage);
        System.out.printf("Средний балл по информатике: %.2f\n", informaticsAverage);
        System.out.printf("Учащийся с наилучшей успеваемостью: %s\n", bestStudentName);

        try (var out = new FileWriter("out.txt")) { // записываем в файл out.txt имя участника с максимальным средним баллом
            out.write(bestStudentName);
        }
    }

    private static double arrayAverage(double[] grades) { // вычисляет средний балл для массива
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.length;
    }

}



