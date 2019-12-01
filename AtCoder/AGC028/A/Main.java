package AGC028.A;


import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        Task task = new Task();
        task.solve(sc, out);
        out.flush();
        sc.close();
    }

    static class Task {
        public void solve(Scanner sc, PrintWriter out) {
            int n = nint(sc);
            int m = nint(sc);
            String S = nstr(sc);
            String T = nstr(sc);

            long L = lcm(n, m);
            boolean f = false;

            long sStep =  L / n;
            long tStep =  L / m;
            long sL =  lcm(sStep, tStep);

            long s = 0;
            long t = 0;
            for (long i =0; i<=L ;i+=sL){
                if (i == 0){
                    if (String.valueOf(S.charAt(0)).equals(String.valueOf(T.charAt(0)))){
                        continue;
                    }else {
                        f = true;
                        break;
                    }

                }else{
                    s = i / sStep;
                    t = i / tStep;
                    if(s > n-1) break;
                    if(t > m-1) break;
                    if (String.valueOf(S.charAt((int) s)).equals(String.valueOf(T.charAt((int) t)))){
                        continue;
                    }else{
                        f = true;
                        break;
                    }
                }
            }
            if (f){
                out.println(-1);
            }else {
                out.println(L);
            }

        }
    }


    static int nint(Scanner sc) {
        return Integer.parseInt(sc.next());
    }

    static long nlong(Scanner sc) {
        return Long.parseLong(sc.next());
    }

    static double ndouble(Scanner sc) {
        return Double.parseDouble(sc.next());
    }

    static float nfloat(Scanner sc) {
        return Float.parseFloat(sc.next());
    }

    static String nstr(Scanner sc) {
        return sc.next();
    }

    static long[] longLine(Scanner sc, int size) {
        long[] lLine = new long[size];
        for (int i = 0; i < size; i++) {
            lLine[i] = nlong(sc);
        }
        return lLine;
    }

    static int[] intLine(Scanner sc, int size) {
        int[] iLine = new int[size];
        for (int i = 0; i < size; i++) {
            iLine[i] = nint(sc);
        }
        return iLine;
    }

    static String[] strLine(Scanner sc, int size) {
        String[] strLine = new String[size];
        for (int i = 0; i < size; i++) {
            strLine[i] = nstr(sc);
        }
        return strLine;
    }

    static long maxFromList(List<Long> longList) {
        return longList.stream().max(Comparator.naturalOrder()).get();
    }

    static long minFromList(List<Long> longList) {
        return longList.stream().min(Comparator.naturalOrder()).get();
    }

    public static int sumDigits(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static long sumDigits(long n) {
        long sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    static List<Integer> getIntegerList(Scanner sc, int size) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(nint(sc));
        }
        return list;
    }

    static List<Long> getLongList(Scanner sc, int size) {
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(nlong(sc));
        }
        return list;
    }
    private static long lcm(long a, long b){
        return a * b /gcd( b, a % b);
    }

    private static long gcd(long a, long b){
        return b == 0 ? a : gcd( b, a % b);
    }
}

