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
            List<Long> aList = getLongList(sc, n);

            long sum = 0;
            long result1 = 0;
            long result2 = 0;

            long margin = 0;
            // even +1
            for (int i = 0; i < n; i++) {
                sum += aList.get(i);
                if (i%2 == 0){
                    if (sum>0){
                        continue;
                    }else {
                        margin = Math.abs(sum)+1;
                        result1 += margin;
                        sum = 1;
                    }
                }else {
                    if (sum<0){
                        continue;
                    }else {
                        margin = Math.abs(sum)+1;
                        result1 += margin;
                        sum = -1;
                    }
                }
            }
            sum = 0;
            // even -1
            for (int i = 0; i < n; i++) {
                sum += aList.get(i);
                if (i%2 == 0){
                    if (sum<0){
                        continue;
                    }else {
                        margin = Math.abs(sum)+1;
                        result2 += margin;
                        sum = -1;
                    }
                }else {
                    if (sum>0){
                        continue;
                    }else {
                        margin = Math.abs(sum)+1;
                        result2 += margin;
                        sum = 1;
                    }
                }
            }
            out.println(Math.min(result1, result2));


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
}
