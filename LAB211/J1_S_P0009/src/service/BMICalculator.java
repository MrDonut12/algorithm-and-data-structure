package src.service;

import src.model.BMIStatus;
import src.utils.Constants;

/**
 * BMICalculator that support calculate bmi value as well as return bmi status
 * @author KhanhNDCE200196
 */
public class BMICalculator {

    /**
     * Construction
     */
    public BMICalculator() {}

    /**
     * Calculate BMI value
     *
     * @param weight weight in kg
     * @param height height in cm
     * @return BMI value
     */
    public double calculateBMIValue(double weight, double height) {
        if (weight <= 0 || height <= 0) {
            throw new IllegalArgumentException(
                "Weight and height must be greater than 0."
            );
        }

        double heightInMeter = height / 100;

        return weight / (heightInMeter * heightInMeter);
    }

    /**
     * Get BMI Value Status form BMI original Value
     * @param bmi bmi value to check and consume for status
     * @return status based on bmi value
     */
    public BMIStatus calculateBMIStatus(double bmi) {
        if (bmi < Constants.UNDER_STANDARD_LIMIT) {
            return BMIStatus.UNDER_STANDARD;
        }

        if (bmi <= Constants.STANDARD_LIMIT) {
            return BMIStatus.STANDARD;
        }

        if (bmi <= Constants.OVERWEIGHT_LIMIT) {
            return BMIStatus.OVERWEIGHT;
        }

        if (bmi <= Constants.FAT_LIMIT) {
            return BMIStatus.FAT;
        }

        return BMIStatus.VERY_FAT;
    }
}
