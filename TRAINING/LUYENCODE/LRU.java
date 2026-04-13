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
                int key = Integer.parseInt(st.nextToken());
                int value = Integer.parseInt(st.nextToken());

                if (map.containsKey(key)) {
                    dq.remove(key); // update → move lên đầu
                } else {
                    if (map.size() == capacity) {
                        int lru = dq.peekLast();
                        dq.removeLast();
                        map.remove(lru);
                    }
                }

                map.put(key, value);
                dq.addFirst(key);
            } else {
                // cmds == get
                int key = Integer.parseInt(st.nextToken());
                if (!map.containsKey(key)) {
                    System.out.println(-1);
                } else {
                    System.out.println(map.get(key));

                    dq.remove(key);
                    dq.addFirst(key);
                }
            }
        }
    }
}
