import java.io.PrintWriter;
import java.util.*;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
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
        public void solve(Scanner sc, PrintWriter out){
            int n = nint(sc);
            int a = nint(sc);
            List<Integer> xList = getIntegerList(sc, n);
            long[][][] dp = new long[n+1][n+1][n * 50 + 1];
 
            dp[0][0][0] = 1;
            for (int i = 1; i <= n; i++) {
                int x = xList.get(i-1);
                for (int j = 0; j <= i; j++) {
                    for (int k = 0; k < dp[i][j].length; k++) {
                        if (j-1 >= 0 && k -x >=0){
                            dp[i][j][k] += dp[i-1][j-1][k-x];
                        }
                        dp[i][j][k] += dp[i-1][j][k];
 
                    }
                }
            }
 
            long count = 0;
            for (int i = 1; i <= n; i++) {
                int s = i*a;
                count += dp[n][i][s];
            }
            out.println(count);
 
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
 
    static List<String> getStringList(Scanner sc, int size){
        List<String> stringList = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            stringList.add(nstr(sc));
        }
        return stringList;
    }
 
    private static long lcm(long a, long b) {
        return a * b / gcd(b, a % b);
    }
 
    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    private static Map<Integer, Integer> primeFactorize(long num) {
        Map<Integer, Integer> map = new HashMap<>();
        int i = 2;
        while (i * i <= num) {
            while (num % i == 0) {
                num /= i;
                if (map.containsKey(i)) {
                    int tmp = map.get(i);
                    tmp++;
                    map.put(i, tmp);
                } else {
                    map.put(i, 1);
                }
            }
            i ++;
        }
        if (num > 1)
            map.put((int) num, 1);
        return map;
    }
}
import java.io.PrintWriter;
import java.util.*;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
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
        public void solve(Scanner sc, PrintWriter out){
            int n = nint(sc);
            int a = nint(sc);
            List<Integer> xList = getIntegerList(sc, n);
            long[][][] dp = new long[n+1][n+1][n * 50 + 1];

            dp[0][0][0] = 1;
            for (int i = 1; i <= n; i++) {
                int x = xList.get(i-1);
                for (int j = 0; j <= i; j++) {
                    for (int k = 0; k < dp[i][j].length; k++) {
                        if (j-1 >= 0 && k -x >=0){
                            dp[i][j][k] += dp[i-1][j-1][k-x];
                        }
                        dp[i][j][k] += dp[i-1][j][k];

                    }
                }
            }

            long count = 0;
            for (int i = 1; i <= n; i++) {
                int s = i*a;
                count += dp[n][i][s];
            }
            out.println(count);

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

    static List<String> getStringList(Scanner sc, int size){
        List<String> stringList = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            stringList.add(nstr(sc));
        }
        return stringList;
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    private static Map<Integer, Integer> primeFactorize(long num) {
        Map<Integer, Integer> map = new HashMap<>();
        int i = 2;
        while (i * i <= num) {
            while (num % i == 0) {
                num /= i;
                if (map.containsKey(i)) {
                    int tmp = map.get(i);
                    tmp++;
                    map.put(i, tmp);
                } else {
                    map.put(i, 1);
                }
            }
            i ++;
        }
        if (num > 1)
            map.put((int) num, 1);
        return map;
    }
}

