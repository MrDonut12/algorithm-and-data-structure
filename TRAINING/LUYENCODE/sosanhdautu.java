import java.io.*;
import java.util.*;

public class sosanhdautu {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            long pA = Long.parseLong(st.nextToken());
            long cA = Long.parseLong(st.nextToken());
            long rA = Long.parseLong(st.nextToken());
            long fA = Long.parseLong(st.nextToken());
            long pB = Long.parseLong(st.nextToken());
            long cB = Long.parseLong(st.nextToken());
            long rB = Long.parseLong(st.nextToken());
            long fB = Long.parseLong(st.nextToken());
            long n = Long.parseLong(st.nextToken());
            long ans = -1;

            if (pA >= pB) {
                System.out.println(0);
                continue;
            }
            long planA = pA,
                planB = pB;
            for (int i = 1; i <= n; i++) {
                planA = planA + (planA * rA) / 10000;
                planA += cA;
                planA -= fA;
                if (planA < 0) planA = 0;

                planB = planB + (planB * rB) / 10000;
                planB += cB;
                planB -= fB;

                if (planB < 0) planB = 0;

                if (planA >= planB) {
                    ans = i;
                    break;
                }
            }
            System.out.println(ans);
        }
    }
}
