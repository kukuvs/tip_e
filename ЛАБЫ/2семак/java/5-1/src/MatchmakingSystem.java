import java.util.*;

class Groom {
    List<String> properties;

    public Groom(List<String> properties) {
        this.properties = properties;
    }
}

class Bride {
    List<String> properties;

    public Bride(List<String> properties) {
        this.properties = properties;
    }
}

public class MatchmakingSystem {
    public static List<Bride> findMatches(List<Groom> grooms, List<Bride> brides) {
        List<Bride> matches = new ArrayList<>();

        // Проходим по каждой невесте
        for (Bride bride : brides) {
            Map<Groom, Integer> groomPreferences = new HashMap<>();

            // Оцениваем каждого жениха для данной невесты
            for (Groom groom : grooms) {
                int score = calculateScore(groom, bride);
                groomPreferences.put(groom, score);
            }

            // Сортируем женихов по степени предпочтения
            List<Groom> sortedGrooms = new ArrayList<>(grooms);
            sortedGrooms.sort(Comparator.comparingInt(groomPreferences::get).reversed());

            // Выбираем самого предпочтительного жениха для невесты
            Groom bestMatch = sortedGrooms.get(0);
            matches.add(new Bride(bride.properties)); // Добавляем невесту в список совпадений
        }

        return matches;
    }

    private static int calculateScore(Groom groom, Bride bride) {
        // Здесь можно реализовать логику расчета степени предпочтения
        // Например, можно просто считать количество общих положительных свойств между женихом и невестой
        int score = 0;
        for (String property : groom.properties) {
            if (bride.properties.contains(property)) {
                score++;
            }
        }
        return score;
    }

    public static void main(String[] args) {
        // Создаем списка женихов и невест
        List<Groom> grooms = new ArrayList<>();
        grooms.add(new Groom(Arrays.asList("Хороший характер", "Заботливый", "Честный")));
        grooms.add(new Groom(Arrays.asList("Заботливый", "Щедрый", "Веселый")));

        List<Bride> brides = new ArrayList<>();
        brides.add(new Bride(Arrays.asList("Добрая", "Веселая", "Честная")));
        brides.add(new Bride(Arrays.asList("Хорошая хозяйка", "Заботливая", "Веселая")));

        // Находим подходящие пары
        List<Bride> matches = findMatches(grooms, brides);

        // Выводим результаты
        System.out.println("Список совпадений:");
        for (Bride bride : matches) {
            System.out.println(bride.properties);
        }
    }
}
