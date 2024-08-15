import java.util.concurrent.BlockingQueue;

// Класс, представляющий событие
class SportEvent {
    private String eventName;
    private String sportType;

    public SportEvent(String eventName, String sportType) {
        this.eventName = eventName;
        this.sportType = sportType;
    }

    @Override
    public String toString() {
        return "Событие: " + eventName + " | Вид спорта: " + sportType;
    }
}

// Класс, имитирующий проведение соревнования
class Competition implements Runnable {
    private BlockingQueue<SportEvent> eventsQueue;
    private String sportType;

    // Конструктор, принимающий очередь для событий и тип спорта
    public Competition(BlockingQueue<SportEvent> eventsQueue, String sportType) {
        this.eventsQueue = eventsQueue;
        this.sportType = sportType;
    }

    // Метод run, который исполнится в отдельном потоке
    @Override
    public void run() {
        try {
            // Кидаем в очередь событие начала соревнования
            eventsQueue.put(new SportEvent("Начало соревнования", sportType));
            // Имитация длительности этапа
            Thread.sleep(500);
            // Кидаем в очередь событие окончания соревнования
            eventsQueue.put(new SportEvent("Окончание соревнования", sportType));
        } catch (InterruptedException e) {
            // Поток может быть прерван, что требует его правильной обработки.
            Thread.currentThread().interrupt();
        }
    }
}

