package src;

import java.util.Scanner;

/**
 * Validation Class - Check and validate the input (re-enter if poor input)
 * @author NguyenDuyKhanh
 */
public class InputValidator {

    private final Scanner sc;

    /**
     * Constructor
     */
    public InputValidator() {
        sc = new Scanner(System.in);
    }

    /**
     * Prompts the user to enter a positive integer
     * @param msg message displayed to the user
     * @return a positive integer
     */
    public int getPositiveInteger(String msg) {
        while (true) {
            try {
                System.out.println(msg);
                String input = sc.nextLine().trim();

                // check if the input (str) is null
                if (input.isEmpty()) {
                    System.err.println("Number must not be null");
                    continue;
                }

                int num = Integer.parseInt(input);
                // check if the num is smaller than 0
                if (num < 0) {
                    System.err.println(
                        "Number must be larger than or equal to 0"
                    );
                    continue;
                }

                return num;
            } catch (NumberFormatException ex) {
                System.err.println(
                    "The input is not correct format, please enter number type"
                );
            }
        }
    }
}
