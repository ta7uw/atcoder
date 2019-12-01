package ABC101.B;

import java.util.Scanner;

public class Main {

        public static void main(String[] args){
            Scanner sr = new Scanner(System.in);
            String input = sr.nextLine();
            long inputNum = Long.valueOf(input);
            int sum = 0;
            for(int i=0 ; i <input.length(); i++){
               String num =  input.substring(i, i+1);
               Integer numToInt = Integer.valueOf(num);
               sum += numToInt;
            }

            if(inputNum % sum == 0){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }

    }
}
