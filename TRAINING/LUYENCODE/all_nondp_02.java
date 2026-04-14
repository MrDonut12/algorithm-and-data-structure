import java.io.*;
import java.util.*;

public class all_nondp_02 {

    private static boolean check(long sum, long[] arr, int n, long K) {
        int left = 0;
        long index = 0;
        long curr_sum = 0;

        for (int right = 0; right < n; right++) {
            curr_sum += arr[right];

            while (curr_sum > sum && left <= right) {
                curr_sum -= arr[left++];
            }

            index += (right - left + 1);
        }

        return index >= K;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        long sum = 0;

        // read Array
        st = new StringTokenizer(br.readLine());
        long[] arr = new long[(int) n];
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
            sum += arr[i];
        }

        long left = 0,
            right = sum * 5,
            ans = sum;
        while (left <= right) {
            long curr_sum = left + (right - left) / 2;
            if (check(curr_sum, arr, n, K)) {
                ans = curr_sum;
                right = curr_sum - 1;
            } else {
                left = curr_sum + 1;
            }
        }

        System.out.println(ans);
    }
}
