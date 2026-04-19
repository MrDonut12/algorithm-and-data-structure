import java.io.*;
import java.util.*;

public class thpttd_127 {

    private static final int N = 200000 + 1103;
    private static boolean[] primes = new boolean[N];

    private static void sieveEratosthenes() {
        for (int i = 0; i < N; i++) {
            primes[i] = true;
        }
        primes[0] = primes[1] = false;

        for (int i = 2; i * i < N; i++) {
            if (primes[i]) {
                for (int j = i * i; j < N; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    private static boolean check(int num) {
        String numString = String.valueOf(num);
        int n = numString.length();
        for (int i = 0; i < n; i++) {
            if (
                numString.charAt(i) != numString.charAt(n - i - 1)
            ) return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new FileReader("SumOfPrimes.inp")
        );
        BufferedWriter bw = new BufferedWriter(
            new FileWriter("SumOfPrimes.out")
        );
        sieveEratosthenes();

        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());
            int curr_sum = 0;
            for (int i = left; i <= right; i++) {
                if (check(i) && primes[i]) {
                    curr_sum += i;
                }
            }
            bw.write(curr_sum + "\n");
        }
        br.close();
        bw.close();
    }
}
