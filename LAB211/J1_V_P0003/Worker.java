public class Worker {

    private String id;
    private String name;
    private int age;
    private double salary;
    private String workLocation;

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

    // public void modifierSalary(SalaryStatus mode, int amount) {
    //     if (mode == SalaryStatus.INCREASE) {
    //         this.salary += amount;
    //     } else if (mode == SalaryStatus.DECREASE) {
    //         this.salary -= amount;
    //     }
    // }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public int getAge() {
        return this.age;
    }

    public double getSalary() {
        return this.salary;
    }

    public String getWorkLocation() {
        return this.workLocation;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void getName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void setWorkLocation(String workLocation) {
        this.workLocation = workLocation;
    }
}
