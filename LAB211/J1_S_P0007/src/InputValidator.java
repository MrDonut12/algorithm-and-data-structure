package src;

import java.util.Scanner;

/**
 * Utility class for validating user input
 * @author KhanhNDCE200196
 */
class InputValidator {

    private final Scanner sc;

    /**
     * Constructor
     */
    public InputValidator() {
        sc = new Scanner(System.in);
    }

    /**
     * Gets a valid integer from the user within a range
     * @param msg The message you want to print
     * @param min Minimum allowed value
     * @param max Maximum allowed value
     * @return A valid integer
     */
    public int getInteger(String msg, int min, int max) {
        while (true) {
            try {
                System.out.println(msg);
                String input = sc.nextLine().trim();
                if (input.isEmpty()) {
                    System.err.println("Input must not be null");
                    continue;
                }

                int num = Integer.parseInt(input);
                if (num < min || num > max) {
                    System.err.println(
                        "The entered number must be in range [" +
                            min +
                            ", " +
                            max +
                            "]"
                    );
                    continue;
                }

                return num;
            } catch (NumberFormatException ex) {
                System.err.println("The input must is digit");
            }
        }
    }
}
