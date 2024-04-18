import java.util.Random;

public class RandomStringGenerator {
    public static void main(String[] args) {
        int length = 10; // Длина строки l
        String s = ( generateRandomString(length));
        System.out.println("Случайная строка: "+s);
        System.out.println("поменяли " +s.replace('!', '_'));// Замените все вхождения символа '!' на '_'
    }

    public static String generateRandomString(int length) {
        String characters = "jklmnopqr012345?!;";
        StringBuilder sb = new StringBuilder();
        Random random = new Random();

        for (int i = 0; i < length; i++) {
            int index = random.nextInt(characters.length());
            sb.append(characters.charAt(index));
        }

        return sb.toString();
    }
}
