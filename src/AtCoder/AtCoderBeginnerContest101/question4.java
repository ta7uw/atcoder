package AtCoder.AtCoderBeginnerContest101;

import java.util.Scanner;

public class question4 {
    public static void main(String[] args){
        Scanner sr = new Scanner(System.in);
        String inputLine = sr.nextLine();
        Integer K = Integer.valueOf(inputLine);
        int count = 0;
        int n = 1;

        while (count != K){
            String nSr = String.valueOf(n);
            int Sn = 0;

            for (int i=0;i<nSr.length();i++){
                Sn += Integer.valueOf(nSr.substring(i,i+1));
            }
            int m = n + 1;
            int Sm = 0;
            String mSr = String.valueOf(m);
            for (int i=0;i<mSr.length();i++){
                Sm += Integer.valueOf(mSr.substring(i,i+1));
            }

            boolean checksunuke = true;
            for(int i =0; i <= 100; i++){
                if (n/Sn <= m/Sm) {
                    continue;
                }else {
                    checksunuke = false;
                }
                m++;
                Sm = 0;
                mSr = String.valueOf(m);
                for (int j = 0; j < mSr.length(); j++) {
                    Sm += Integer.valueOf(mSr.substring(j, j+1));
                }
            }
            if (checksunuke){
                System.out.println(n);
            }
            count++;
            n++;

        }


    }
}
