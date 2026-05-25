package src.controller;

import java.util.Scanner;
import src.model.BMIStatus;
import src.model.Operator;
import src.service.BMICalculator;
import src.service.NormalCalculator;
import src.utils.Constants;
import src.validator.InputValidator;

/**
 * Main Controller that help program control the workflow through user inputs
 * @author KhanhNDCE200196
 */
public class CalculatorController {

    private final Scanner scanner;
    private final InputValidator inputValidator;
    private final BMICalculator bmiCalculator;
    private final NormalCalculator normalCalculator;

    /**
     * Constructor
     */
    public CalculatorController() {
        scanner = new Scanner(System.in);
        bmiCalculator = new BMICalculator();
        normalCalculator = new NormalCalculator();
        inputValidator = new InputValidator();
    }

    /**
     * Run main workflow
     */
    public void runProgram() {
        while (true) {
            System.out.println("========= Calculator Program =========");
            System.out.println("1. Normal Calculator");
            System.out.println("2. BMI Calculator");
            System.out.println("3. Exit");

            int option = getOption();

            switch (option) {
                case Constants.BMI_CALCULATOR:
                    useBMICalculator();
                    break;
                case Constants.NORMAL_CALCULATOR:
                    useNormalCalculator();
                    break;
                case Constants.EXIT:
                    // exit program
                    System.out.println("Existing...");
                    return;
                default:
                    System.out.println("Invalid Option");
            }
        }
    }

    /**
     * Get menu choice
     * @return valid menu option
     */
    private int getOption() {
        while (true) {
            System.out.println("Please choice one option: ");

            String input = scanner.nextLine();
            Double value = inputValidator.checkInputNumber(input);

            if (value == null) {
                System.out.println("Please input a valid number");
                continue;
            }

            int option = value.intValue();

            if (option < 1 || option > 3) {
                System.out.println("Option must be from 1 to 3");

                continue;
            }

            return option;
        }
    }

    /**
     * Input valid number
     * @param message input message that we want to display
     * @return valid double number
     */
    private double inputNumber(String msg) {
        while (true) {
            System.out.print(msg);

            String input = scanner.nextLine();

            Double value = inputValidator.checkInputNumber(input);

            if (value == null) {
                System.out.println("Input must be a valid number");
                continue;
            }

            return value;
        }
    }

    /**
     * Input positive number
     * @param message input message that we want to display
     * @return positive double number (>= 0)
     */
    private double inputPositiveNumber(String msg) {
        while (true) {
            double value = inputNumber(msg);

            if (value <= 0) {
                System.out.println("Value must be greater than 0.");
                continue;
            }
            return value;
        }
    }

    /**
     * Input valid operator
     * @return Operator enum
     */
    private Operator inputOperator() {
        while (true) {
            System.out.print("Enter Operator: ");

            String input = scanner.nextLine();
            Operator operator = inputValidator.checkOperator(input);

            if (operator == null) {
                System.out.println("Please input (+, -, *, /, ^, =)");
                continue;
            }

            return operator;
        }
    }

    /**
     * Input valid BMI number
     * @param message input prompt
     * @return valid positive number
     */
    private double inputBMINumber(String msg) {
        while (true) {
            System.out.print(msg);

            String input = scanner.nextLine();
            Double value = inputValidator.checkInputNumber(input);

            if (value == null) {
                System.out.println("BMI is digit");
                continue;
            }
            if (value <= 0) {
                System.out.println("Value must be greater than 0");
                continue;
            }
            return value;
        }
    }

    /**
     * Execute BMI calculator workflow
     */
    public void useBMICalculator() {
        System.out.println("----- BMI Calculator -----");

        double weight = inputBMINumber("Enter Weight(kg): ");
        double height = inputBMINumber("Enter Height(cm): ");

        try {
            double bmi = bmiCalculator.calculateBMIValue(weight, height);
            BMIStatus status = bmiCalculator.calculateBMIStatus(bmi);

            System.out.printf("BMI Number: %.2f\n", bmi);
            System.out.println(status.getDescription());
        } catch (IllegalArgumentException exception) {
            System.out.println(exception.getMessage());
        } catch (Exception exception) {
            System.out.println("Unexpected error occurred");
        }
    }

    /**
     * Execute Normal calculator workflow
     */
    public void useNormalCalculator() {
        System.out.println("----- Normal Calculator -----");

        double memory = inputNumber("Enter number: ");

        while (true) {
            Operator operator = inputOperator();

            if (operator == Operator.EQUAL) {
                System.out.println("Result: " + memory);

                return;
            }

            double nextNumber = inputNumber("Enter number: ");

            try {
                memory = normalCalculator.calculate(
                    memory,
                    operator,
                    nextNumber
                );

                System.out.println("Memory: " + memory);
            } catch (ArithmeticException exception) {
                System.out.println(exception.getMessage());
            } catch (Exception exception) {
                System.out.println("Unexpected error occurred");
            }
        }
    }
}
