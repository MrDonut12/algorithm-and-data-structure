import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class template {

    public void input() {
        System.out.println("Enter number of array: ");
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );
    }

    public static void main(String[] args) throws Exception {
        int a, b;

        // nhẫn
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        int sum = a + b;
        System.out.println("Sum: " + sum);
    }
}
