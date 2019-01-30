package EDPC.S.Main;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

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
            String K = nstr(sc);
            int D = nint(sc);
            int mod = (int) 1e9 + 7;

            int length = K.length();
            long[][][] dp = new long[length + 1][2][D];
            dp[0][0][0] = 1;

            for (int i = 0; i < length; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < D; k++) {
                        int x;
                        if (j == 1) {
                            x = 9;
                        } else {
                            x = K.charAt(i) - '0';
                        }
                        for (int d = 0; d <= x; d++) {
                            if (j == 1) {
                                dp[i + 1][1][(k + d) % D] += dp[i][j][k];

                            } else if (d < x) {
                                dp[i + 1][1][(k + d) % D] += dp[i][j][k];

                            } else {
                                dp[i + 1][0][(k + d) % D] += dp[i][j][k];

                            }
                            dp[i + 1][1][(k + d) % D] %= mod;
                            dp[i + 1][0][(k + d) % D] %= mod;
                        }
                    }
                }
            }
            long ans = 0;
            for (int i = 0; i < 2; i++) {
                ans += dp[length][i][0];
                ans %= mod;
            }
            out.println((ans + mod - 1) % mod);
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
        return String.valueOf(sc.next());
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

