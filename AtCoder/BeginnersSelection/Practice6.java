package AtCoder.BeginnersSelection;


import java.io.PrintWriter;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Practice6 {
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
            int A = nint(sc);
            int B = nint(sc);
            int result = 0;
            for (int i = 1; i<=N; i++ ){
                int sum = 0;
                int tmp = i;
                while(tmp!=0){
                    sum += tmp %10;
                    tmp /= 10;
                }
                if (A <= sum && sum <= B){
                    result += i;
                }
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

    static long maxFromList(List<Long> longList){
        return longList.stream().max(Comparator.naturalOrder()).get();
    }
    static long minFromList(List<Long> longList){
        return longList.stream().min(Comparator.naturalOrder()).get();
    }
}
