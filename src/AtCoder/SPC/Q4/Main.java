package AtCoder.SPC.Q4;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
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
            double startYen = Math.pow(10,15);
            int n = nint(sc);
            int m = nint(sc);
            int s = nint(sc);
            int t = nint(sc);
            List<List<Long>> fares = new ArrayList<>();

            for(int i=0; i<m; i++){
                List<Long> fare= new ArrayList<>();
                fare.add(nlong(sc));
                fare.add(nlong(sc));
                fare.add(nlong(sc));
                fare.add(nlong(sc));
                fares.add(fare);
            }
            int maxYear = n-1;
            boolean changeToSunuke = false;
            for (int year=0; year<=maxYear; year++){

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