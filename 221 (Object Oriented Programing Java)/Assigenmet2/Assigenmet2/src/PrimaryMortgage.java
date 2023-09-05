public class PrimaryMortgage extends LoanAccount 
{
    // Private properties to store the PMI monthly amount and the address
    private double PMIMonthlyAmount;
    private Address address;

    // Constructor for PrimaryMortgage class
    public PrimaryMortgage(double principal, double annualInterestRate, int months, double PMIMonthlyAmount, Address address) {
        // Call the constructor of the superclass (LoanAccount) with the provided parameters
        super(principal, annualInterestRate, months);

        // Assign the provided values to the corresponding properties
        this.PMIMonthlyAmount = PMIMonthlyAmount;
        this.address = address;
    }

    // Override the toString() method to provide custom string representation of PrimaryMortgage objects
    @Override
    public String toString() 
    {
        // Concatenate the superclass's toString() result with additional information about PMI and the address
        return "Primary Mortgage Loan with:\n" + super.toString() + "PMI Monthly Amount: $" + PMIMonthlyAmount +
                "\nProperty Address: \n" + address + "\n";
    }
}
