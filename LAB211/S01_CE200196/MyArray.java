public class MyArray {

    int arr[];
    int length;

    private int randomNumber(int lower, int upper) {
        return (int) (Math.random() * (upper - lower) + lower);
    }

    public MyArray(int length) {
        this.length = length;
        arr = new int[length];
        for (int i = 0; i < length; i++) {
            arr[i] = randomNumber(-length, length);
        }
    }

    public void sort() {
        for (int i = 0; i < this.length - 1; i++) {
            for (int j = i + 1; j < this.length; j++) {
                if (arr[i] > arr[j]) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }

    @Override
    public String toString() {
        if (this.length == 0 || arr == null) {
            return "[]";
        }

        String str = "[" + arr[0];
        for (int i = 0; i < this.length - 1; i++) {
            str += ", " + arr[i];
        }
        str += arr[this.length - 1] + "]";

        return str;
    }
}
