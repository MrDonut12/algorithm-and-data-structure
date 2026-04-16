import java.io.*;
import java.util.*;

public class Fence_Painting {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("paint.in"));
        PrintWriter out = new PrintWriter(new FileWriter("paint.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int ans;

        if (b < c || d < a) {
            ans = (b - a) + (d - c);
        } else {
            ans = Math.max(b, d) - Math.min(a, c);
        }

        out.println(ans);

        out.close();
        br.close();
    }
}
