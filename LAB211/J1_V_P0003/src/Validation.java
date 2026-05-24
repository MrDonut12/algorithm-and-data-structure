package src;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Utility class for validating user input
 * Refactored to use instance methods where possible to reduce static dependency
 * @author KhanhNDCE200196
 */
public class Validation {

    /**
     * Scanner object for reading input
     */
    private final Scanner sc;

    /**
     * Constructs a Validation instance with a specific Scanner
     * @param sc The scanner to use for input
     */
    public Validation(Scanner sc) {
        this.sc = sc;
    }

    /**
     * Gets a valid integer from the user within a range
     * @param msg The message you want to print
     * @param min Minimum allowed value
     * @param max Maximum allowed value
     * @return A valid integer
     */
    public int getInt(String msg, int min, int max) {
        while (true) {
            try {
                System.out.print(msg);
                String input = sc.nextLine().trim();
                if (input.isEmpty()) {
                    System.err.println("Input cannot be empty.");
                    continue;
                }
                int result = Integer.parseInt(input);
                if (result < min || result > max) {
                    System.err.println(
                        "Please enter a number in range [" +
                            min +
                            ", " +
                            max +
                            "]."
                    );
                    continue;
                }
                return result;
            } catch (NumberFormatException e) {
                System.err.println(
                    "Invalid input. Please enter a whole number."
                );
            }
        }
    }

    /**
     * Gets a valid string from the user
     * @param msg The message you want to print
     * @return A string (not null)
     */
    public String getString(String msg) {
        while (true) {
            System.out.print(msg);
            String input = sc.nextLine().trim();
            if (input.isEmpty()) {
                System.err.println("Input cannot be empty.");
                continue;
            }
            return input;
        }
    }

    /**
     * Gets a valid worker ID. Checks for existence using a arraylist
     * @param msg The message you want to print
     * @param workers List of existing workers
     * @param isAdd True if adding a new worker (ID must not exist), False if updating (ID must exist)
     * @return A valid ID
     */
    public String getId(String msg, ArrayList<Worker> workers, boolean isAdd) {
        while (true) {
            String id = getString(msg);
            Worker worker = null;
            // Find worker
            for (Worker w : workers) {
                if (w.getId().equals(id)) {
                    worker = w;
                    break;
                }
            }

            if (isAdd) {
                if (worker != null) {
                    System.err.println(
                        "ID already exists. Please enter a new ID."
                    );
                    continue;
                }
            } else {
                if (worker == null) {
                    System.err.println(
                        "ID does not exist. Please enter an existing ID."
                    );
                    continue;
                }
            }
            return id;
        }
    }

    /**
     * Gets a valid age between 18 and 50
     * @param msg The message you want to print
     * @return A valid age
     */
    public int getAge(String msg) {
        return getInt(msg, 18, 50);
    }

    /**
     * Gets a valid salary (greater than 0)
     * @param msg The message you want to print
     * @return A valid salary
     */
    public double getSalary(String msg) {
        while (true) {
            try {
                System.out.print(msg);
                String input = sc.nextLine().trim();
                if (input.isEmpty()) {
                    System.err.println("Input cannot be empty");
                    continue;
                }
                double result = Double.parseDouble(input);
                if (result <= 0) {
                    System.err.println("Salary must be greater than 0");
                    continue;
                }
                return result;
            } catch (NumberFormatException e) {
                System.err.println("Invalid input. Please enter a number");
            }
        }
    }
}
