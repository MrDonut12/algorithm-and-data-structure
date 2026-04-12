import java.io.*;
import java.util.*;

public class LRU {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        Deque<Integer> dq = new ArrayDeque<>();
        Map<Integer, Integer> map = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int capacity = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int currCapacity = 0;
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            String cmds = st.nextToken();
            if (cmds.equals("put")) {
                currCapacity++;

                if (currCapacity > capacity) {
                    map.remove(dq.peekLast());
                    dq.removeLast();
                }
                int first = Integer.parseInt(st.nextToken());
                int second = Integer.parseInt(st.nextToken());
                map.put(first, second);
                dq.addFirst(first);
            } else {
                // cmds == get
                int key = Integer.parseInt(st.nextToken());
                if (map.get(key) == null) {
                    System.out.println(-1);
                } else {
                    System.out.println(map.get(key));
                    int lastElement = dq.peekLast();
                    dq.addFirst(lastElement);
                    dq.removeLast();
                }
            }
        }
    }
}
