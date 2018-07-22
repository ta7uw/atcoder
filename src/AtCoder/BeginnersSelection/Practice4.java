package AtCoder.BeginnersSelection;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Practice4 {
    public static void  main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<Long> inputList = new ArrayList<>();
        for (int i=0; i<N; i++){
            long num = sc.nextLong();
            inputList.add(num);
        }
        long count = 0;
        Stream<Long> stream = inputList.stream();
        while (stream.filter(s-> s%2 ==0).count() == N){
            count ++;
            final long tmp = (long)Math.pow(2, count);
            List<Long> newList = inputList.stream().map(s -> s/tmp).collect(Collectors.toList());
            stream = newList.stream();
        }
        System.out.println(count);
    }
}
