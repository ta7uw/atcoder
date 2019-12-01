package CodeFlyer.A;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<Long> PriceList = new ArrayList<>();
        for (int i=0; i<N;i++){
            Long num = sc.nextLong();
            PriceList.add(num);
        }

        int countZero = 0;
        boolean checkZeroCount = true;
        while (checkZeroCount){
            for (long price: PriceList){
                String priceStr = String.valueOf(price);

                if (!priceStr.substring(priceStr.length()-1-countZero).startsWith("0")){
                    checkZeroCount = false;
                }
            }
            if (checkZeroCount){
                countZero++;
            }
        }
        System.out.println(countZero);


    }
}
