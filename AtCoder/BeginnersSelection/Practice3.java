package AtCoder.BeginnersSelection;

import java.util.Scanner;

public class Practice3 {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        int count = 0;
        for (int i =0; i<3;i++){
            String num =line.substring(i,i+1);
            if (num.equals("1")){
                count++;
            }
        }
        System.out.println(count);
    }
}
