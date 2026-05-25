package src.validator;

import src.model.Operator;

/**
 * Responsible for validate the input
 * @author KhanhNDCE200196
 */
public class InputValidator {

    /**
     * Constructer
     */
    public InputValidator() {}

    /**
     * Validate and parse double number
     *
     * @param inputValue user input
     * @return Double value if valid, null if not
     */
    public Double checkInputNumber(String inputValue) {
        try {
            if (inputValue == null) {
                throw new NullPointerException();
            }

            inputValue = inputValue.trim();

            // check if inputValue is empty after trim
            if (inputValue.isEmpty()) {
                return null;
            }

            double value = Double.parseDouble(inputValue);

            // Check if Infinity and NaN then return null
            if (Double.isInfinite(value) || Double.isNaN(value)) {
                return null;
            }

            return value;
        } catch (NumberFormatException exception) {
            return null;
        } catch (NullPointerException exception) {
            return null;
        }
    }

    /**
     * Validate operator.
     *
     * @param operatorInput operator entered by user
     * @return Operator enum if valid, otherwise null
     */
    public Operator checkOperator(String operatorInput) {
        try {
            if (operatorInput == null) {
                throw new NullPointerException();
            }

            operatorInput = operatorInput.trim();
            // use forEach to check if operator input occur in Operator[] from Operator enum
            for (Operator operator : Operator.values()) {
                if (operator.getSymbol().equals(operatorInput)) {
                    return operator;
                }
            }

            return null;
        } catch (NullPointerException exception) {
            return null;
        }
    }
}
