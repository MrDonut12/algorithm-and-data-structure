import java.io.*;
import java.util.*;

public class thpttd_126_adj {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("test.inp"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("test.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            adj[u].add(v);
            adj[v].add(u);
        }

        for (int i = 1; i <= n; i++) {
            Collections.sort(adj[i]);
        }

        for (int i = 1; i <= n; i++) {
            StringBuilder sb = new StringBuilder();

            for (int v : adj[i]) {
                if (v != i) {
                    sb.append(v).append(" ");
                }
            }

            sb.append("0\n");
            bw.write(sb.toString());
        }

        br.close();
        bw.close();
    }
}
