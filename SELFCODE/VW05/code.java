import java.io.*;
import java.util.*;

public class code {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        long[][] arr = new long[(int) n + 1][(int) m + 1];
        long[][] pref = new long[(int) n + 1][(int) m + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                long val = Long.parseLong(st.nextToken());
                pref[i][j] =
                    val + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        long ans = Long.MAX_VALUE;

        for (int i = 3; i <= n; i++) {
            for (int j = 3; j <= m; j++) {
                long sum =
                    pref[i][j] -
                    pref[i - 3][j] -
                    pref[i][j - 3] +
                    pref[i - 3][j - 3];
                ans = Math.min(ans, sum);
            }
        }

        System.out.println(ans);
    }
}
