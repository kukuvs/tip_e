import java.util.function.IntPredicate;
import java.util.stream.IntStream;

public class PerfectNumbersGenerator {

    public static void main(String[] args) {
        // Лямбда-выражение, проверяющее является ли число совершенным
        IntPredicate isPerfectNumber = (number) -> {
            // Сумма делителей числа
            int sum = IntStream.range(1, number)
                    .filter(divisor -> number % divisor == 0)
                    .sum();
            // Проверка равенства суммы делителей и самого числа
            return sum == number;
        };

        // Печать всех совершенных чисел в пределах от 1 до 10000
        System.out.println("Совершенные числа в диапазоне от 1 до 10000:");
        IntStream.rangeClosed(1, 10000)
                .filter(isPerfectNumber)
                .forEach(System.out::println);
        //- Поток фильтруется с помощью isPerfectNumber, и для каждого совершенного числа выводится его значение при помощи
        // forEach(System.out::println).
        //- Метод filter используется для отбора только тех делителей, на которые number делится без остатка.
    }
}
