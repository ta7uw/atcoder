package AtCoder.BeginnersSelection;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class Practice4 {
    public static void  main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Integer[] array = new Integer[N];
        for (int i=0; i<N; i++){
            Integer num = sc.nextInt();
            array[i] = num;
        }
        int count = 0;
        Stream<Integer> stream = Arrays.asList(array).stream();
        while (stream.filter(s-> s%2 ==0).count() == N){
            count ++;
            stream = stream.map(s-> s/2);
            stream.forEach(System.out::println);
        }
        System.out.println(count);
    }
}
