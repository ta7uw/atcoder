package AtCoder.BeginnersSelection;



import java.io.PrintWriter;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Practice5 {
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
            int A = nint(sc);
            int B = nint(sc);
            int C = nint(sc);
            int X = nint(sc);

            long count = 0;
            for (int i=0; i<=A; i++){
                for (int j=0; j<=B; j++){
                    for (int k=0; k<=C; k++){
                        if (500*i + 100*j + 50*k ==X){
                            count++;
                        }
                    }
                }
            }
            out.println(count);
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