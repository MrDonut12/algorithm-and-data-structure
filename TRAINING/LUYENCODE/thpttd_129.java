import java.io.*;
import java.util.*;

public class thpttd_129 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("BDEL.inp"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("BDEL.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            HashMap<Integer, Integer> mp = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int x = Integer.parseInt(st.nextToken());
                if (!mp.containsKey(x)) {
                    mp.put(x, 1);
                    bw.write(x + " ");
                }
            }

            bw.write("\n");
        }
    }
}
