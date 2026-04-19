import java.io.*;
import java.util.*;

public class thpttd_126_matrix {

    private static final int N = 1000 + 1103;
    private static int[][] arr = new int[N][N];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("test.inp"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("test.out"));

        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr[u][v] = arr[v][u] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 1 && (j != i)) {
                    bw.write(j + " ");
                }
            }
            bw.write("0\n");
        }

        br.close();
        bw.close();
    }
}
