import java.io.*;
import java.util.*;

public class thpttd_128 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("APERM.INP"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("APERM.OUT"));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            pq.add(x);

            if (pq.size() > k) {
                pq.poll();
            }

            if (i >= k - 1) {
                //bw.write(pq.peek() + "\n");
                System.out.println(pq.peek());
            }
        }
        br.close();
        bw.close();
    }
}
