package src.model;

/**
 * Enum represents BMI status
 * @author KhanhNDCE200196
 */
public enum BMIStatus {
    /**
     * BMI is below standard level
     */
    UNDER_STANDARD("Under-standard"),

    /**
     * BMI is within healthy range
     */
    STANDARD("Standard"),

    /**
     * BMI is above healthy range
     */
    OVERWEIGHT("Overweight"),

    /**
     * BMI indicates obesity
     */
    FAT("Fat - should lose weight"),

    /**
     * BMI indicates severe obesity
     */
    VERY_FAT("Very fat - should lose weight immediately");

    private final String description;

    /**
     * Initialize BMI description
     * @param description display description
     */
    BMIStatus(String description) {
        this.description = description;
    }

    /**
     * Get BMI description
     * @return BMI description
     */
    public String getDescription() {
        return description;
    }
}
