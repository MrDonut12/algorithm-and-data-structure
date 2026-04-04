import java.io.*;
import java.util.*;

public class gopmuctieu {

    static boolean check(long p, long x, long r, long n, long C) {
        long A = p;
        for (int i = 0; i < n; i++) {
            A = (A * (10000 + r)) / 10000 + C;
            if (A >= x) {
                return true;
            }
        }
        return (A >= x);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            long p = Long.parseLong(st.nextToken());
            long x = Long.parseLong(st.nextToken());
            long r = Long.parseLong(st.nextToken());
            long n = Long.parseLong(st.nextToken());

            if (x <= p) {
                System.out.println(0);
            } else if (n == 0 && p < x) {
                System.out.println(-1);
            } else {
                long C = 0;
                long left = 0,
                    right = (long) 1e18,
                    g;
                while (left <= right) {
                    g = (left + right) >> 1;
                    if (check(p, x, r, n, g)) {
                        C = g;
                        right = g - 1;
                    } else {
                        left = g + 1;
                    }
                }

                System.out.println(C);
            }
        }
    }
}
