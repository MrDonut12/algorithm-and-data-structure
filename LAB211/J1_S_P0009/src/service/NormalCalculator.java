package src.service;

import src.model.Operator;

/**
 * NormalCalculate that support for normal operation such as add, subtract, multiply, etc
 * @author KhanhNDCE200196
 */
public class NormalCalculator {

    /**
     * Constructor
     */
    public NormalCalculator() {}

    /**
     * Perform calculation based on operator
     *
     * @param firstNumber  first operand
     * @param operator     operator
     * @param secondNumber second operand
     * @return calculated result
     */
    public double calculate(
        double firstNumber,
        Operator operator,
        double secondNumber
    ) {
        switch (operator) {
            case ADD:
                return firstNumber + secondNumber;
            case SUBTRACT:
                return firstNumber - secondNumber;
            case MULTIPLY:
                return firstNumber * secondNumber;
            case DIVIDE:
                if (secondNumber == 0) {
                    throw new ArithmeticException("Cannot divide by zero");
                }

                return firstNumber / secondNumber;
            case POWER:
                return Math.pow(firstNumber, secondNumber);
            default:
                throw new IllegalArgumentException("Invalid operator");
        }
    }
}
