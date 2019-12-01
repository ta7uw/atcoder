package ABC101.A;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sr = new Scanner(System.in);
        String inputLine = sr.nextLine();
        int result = 0;
        if (inputLine.length() == 4) {
            for (int i = 0; i < inputLine.length(); i++) {
                String plusOrMinus = inputLine.substring(i, i + 1);
                if (plusOrMinus.equals("+")) {
                    result++;
                } else {
                    result--;
                }
            }
        }
        System.out.println(result);
    }

}
