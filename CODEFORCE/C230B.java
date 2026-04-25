import java.io.*;
import java.util.*;

public class C230B {

    private static final long MAXN = 2000000;
    private static boolean[] prime = new boolean[(int) MAXN];

    private static void sieve() {
        for (int i = 0; i < MAXN; i++) {
            prime[i] = true;
        }
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < MAXN; i++) {
            if (prime[i]) {
                for (int j = i * i; j < MAXN; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    private static boolean check_t_prime(long n) {
        long sqrn = (long) Math.sqrt(n);
        return (sqrn * sqrn == n && prime[(int) sqrn]);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        sieve();
        st = new StringTokenizer(br.readLine());
        while (n-- > 0) {
            long x = Long.parseLong(st.nextToken());
            if (check_t_prime(x)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
