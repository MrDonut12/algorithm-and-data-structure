import java.util.ArrayList;
import java.util.Collections;

public class WorkerManagement {

    private ArrayList<Worker> workerList = new ArrayList<>();
    private ArrayList<SalaryHistory> salaryHistories = new ArrayList<>();

    public WorkerManagement() {}

    public void addWorker(Worker worker) {
        workerList.add(worker);
        SalaryHistory salaryHistory = new SalaryHistory(
            worker,
            SalaryStatus.UP
        );
        salaryHistories.add(salaryHistory);
    }

    public Boolean increaseSalary(Worker worker, int amount) {
        for (Worker workerInList : workerList) {
            workerInList.setSalary(workerInList.getSalary() + amount);
            if (workerInList.getId().equals(worker.getId())) {
                SalaryHistory salaryHistory = new SalaryHistory(
                    workerInList,
                    SalaryStatus.UP
                );
                salaryHistories.add(salaryHistory);
                return true;
            }
        }
        return false;
    }

    public Boolean decreaseSalary(Worker worker, int amount) {
        for (Worker workerInList : workerList) {
            if (workerInList.getId().equals(worker.getId())) {
                workerInList.setSalary(workerInList.getSalary() - amount);
                SalaryHistory salaryHistory = new SalaryHistory(
                    workerInList,
                    SalaryStatus.DOWN
                );
                salaryHistories.add(salaryHistory);

                return true;
            }
        }

        return false;
    }

    public void displayWorkers() {
        salaryHistories.sort(new Comparator<salaryHistory>() {});

        System.out.printf(
            "%-10s %-15s %-10s %-10s %-10s %-15s\n",
            "Code",
            "Name",
            "Age",
            "Salary",
            "Status",
            "Date"
        );

        salaryHistories.forEach(salaryHistory -> {
            System.out.printf(
                "%-10s %-15s %-10d %-10f %-10s %-15s\n",
                salaryHistory.getId(),
                salaryHistory.getName(),
                salaryHistory.getAge(),
                salaryHistory.getSalary(),
                salaryHistory.getStatus()
            );
        });
    }
}
