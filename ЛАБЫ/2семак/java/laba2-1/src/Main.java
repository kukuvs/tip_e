
public class Main {
    //
    public static void main(String[] args) {

        String s = null;
        long x = System.currentTimeMillis();

        for (int  i = 0; i < 1000000; i++)
        {
            if (i%2==0)
            {
                s = UpToTen(16);
            } else {
                s = UpToTen(56);
            }
        }

        long y = System.currentTimeMillis();
        System.out.println(s);

        System.out.println(Long.toString(y-x)+" ms");

    }
    // Напишите функцию static int UpToTen (int n), которая по данному натуральному числу n
    //возвращает число, полученное из n следующим образом: для каждой цифры i числа n в новом числе
    //ставится цифра 10-i, цифра 0 остается без изменений (например, при вводе 1079 программа выводит
    //9031). Определите время работы функции для 1000000 повторов.
    public  static String UpToTen (int n)
    {
        String s = Integer.toString(n);
        StringBuilder fin = new StringBuilder();
        for (int i = 0; i < s.length(); i++)
        {
            String v = String.valueOf(s.charAt(i));
            fin.append(Integer.toString((10 - Integer.parseInt(v))));
        }

        return fin.toString();
    }

}