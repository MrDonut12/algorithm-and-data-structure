package src;

/**
 * Records the history of salary adjustments for a worker
 * @author KhanhNDCE200196
 */
public class SalaryHistory extends Worker {

    private SalaryStatus status;
    private String date;

    /**
     * Constructs a salary history record.
     * @param id Worker's ID.
     * @param name Worker's name.
     * @param age Worker's age.
     * @param salary Worker's salary after adjustment.
     * @param status The status (UP/DOWN).
     * @param date The date of adjustment.
     */
    public SalaryHistory(
        String id,
        String name,
        int age,
        double salary,
        SalaryStatus status,
        String date
    ) {
        super(id, name, age, salary, "");
        this.status = status;
        this.date = date;
    }

    /**
     * Gets the adjustment status.
     * @return The status.
     */
    public SalaryStatus getStatus() {
        return status;
    }

    /**
     * Gets the adjustment date.
     * @return The date.
     */
    public String getDate() {
        return date;
    }
}
