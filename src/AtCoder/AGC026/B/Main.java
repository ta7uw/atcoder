package AtCoder.AGC026.B;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Main {
    public static void main(String[] args){
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        Task task = new Task();
        task.solve(sc, out);
        out.flush();
        sc.close();
    }
    static class Task{
        public void solve(Scanner sc, PrintWriter out){
            int T = nint(sc);
            List<long[]> inputLine = new ArrayList<>();
            for (int i= 0 ; i < T; i++){
                long[] line = longLine(sc, 4);
                inputLine.add(line);
            }
            for (int i=0; i<T; i++){
                long A = inputLine.get(i)[0];
                long B = inputLine.get(i)[1];
                long C = inputLine.get(i)[2];
                long D = inputLine.get(i)[3];

                if (A < B){
                    // 初日アウト
                    out.println("No");
                    continue;
                }
                if(B > D){
                    // 必ずいつか尽きる
                    out.println("No");
                    continue;
                }

                if (C >= B ){
                    // 危ない状況にならない
                    out.println("Yes");
                    continue;
                }

                long remain = A % B;
                long div = D / B;
                long margin = D - B;
                long result = remain;
                if (div >=1){
                    if (margin !=0){
                        for (long j = 1; result <C+1; j++){
                            result +=margin;
                        }
                    }else{
                        if(remain <= C){
                            out.println("Yes");
                            continue;
                        }else {
                            out.println("No");
                            continue;
                        }
                    }
                    if (result >= B){
                        out.println("Yes");
                    }else {

                        out.println("No");
                    }
                }else {
                    out.println("Yes");
                }
            }
        }
    }

    static int nint(Scanner sc){
        return Integer.parseInt(sc.next());
    }
    static long nlong(Scanner sc){
        return Long.parseLong(sc.next());
    }
    static double ndouble(Scanner sc){
        return Double.parseDouble(sc.next());
    }
    static float nfloat(Scanner sc){
        return Float.parseFloat(sc.next());
    }
    static String nstr(Scanner sc){
        return  String.valueOf(sc.next());
    }
    static long[] longLine(Scanner sc, int size){
        long[] lLine = new long[size];
        for (int i = 0; i < size; i++) {
            lLine[i] = nlong(sc);
        }
        return lLine;
    }
    static int[] intLine(Scanner sc, int size){
        int[] iLine = new int[size];
        for (int i = 0; i < size; i++) {
            iLine[i] = nint(sc);
        }
        return iLine;
    }
    static String[] strLine(Scanner sc, int size){
        String[] strLine = new String[size];
        for (int i = 0; i < size; i++) {
            strLine[i] = nstr(sc);
        }
        return strLine;
    }
}