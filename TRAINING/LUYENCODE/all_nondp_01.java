import java.io.*;
import java.util.*;

public class all_nondp_01 {

    private static boolean check(long mid, long[] arr, long n, long x) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (int) arr[i] / mid;
        }
        return (sum >= x);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long x = Long.parseLong(st.nextToken());
        long[] arr = new long[(int) n];
        long curr_sum = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
            curr_sum += arr[i];
        }

        long ans = 0;
        long left = 1,
            right = curr_sum;
        while (left <= right) {
            long mid = (left + right) >> 1;
            if (check(mid, arr, n, x)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(ans);
    }
}
