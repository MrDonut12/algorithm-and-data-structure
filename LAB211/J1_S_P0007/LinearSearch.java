/**
 * J1.S.P0007 - Linear Search Program (Main workflow)
 * @author KhanhNDCE200196
 */

public class LinearSearch {

    /**
     * Constructor
     */
    public LinearSearch() {}

    /**
     * Run the linear search program
     */
    public void runProgram() {
        Validation validation = new Validation();
        int size = validation.getPositiveInteger("Enter number of array: ");
        MyArray myArray = new MyArray(size);
        int target = validation.getPositiveInteger("Enter search value: ");
        System.out.println("The array: " + myArray.toString());
        myArray.search(target);
    }
}
