import java.io.*;
import java.util.*;

public class bs_exam_2_1 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n + 1];
        long answer = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int left = 0,
            right = n - 1;
        while (left < right) {
            long area = (long) Math.min(arr[left], arr[right]) * (right - left);
            answer = Math.max(answer, area);

            if (arr[left] < arr[right]) left++;
            else {
                right--;
            }
        }
        System.out.println(answer);
    }
}
