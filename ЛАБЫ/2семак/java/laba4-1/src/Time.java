public class Time {
    private int hours;
    private int minutes;
    private int seconds;

    // Конструктор с проверкой допустимости вводимых значений
    public Time(int hours, int minutes, int seconds) {
        setTime(hours, minutes, seconds);
    }

    // Метод установки даты и времени с проверкой допустимости вводимых значений
    public void setTime(int hours, int minutes, int seconds) {
        if (hours < 0 || hours > 24 || minutes < 0 || minutes > 60 || seconds < 0 || seconds > 60) {
            throw new IllegalArgumentException("Недопустимые значения для времени.");
        }
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    // Метод изменения времени на заданное количество часов, минут и секунд
    public void addTime(int addedHours, int addedMinutes, int addedSeconds) {
        int totalSeconds = this.hours * 3600 + this.minutes * 60 + this.seconds;
        totalSeconds += addedHours * 3600 + addedMinutes * 60 + addedSeconds;

        // Обработка случая, когда количество секунд отрицательное
        while (totalSeconds < 0) {
            totalSeconds += 24 * 3600; // Добавляем сутки в секундах
        }

        this.hours = (totalSeconds / 3600) % 24;
        this.minutes = (totalSeconds % 3600) / 60;
        this.seconds = totalSeconds % 60;
    }

    public void displayTime() {
        System.out.printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    }
}
