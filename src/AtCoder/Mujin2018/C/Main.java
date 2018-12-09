package Mujin2018.C;

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
        public void solve(Scanner sc, PrintWriter out) {
            int N = nint(sc);
            int M = nint(sc);
            boolean[][] map = new boolean[N][M];
            int[][][] count = new int[4][N][M];
            for (int i = 0; i < N; i++) {
                char[] row = sc.next().toCharArray();
                for (int j = 0; j < M; j++) {
                    map[i][j] = row[j] == '#';
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (map[i][j]) continue;
                    count[0][i][j] = (i == 0 ? 0 : count[0][i - 1][j]) + 1;
                    count[3][i][j] = (j == 0 ? 0 : count[3][i][j - 1]) + 1;
                }
            }
            for (int i = N - 1; i >= 0; i--) {
                for (int j = M - 1; j >= 0; j--) {
                    if (map[i][j]) continue;
                    count[1][i][j] = (j == M - 1 ? 0 : count[1][i][j + 1]) + 1;
                    count[2][i][j] = (i == N - 1 ? 0 : count[2][i + 1][j]) + 1;
                }
            }
            long answer = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (map[i][j]) continue;
                    for (int k = 0; k < 4; k++) {
                        answer += (count[k][i][j] - 1) * (count[(k + 1) % 4][i][j] - 1);
                    }
                }
            }
            out.println(answer);
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

