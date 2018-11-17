import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.LongStream;

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
            int w = nint(sc);
            int h = nint(sc);
            int n = nint(sc);

            List<Integer> xList = new ArrayList<>();
            List<Integer> yList = new ArrayList<>();
            List<Integer> aList = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                xList.add(nint(sc));
                yList.add(nint(sc));
                aList.add(nint(sc));
            }

            int[] remainX = new int[w];
            int[] remainY = new int[h];
            int x, y, a;
            for (int i = 0; i < n; i++) {
                a = aList.get(i);
                x = xList.get(i);
                y = yList.get(i);
                switch (a){
                    case 1:
                        for (int j = 0; j < x; j++) {
                            if(remainX[j] == 0){
                                remainX[j] = -1;
                            }
                        }
                        break;
                    case 2:
                        for (int j = x; j < w; j++) {
                            if(remainX[j] == 0){
                                remainX[j] = -1;
                            }
                        }
                        break;
                    case 3:
                        for (int j = 0; j < y; j++) {
                            if(remainY[j] == 0){
                                remainY[j] = -1;
                            }
                        }
                        break;
                    case 4:
                        for (int j = y; j < h; j++) {
                            if(remainY[j] == 0){
                                remainY[j] = -1;
                            }
                        }
                        break;
                }

            }
            int countX = 0, countY = 0;
            for (int i = 0; i < w; i++) {
                x = remainX[i];
                if (x == 0) countX++;
            }
            for (int i = 0; i < h; i++) {
                y = remainY[i];
                if (y == 0) countY++;
            }
            out.println((countX!=0 && countY!=0) ? (countX)*(countY) : 0);
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

    private static long lcm(long a, long b) {
        return a * b / gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}

