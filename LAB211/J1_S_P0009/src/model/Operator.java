package src.model;

/**
 * Enum represents all operators for project
 * @author KhanhNDCE200196
 */
public enum Operator {
    /**
     * Addition operator
     */
    ADD("+"),

    /**
     * Subtraction operator
     */
    SUBTRACT("-"),

    /**
     * Multiplication operator
     */
    MULTIPLY("*"),

    /**
     * Division operator
     */
    DIVIDE("/"),

    /**
     * Exponent operator
     */
    POWER("^"),

    /**
     * Equal operator
     */
    EQUAL("=");

    private final String symbol;

    /**
     * Initialize operator symbol
     * @param symbol operator character
     */
    Operator(String symbol) {
        this.symbol = symbol;
    }

    /**
     * Get operator symbol
     * @return operator symbol
     */
    public String getSymbol() {
        return symbol;
    }
}
