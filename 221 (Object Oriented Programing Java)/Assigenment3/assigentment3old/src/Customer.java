import java.util.ArrayList;

public class Customer {
    private String firstName;
    private String lastName;
    private String SSN;
    private ArrayList<LoanAccount> loanAccounts;

    // Constructor to initialize a Customer object with first name, last name, and SSN
    public Customer(String firstName, String lastName, String SSN) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.SSN = SSN;
        this.loanAccounts = new ArrayList<>(); // Initialize the loanAccounts ArrayList
    }

    // Getter for retrieving the first name of the customer
    public String getFirstName() {
        return firstName;
    }

    // Getter for retrieving the last name of the customer
    public String getLastName() {
        return lastName;
    }

    // Getter for retrieving the SSN of the customer
    public String getSSN() {
        return SSN;
    }

    // Method to add a loan account to the customer's list of accounts
    public void addLoanAccount(LoanAccount account) {
        loanAccounts.add(account);
    }

    // Method to calculate the total monthly payment for all loan accounts of the customer
    public double calculateTotalMonthlyPayment() {
        double totalMonthlyPayment = 0.0;
        for (LoanAccount account : loanAccounts) {
            totalMonthlyPayment += account.calculateMonthlyPayment();
        }
        return totalMonthlyPayment;
    }

    // Method to generate a monthly report for all loan accounts of the customer
    public String printMonthlyReport() {
        StringBuilder report = new StringBuilder();
        report.append("Account Report for Customer: ").append(firstName).append(" ").append(lastName)
                .append(" with SSN ").append(SSN).append("\n\n");

        for (LoanAccount account : loanAccounts) {
            report.append(account.toString()).append("\n\n");
        }

        return report.toString();
    }
}
