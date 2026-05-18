import java.util.Scanner;

/**
 * J1.S.P0007
 * Validation Class - Check and validate the input (re-enter if poor input)
 * @author NguyenDuyKhanh
 */
public class Validation {

    private Scanner sc;

    /**
     * Constructor
     */
    public Validation() {
        sc = new Scanner(System.in);
    }

    /**
     * prompts the user to enter a positive integer
     * @param msg message displayed to the user
     * @return a positive integer
     */
    public int getPositiveInteger(String msg) {
        System.out.println(msg);
        // input n as integer that we need to check if it is positive
        int n;
        boolean checkFlag = true;

        // use a do-while loop to force the user to re-enter a number while the input is negative, throughout checkFlag (checkFlag equals to True if number input >= 0)
        do {
            n = Integer.parseInt(sc.nextLine());
            if (n < 0) {
                checkFlag = false;
                System.out.println("Input number must be positive");
            }
        } while (!checkFlag);

        return n;
    }
}
