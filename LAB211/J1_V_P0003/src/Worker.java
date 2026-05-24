package src;

/**
 * Represents a worker in the system which store personal information
 * @author KhanhNDCE200196
 */
public class Worker {

    private String id;
    private String name;
    private int age;
    private double salary;
    private String workLocation;

    /**
     * Constructer
     * @param id id of the worker
     * @param name name of the worker
     * @param age age of the worker
     * @param salary salary of the worker
     * @param workLocation work location of the worker
     */
    public Worker(
        String id,
        String name,
        int age,
        double salary,
        String workLocation
    ) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.salary = salary;
        this.workLocation = workLocation;
    }

    /**
     * Gets the worker's ID
     * @return The ID
     */
    public String getId() {
        return id;
    }

    /**
     * Sets the worker's ID
     * @param id The ID to set
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Gets the worker's name
     * @return The name
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the worker's name
     * @param name The name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Gets the worker's age
     * @return The age
     */
    public int getAge() {
        return age;
    }

    /**
     * Sets the worker's age
     * @param age The age to set
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     * Gets the worker's salary
     * @return The salary
     */
    public double getSalary() {
        return salary;
    }

    /**
     * Sets the worker's salary
     * @param salary The salary to set
     */
    public void setSalary(double salary) {
        this.salary = salary;
    }

    /**
     * Gets the worker's work location
     * @return The work location
     */
    public String getWorkLocation() {
        return workLocation;
    }

    /**
     * Sets the worker's work location
     * @param workLocation The work location to set
     */
    public void setWorkLocation(String workLocation) {
        this.workLocation = workLocation;
    }
}
