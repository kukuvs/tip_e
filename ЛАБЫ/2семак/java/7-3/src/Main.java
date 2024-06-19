// Интерфейс, описывающий действия и свойства устройства, работающего от питания
interface IPowerable {

    void turnOn();// Метод для включения устройства

    void turnOff();// Метод для выключения устройства

    void charge();// Метод для зарядки устройства

    int getChargeLevel();// Метод для получения уровня заряда устройства

    boolean isCharged();// Метод для проверки, заряжено ли устройство
}

// Класс iPhone, реализующий интерфейс IPowerable
class iPhone implements IPowerable {
    private int chargeLevel;     // Уровень заряда батареи
    private boolean isCharged;   // Состояние зарядки

    // Конструктор класса iPhone
    public iPhone() {
        this.chargeLevel = 0;
        this.isCharged = false;
    }

    @Override
    public void turnOn() {
        if (chargeLevel > 0 && isCharged) {
            System.out.println("iPhone is now on.");
        }
    }

    @Override
    public void turnOff() {
        System.out.println("iPhone is now off.");
    }

    @Override
    public void charge() {
        chargeLevel = 100;
        isCharged = true;
        System.out.println("iPhone is charging.");
    }

    @Override
    public int getChargeLevel() {
        return chargeLevel;
    }

    @Override
    public boolean isCharged() {
        return isCharged;
    }
}

// Класс Toaster, реализующий интерфейс IPowerable
class Toaster implements IPowerable {
    private int chargeLevel;      // Уровень заряда - в контексте тостера может быть
    // использован для индикации температуры или времени работы
    private boolean isCharged;    // Состояние зарядки - показывает, готов ли тостер к использованию

    // Конструктор класса Toaster
    public Toaster() {
        this.chargeLevel = 0;
        this.isCharged = false;
    }

    @Override
    public void turnOn() {
        if (isCharged) {
            System.out.println("Toaster is now on.");
        }
    }

    @Override
    public void turnOff() {
        System.out.println("Toaster is now off.");
    }

    @Override
    public void charge() {
        chargeLevel = 100;
        isCharged = true;
        System.out.println("Toaster is ready to use.");
    }

    @Override
    public int getChargeLevel() {
        return chargeLevel;
    }

    @Override
    public boolean isCharged() {
        return isCharged;
    }
}
