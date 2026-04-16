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

    private static long countCouple(long secondNum, long target) {
        long index = 0;
        for (long i = secondNum; i <= target; i++) {
            if (!prime_array[(int) i]) {
                continue;
            }

            long thirdNum = target - i;
            if (
                thirdNum >= 2 &&
                thirdNum <= target &&
                prime_array[(int) thirdNum] &&
                thirdNum >= i
            ) {
                index++;
            }
        }
        return index;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        sieve();
        StringTokenizer st = new StringTokenizer(br.readLine());
        long k = Long.parseLong(st.nextToken());
        long index = 0;
        for (long firstNum = 2; firstNum <= k; firstNum++) {
            if (prime_array[(int) firstNum]) {
                long target = k - firstNum;
                index += countCouple(firstNum, target);
            }
        }
        System.out.println(index);
    }
}
