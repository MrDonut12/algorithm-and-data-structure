package src;

/**
 * Linear Search Program (Main workflow)
 * @author KhanhNDCE200196
 */

public class J1sp0007 {

    /**
     * Constructor
     */
    public J1sp0007() {}

    /**
     * Run the linear search program
     */
    public static void main(String[] args) {
        InputValidator inputValidator = new InputValidator();
        // input size of the array
        int size = inputValidator.getInteger(
            "Enter number of array: ",
            0,
            Integer.MAX_VALUE
        );
        MyArray myArray = new MyArray(size);
        // search the target if it is occur in array
        int target = inputValidator.getInteger(
            "Enter search value: ",
            0,
            Integer.MAX_VALUE
        );
        // print the random element of the array with entered size
        System.out.println("The array: " + myArray.toString());
        // print the list of the index of target number that is occur in the array (return by null if cannot find the target in array)
        System.out.print("Found " + target + " at index: ");
        System.out.print(myArray.search(target) + "\n");
    }
}
