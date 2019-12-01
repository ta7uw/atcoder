package SPC.B;

import java.io.PrintWriter;
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
            String str = sc.nextLine();
            int N = nint(sc);
            StringBuilder result = new StringBuilder(str.charAt(0));
           for(int i = 0; N*i <str.length() ;i++){
               result.append(str.charAt(N*i)); }
            out.println(result.toString());
        }
    }


    static int nint(Scanner sc){
        return Integer.parseInt(sc.next());
    }


}