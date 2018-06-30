package AtCoder.CodeFlyer;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.io.PrintWriter;

public class B {
    public static void main(String[] args){
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int Q = Integer.parseInt(sc.next());
        List<Long> XList = new ArrayList<>();
        for (int i=0; i<N; i++){
            long X = Long.parseLong(sc.next());
            XList.add(X);
        }
        for (int i=0; i<Q; i++){
            long c = Long.parseLong(sc.next());
            long d = Long.parseLong(sc.next());
            long sum = 0;
            for (long x:XList){
                if (Math.abs(x - c) <= d){
                    sum += Math.abs(x -c);
                }else {
                    sum += d;
                }
            }
            out.println(sum);
        }
        out.flush();
    }
}
