package src;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * J1-V-P0003 Worker Information Manager
 * @author KhanhNDCE200196
 */
public class J1vp0003 {

    private final Scanner sc;
    private final Validation valid;
    private final WorkerManagement manager;

    /**
     * Constructor to initialize dependencies.
     */
    public J1vp0003() {
        this.sc = new Scanner(System.in);
        this.valid = new Validation(sc);
        this.manager = new WorkerManagement();
    }

    /**
     * Main entry point.
     * @param args CLI arguments.
     */
    public static void main(String[] args) {
        J1vp0003 mainProgram = new J1vp0003();
        mainProgram.run();
    }

    /**
     * Main execution loop.
     */
    public void run() {
        while (true) {
            System.out.println("======== Worker Management =========");
            System.out.println("1. Add Worker");
            System.out.println("2. Up salary");
            System.out.println("3. Down salary");
            System.out.println("4. Display Information salary");
            System.out.println("5. Exit");

            int choice = valid.getInt("Please choose: ", 1, 5);

            switch (choice) {
                case 1:
                    addWorker();
                    break;
                case 2:
                    changeSalary(SalaryStatus.UP);
                    break;
                case 3:
                    changeSalary(SalaryStatus.DOWN);
                    break;
                case 4:
                    displayHistory();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    return;
            }
        }
    }

    /**
     * Handles UI for adding a worker.
     */
    private void addWorker() {
        System.out.println("--------- Add Worker ----------");
        String id = valid.getId("Enter Code: ", manager.getWorkers(), true);
        String name = valid.getString("Enter Name: ");
        int age = valid.getAge("Enter Age: ");
        double salary = valid.getSalary("Enter Salary: ");
        String workLocation = valid.getString("Enter work location: ");

        if (
            manager.addWorker(new Worker(id, name, age, salary, workLocation))
        ) {
            System.out.println("Worker added successfully.");
        }
    }

    /**
     * Handles UI for changing salary.
     * @param status UP or DOWN.
     */
    private void changeSalary(SalaryStatus status) {
        System.out.println(
            "------- " +
                (status == SalaryStatus.UP ? "Up" : "Down") +
                " Salary --------"
        );
        String id = valid.getId("Enter Code: ", manager.getWorkers(), false);
        double amount = valid.getSalary("Enter amount: ");

        if (manager.changeSalary(status, id, amount)) {
            System.out.println("Salary updated successfully.");
        }
    }

    /**
     * Displays salary history records.
     */
    private void displayHistory() {
        ArrayList<SalaryHistory> history = manager.getInformationSalary();
        if (history.isEmpty()) {
            System.out.println("No salary history records found.");
            return;
        }

        System.out.println(
            "--------------------Display Information Salary-----------------------"
        );
        System.out.printf(
            "%-10s%-15s%-10s%-10s%-10s%-15s\n",
            "Code",
            "Name",
            "Age",
            "Salary",
            "Status",
            "Date"
        );
        for (SalaryHistory sh : history) {
            System.out.printf(
                "%-10s%-15s%-10d%-10.0f%-10s%-15s\n",
                sh.getId(),
                sh.getName(),
                sh.getAge(),
                sh.getSalary(),
                sh.getStatus(),
                sh.getDate()
            );
        }
    }
}
