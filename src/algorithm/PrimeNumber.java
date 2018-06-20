package algorithm;

import java.util.Iterator;

public class PrimeNumber {

    public static boolean isPrime(int number){
        if (number <= 1) return false;
        else if (number == 2) return true;
        else if (number == 3) return true;
        else {
            int n = (int)Math.sqrt( number );
            for (int i = 2; i  <= n; i++) {
                if (number % i == 0) {
                    return false;
                }
            }
            return true;
        }
    }
    public static  boolean isPrime2(int x) {
        for (int i = 2; i*i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args){

        int count = 0 ;
        for (int i = 2; i <= 10000; i++){
            if (isPrime(i)){
                count ++;
            }
        }
        System.out.println("isPrime: " + count);

        count = 0 ;
        for (int i = 2; i <= 10000; i++){
            if (isPrime2(i)){
                count ++;
            }
        }
        System.out.println("isPrime2: " + count);
    }
}
