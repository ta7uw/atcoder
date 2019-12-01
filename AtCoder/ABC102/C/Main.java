package ABC102.C;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        TaskC task = new TaskC();

        task.solve(sc, out);
        out.flush();
        sc.close();
    }
    static class TaskC{
        void solve(Scanner sc, PrintWriter out){
            int N = nint(sc);
            long[] lLine = longLine(sc, N);
            long[] AminusN = new long[N];
            for (int i = 0; i < N; i++) {
                AminusN[i] = lLine[i] - (i+1);
            }
            Arrays.sort(AminusN);
            long b;
            if (N%2==0){
                b = AminusN[N/2 -1];
            }else{
                b = AminusN[(N+1)/2 -1];
            }
            long result = 0;
            for (long a: AminusN){
                result += Math.abs(a - b);
            }
            out.println(result);

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