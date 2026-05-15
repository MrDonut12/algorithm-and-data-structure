import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class SalaryHistory {

    private String id;
    private String name;
    private int age;
    private double salary;

    private SalaryStatus salaryStatus;
    private String date;

    public SalaryHistory(Worker worker, SalaryStatus salaryStatus) {
        this.id = worker.getId();
        this.name = worker.getName();
        this.age = worker.getAge();
        this.salary = worker.getSalary();
        this.salaryStatus = salaryStatus;
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern(
            "dd/MM/yyyy"
        );
        this.date = LocalDate.now().format(dateTimeFormatter);
    }

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

    public String getDate() {
        return this.date;
    }

    public SalaryStatus getStatus() {
        return salaryStatus;
    }
}
