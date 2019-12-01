package CTF2017.B;

import java.io.PrintWriter;
import java.util.*;


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
        void solve(Scanner sc, PrintWriter out) {
            String S = nstr(sc);
            char[] s = S.toCharArray();
            int n = S.length();
            char[] t = new char[n];
            for (int i = 0; i < n - 1; i++) {
                t[i] = '#';
            }
            for (int i = 0; i < n; i++) {
                StringBuilder sb = new StringBuilder();
                sb.append(S);
                for (int j = 0; j < i; j++) {
                    sb.append(t[j]);
                }
                String now = sb.toString();
                char[] nowChar = now.toCharArray();
                int m = n + i;
                int half = m / 2;
                boolean f = true;
                for (int j = 0; j < half; j++) {
                    if (nowChar[j] != nowChar[m - 1 - j] && nowChar[m - 1 - j] != '#') {
                        f = false;
                    }
                }
                if (f) {
                    out.println(i);
                    break;
                }
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

    static List<String> getStringList(Scanner sc, int size) {
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
            i++;
        }
        if (num > 1)
            map.put((int) num, 1);
        return map;
    }

    /**
     * Returns the most frequent value in the list. リスト内で最頻出数値を返します。
     *
     * @param list List
     * @return most frequent value
     */
    private static Integer getMode(List<Integer> list) {
        if (list.size() <= 0) {
            throw new IllegalArgumentException();
        }

        Map<Integer, Integer> modeMap = new HashMap<>();

        for (Integer x : list) {
            if (modeMap.containsKey(x)) {
                modeMap.put(x, modeMap.get(x) + 1);
            } else {
                modeMap.put(x, 1);
            }
        }
        return modeMap.entrySet().stream()
                .max(Map.Entry.comparingByValue())
                .get()
                .getKey();

    }
}


