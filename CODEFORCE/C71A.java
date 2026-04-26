import java.io.*;
import java.util.*;

public class C71A {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            String str = (st.nextToken());
            String abbrStr =
                "" +
                str.charAt(0) +
                (str.length() - 2) +
                str.charAt(str.length() - 1);
            if (str.length() <= 10) System.out.println(str);
            else System.out.println(abbrStr);
        }
    }
}
