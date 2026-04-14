import java.io.*;
import java.util.*;

public class bs_exam_test_final3 {

    private static boolean[] prime_array = new boolean[(int) 2e5];

    private static void sieve() {
        for (int i = 0; i < (int) 2e5; i++) {
            prime_array[i] = true;
        }
        prime_array[0] = prime_array[1] = false;
        for (int i = 2; i * i < (int) 2e5; i++) {
            if (prime_array[i]) {
                for (int j = i * i; j < (int) 2e5; j += i) {
                    prime_array[j] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        sieve();
        StringTokenizer st = new StringTokenizer(br.readLine());
        long k = Long.parseLong(st.nextToken());
        long index = 0;
        for (int i = 2; i <= k; i++) {
            if (prime_array[i]) {
                for (int j = i; j <= k; j++) {
                    if (prime_array[j]) {
                        for (int l = j; l <= k; l++) {
                            if (prime_array[l]) {
                                if (i + j + l == k) index++;
                            }
                        }
                    }
                }
            }
        }
        System.out.println(index);
    }
}
