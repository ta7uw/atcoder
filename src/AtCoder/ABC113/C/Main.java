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
            List<List<Integer>> inputList = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int p = nint(sc);
                int y = nint(sc);
                List<Integer> ipy = new ArrayList<>();
                ipy.add(i);
                ipy.add(p);
                ipy.add(y);
                inputList.add(ipy);
            }
            inputList = inputList.stream()
                                   .sorted(Comparator.comparingInt((List<Integer> x) -> x.get(1))
                                           .thenComparingInt((List<Integer> x) -> x.get(2)))
                                   .collect(Collectors.toList());
            Map<Integer, Integer> countMap = new HashMap<>();
            Map<Integer, List<Integer>> result = new HashMap<>();
            for (List<Integer> list : inputList){
                int index = list.get(0);
                int p = list.get(1);
                if (countMap.containsKey(p)){
                    int count = countMap.get(p) + 1;
                    countMap.put(p, count);

                }else{
                    countMap.put(p, 1);
                }
                List<Integer> r = new ArrayList<>();
                r.add(p);
                r.add(countMap.get(p));
                result.put(index, r);
            }
            result.entrySet()
                    .stream()
                    .sorted(Map.Entry.comparingByKey())
                    .map(e -> String.format("%06d", e.getValue().get(0)) + String.format("%06d", e.getValue().get(1)))
                    .forEach(out::println);


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

