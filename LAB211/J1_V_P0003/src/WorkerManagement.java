package src;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * Manager Class that controller the Data of the worker and salary history
 * @author KhanhNDCE200196
 */
public class WorkerManagement {

    private final ArrayList<Worker> workers;
    private final ArrayList<SalaryHistory> history;

    /**
     * Initializes the management system
     */
    public WorkerManagement() {
        this.workers = new ArrayList<>();
        this.history = new ArrayList<>();
    }

    /**
     * Adds a new worker to the worker list
     * @param worker The worker object to add
     * @return true if added successfully
     */
    public boolean addWorker(Worker worker) {
        if (worker == null) return false;
        return workers.add(worker);
    }

    /**
     * Changes the salary of a worker and records the history
     * @param status The type of adjustment (UP/DOWN)
     * @param id The ID of the worker
     * @param amount The amount to increase or decrease
     * @return true if updated successfully
     */
    public boolean changeSalary(SalaryStatus status, String id, double amount) {
        Worker worker = findWorkerById(id);
        if (worker == null) return false;

        double currentSalary = worker.getSalary();
        double newSalary = currentSalary;

        if (status == SalaryStatus.UP) {
            newSalary = currentSalary + amount;
        } else if (status == SalaryStatus.DOWN) {
            if (currentSalary <= amount) {
                System.err.println("Salary cannot be decreased below 0.");
                return false;
            }
            newSalary = currentSalary - amount;
        }

        worker.setSalary(newSalary);
        String date = LocalDate.now().format(
            DateTimeFormatter.ofPattern("dd/MM/yyyy")
        );
        history.add(
            new SalaryHistory(
                worker.getId(),
                worker.getName(),
                worker.getAge(),
                newSalary,
                status,
                date
            )
        );
        return true;
    }

    /**
     * Finds a worker by their ID.
     * @param id The ID to search for.
     * @return The worker object, or null if not found.
     */
    public Worker findWorkerById(String id) {
        for (Worker w : workers) {
            if (w.getId().equals(id)) {
                return w;
            }
        }
        return null;
    }

    /**
     * Retrieves all salary history records.
     *
     * @return A list of SalaryHistory objects.
     */
    public ArrayList<SalaryHistory> getInformationSalary() {
        return history;
    }

    /**
     * Gets the list of workers.
     * @return The workers list.
     */
    public ArrayList<Worker> getWorkers() {
        return workers;
    }
}
