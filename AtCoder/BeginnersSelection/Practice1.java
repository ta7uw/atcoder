package AtCoder.BeginnersSelection;

import java.util.Scanner;

public class Practice1 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String firstNum = scanner.nextLine();
        String secondNum = scanner.next();
        String thirdNum = scanner.nextLine().replace(" ", "");
        String str = scanner.nextLine();
        int sum = Integer.valueOf(firstNum) + Integer.valueOf(secondNum) + Integer.valueOf(thirdNum);
        System.out.println(sum +" "+ str);

        }

}
