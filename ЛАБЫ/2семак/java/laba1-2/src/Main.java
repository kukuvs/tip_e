public class Main{

    public static void main(String[] args) {
        int result;
        char[] operations = {'+', '-', '*', '/'};

        for (char op1 : operations) {
            for (char op2 : operations) {
                for (char op3 : operations) {
                    for (char op4 : operations) {
                        for (char op5 : operations) {
                            result = calculate(1, 2, op1, 3, op2, 4, op3, 5, op4, 6, op5);
                            if (result == 35) {
                                System.out.println("Solution found: " + "1" + op1 + "2" + op2 + "3" + op3 + "4" + op4 + "5" + op5 + "6 = " + result);
                                return;
                            }
                        }
                    }
                }
            }
        }
        System.out.println("No solution found.");
    }

    public static int calculate(int a, int b, char op1, int c, char op2, int d, char op3, int e, char op4, int f, char op5) {
        int result = a;
        result = applyOperation(result, b, op1);
        result = applyOperation(result, c, op2);
        result = applyOperation(result, d, op3);
        result = applyOperation(result, e, op4);
        result = applyOperation(result, f, op5);
        return result;
    }

    public static int applyOperation(int x, int y, char op) {
        return switch (op) {
            case '+' -> x + y;
            case '-' -> x - y;
            case '*' -> x * y;
            case '/' -> x / y;
            default -> throw new IllegalArgumentException("Invalid operation: " + op);
        };
    }
}