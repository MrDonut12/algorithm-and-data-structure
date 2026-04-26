import java.io.*;
import java.util.*;

public class C750A {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        final int MAXN = 240;
        if (t >= MAXN) {
            System.out.println(0);
        } else {
            int remainTime = MAXN - t;
            int answer = 0;
            int index = 0;
            for (int i = 1; i <= n; i++) {
                index += i * 5;
                answer++;
                if (index > remainTime) {
                    System.out.println(--answer);
                    return;
                }
            }
            answer -= (index > remainTime) ? 1 : 0;
            System.out.println(answer);
        }
    }
}
