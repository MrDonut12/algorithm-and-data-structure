package src;

import src.controller.CalculatorController;

/**
 * J1.S.P0009 - Calculator Program support calculate BMI value and normal operation
 * @author KhanhNDCE200196
 */
public class J1sp0009 {

    /**
     * Constructor
     */
    public J1sp0009() {}

    /**
     * Entry point of program
     * @param args command line arguments
     */
    public static void main(String[] args) {
        CalculatorController calculatorController = new CalculatorController();
        calculatorController.runProgram();
    }
}
