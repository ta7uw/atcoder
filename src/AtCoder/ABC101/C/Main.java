package ABC101.C;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String K = sc.nextLine().replace(" ", "");
        Integer k = Integer.valueOf(K);
        String[] numbers = sc.nextLine().split(" ", 0);
        List<Integer> numbersList = new ArrayList<>();
        for (String n: numbers){
            Integer num = Integer.valueOf(n);
            numbersList.add(num);
        }

        int result = 0;
        int remain ;
        remain = N -k;
        result++;
        if(N==k){
            System.out.println(1);
        }else {
            while (remain >0) {
                remain -= k-1;
                result++;
            }
            System.out.println(result);
        }
    }
}
