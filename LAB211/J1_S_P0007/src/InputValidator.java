package src;

import java.util.Scanner;

class InputValidator {

    private final Scanner sc;

    public InputValidator() {
        sc = new Scanner(System.in);
    }

    public int getInteger(String msg, int min, int max) {
        while (true) {
            try {
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
