package src;

import java.util.Scanner;

public class Menu {

    private final Scanner sc;
    private final InputValidator inputValidator;

    /**
     * Construction
     */
    public Menu() {
        sc = new Scanner(System.in);
        inputValidator = new InputValidator();
    }

    /**
     * Display menu with 3 options for user
     */
    public void displayMenu() {
        System.out.println("========= Calculator Program =========");
        System.out.println("1. Normal Calculator");
        System.out.println("2. BMI Calculator");
        System.out.println("3. Exit");
    }

    public void inputOption() {
        int option = inputValidator.getInteger(
            "Please choice one option: ",
            "",
            1,
            3
        );
    }
}
