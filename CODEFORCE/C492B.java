import java.io.*;
import java.util.*;

public class C492B {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        float answer = 0;
        for (int i = 0; i < n - 1; i++) {
            answer = Math.max(answer, arr[i + 1] - arr[i]);
        }

        answer = Math.max(answer, l - arr[n - 1]);
        answer = answer / 2;
        System.out.printf("%.10f", answer);
    }
}
