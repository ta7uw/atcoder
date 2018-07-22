package AtCoder.BeginnersSelection;

import java.util.Scanner;

public class Practice2 {
    public static void main(String[] atgs){
        Scanner sc = new Scanner(System.in);
        int firstNum = sc.nextInt();
        int secondNum = sc.nextInt();
        if (firstNum * secondNum % 2==0) System.out.println("Even");
        else System.out.println("Odd");
    }
}
