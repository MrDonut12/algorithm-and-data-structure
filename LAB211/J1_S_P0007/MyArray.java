/**
 * J1.S.P0007
 * Array Management Class - This class manages array operations such as generating, displaying, and searching elements in array.
 * @author NguyenDuyKhanh
 */
public class MyArray {

    private int[] arr;
    private int size;

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
     * @param size length of the array
     */
    public MyArray(int size) {
        // allocate memory of the array  with size variable
        arr = new int[size];

        // assign each index from 0 to size - 1 with random number in range[0, size - 1]
        for (int i = 0; i < size; i++) {
            arr[i] = randomNumber(0, size - 1);
        }

        // assign the constructor parameter 'size' to the instance variable
        this.size = size;
    }

    /**
     * Search target method (use Linear Search) - Print all the index of the target that occur in Array with formatted string: "Found {target} at index: {list of returned index}"
     * @param target the number need to search in Array
     */
    public void search(int target) {
        boolean checkFlag = false;

        // check for each index (as i) of the array, if array[i] == target, so this is the index of the target
        System.out.print("Found " + target + " at index: ");
        for (int i = 0; i < this.size; i++) {
            if (arr[i] == target) {
                checkFlag = true;
                System.out.print(i + " ");
            }
        }
        // if checkFlag == false, it means that target is not occur in Array, print null
        if (!checkFlag) {
            System.out.println("null");
            return;
        }
        System.out.println("");
    }

    /**
     * Return a string representation of the array
     * @return a formatted string that containing all the element of the array
     */
    @Override
    public String toString() {
        // if arr is null, return []
        if (arr == null || this.size == 0) {
            return "[]";
        }
        // else return formatted string like: "[ a1, a2, ..., a_size ]"
        String result = "[" + arr[0];
        for (int i = 1; i < size - 1; i++) {
            result += ", " + arr[i];
        }
        result += ", " + arr[size - 1] + "]";

        return result;
    }
}
