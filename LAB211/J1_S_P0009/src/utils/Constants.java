package src.utils;

/**
 * Contains all constant values used in the application
 * @author KhanhNDCE200196
 */
public final class Constants {

    private Constants() {}

    /**
     * Menu option for normal calculator
     */
    public static final int NORMAL_CALCULATOR = 1;

    /**
     * Menu option for BMI calculator
     */
    public static final int BMI_CALCULATOR = 2;

    /**
     * Menu option for exiting program
     */
    public static final int EXIT = 3;

    /**
     * BMI threshold for under standard status
     */
    public static final double UNDER_STANDARD_LIMIT = 19;

    /**
     * BMI threshold for standard status
     */
    public static final double STANDARD_LIMIT = 25;

    /**
     * BMI threshold for overweight status
     */
    public static final double OVERWEIGHT_LIMIT = 30;

    /**
     * BMI threshold for fat status
     */
    public static final double FAT_LIMIT = 40;
}
