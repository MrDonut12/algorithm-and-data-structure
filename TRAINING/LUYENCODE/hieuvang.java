import java.io.*;
import java.util.*;

public class hieuvang {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] arr = new long[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        long ans = 0;
        long minCompare = arr[0];
        for (int i = 1; i < n; i++) {
            ans = Math.max(arr[i] - minCompare, ans);
            minCompare = Math.min(arr[i], minCompare);
        }

        System.out.println(ans);
    }
}
