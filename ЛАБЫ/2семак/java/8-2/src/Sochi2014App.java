import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;

//`Runnable`: функциональный интерфейс, определяющий задачу, которая выполняется в потоке.
//- `Thread.sleep(500)`: статический метод, который приостанавливает выполнение текущего потока на указанное время в миллисекундах (для имитации длительности этапа соревнования в примере).
//-`eventsQueue.poll(200, TimeUnit.MILLISECONDS)`: метод, извлекающий событие из очереди,
// ожидая заданное время. Если в течение этого времени событие не появится, метод возвращает `null`.

public class Sochi2014App {
    public static void main(String[] args) {
        // Создаем потокобезопасную очередь для событий
        BlockingQueue<SportEvent> eventsQueue = new LinkedBlockingQueue<>();

        // Список видов спорта
        String[] sportsTypes = {"Лыжный спуск", "Биатлон", "Бобслей",
                "Фигурное катание", "Керлинг", "Сноуборд", "Хоккей",
                "Скелетон", "Скоростной спуск", "Конькобежный спорт"};

        // Запускаем потоки, которые симулируют соревнования
        for (String sportType : sportsTypes) {
            new Thread(new Competition(eventsQueue, sportType)).start();
        }

        // Мониторинг и вывод событий на протяжении 15 секунд
        long startTime = System.currentTimeMillis();
        while (System.currentTimeMillis() - startTime < 15000) {
            try {
                // Из очереди извлекается событие с timeout 
                SportEvent event = eventsQueue.poll(200, TimeUnit.MILLISECONDS);
                if (event != null) {
                    // Если событие есть, печатаем его
                    System.out.println(event);
                }
            } catch (InterruptedException e) {
                // В случае прерывания потока корректно его завершаем
                Thread.currentThread().interrupt();
            }
        }

        // Вывод сообщения об окончании цикла моделирования
        System.out.println("Полный цикл моделирования завершен.");
    }
}
