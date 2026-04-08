import java.io.*;
import java.util.*;

public class LRU {

    private static long t, n;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        t = Long.parseLong(br.readLine());
        while (t-- > 0) {
            n = Integer.parseInt(br.readLine());
            int sla = 0,
                slb = 0;
            if (n == 1) {
                System.out.println(0);
                continue;
            }
            while (n % 2 == 0) {
                sla++;
                n /= 2;
            }
            while (n % 3 == 0) {
                slb++;
                n /= 3;
            }

            if (n != 1 || (sla > slb)) {
                System.out.println(-1);
                continue;
            }
            System.out.println(2 * slb - sla);
        }
    }
}
