package src;

/**
 * Array Management Class - This class manages array operations such as generating, displaying, and searching elements in array.
 * @author NguyenDuyKhanh
 */
public class MyArray {

    private int[] arr;

    /**
     * Generate random number
     * @param lower min number can be generate
     * @param upper max number can be generate, upper must alway higher than lower
     * @return random number in range [lower, upper]
     */

    public int randomNumber(int lower, int upper) {
        return (int) (Math.random() * (upper - lower + 1)) + lower;
    }

    /**
     * Constructor
     * @param length length of the array
     */
    public MyArray(int length) {
        // allocate memory of the array  with size variable
        arr = new int[length];

        // assign each index from 0 to size - 1 with random number in range[1, size]
        for (int i = 0; i < length; i++) {
            arr[i] = randomNumber(1, length);
        }
    }

    /**
     * Search target method (use Linear Search) - Print all the index of the target that occur in Array with formatted string: "Found {target} at index: {list of returned index}"
     * @param target the number need to search in Array
     * @return a string that is a list of targets' index which are occure in the array, return null if cannot find target
     */
    public String search(int target) {
        boolean checkFlag = false;
        String result = "";
        // check for each index (as i) of the array, if array[i] == target, so this is the index of the target
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                checkFlag = true;
                result += i + " ";
            }
        }
        // if checkFlag == false, it means that target is not occur in Array, return null
        if (!checkFlag) {
            return "null";
        }
        return result;
    }

    /**
     * Convert the array to the formatted string
     * @return a formatted string
     */
    @Override
    public String toString() {
        // check if arr is empty, return []
        if (arr.length == 0 || arr == null) return "[]";
        String result = "[";

        for (int i = 0; i < arr.length - 1; i++) {
            result += arr[i] + ", ";
        }
        result += arr[arr.length - 1] + "]";

        return result;
    }
}
