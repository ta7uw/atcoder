package AtCoder.ABC103.C;


import java.io.PrintWriter;
import java.util.Scanner;

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
            int N = nint(sc);
            long[] AList = longLine(sc, N);
            long result = 0;
            for (int i=0; i<AList.length; i++){
               result += AList[i] -1;
            }
            out.println(result);
        }
    }
    private static long lcm(long a, long b){
        return a * b /gcd( b, a % b);
    }
    private static long gcd(long a, long b){
        if (a < b) return gcd(b ,a );
        return b == 0 ? a : gcd( b, a % b);
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