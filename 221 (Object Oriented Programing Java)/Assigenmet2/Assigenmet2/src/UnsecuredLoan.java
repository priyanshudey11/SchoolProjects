public class UnsecuredLoan extends LoanAccount 
{
    // Constructor for UnsecuredLoan class
    public UnsecuredLoan(double principal, double annualInterestRate, int months)
     {
        // Call the constructor of the superclass (LoanAccount) with the provided parameters
        super(principal, annualInterestRate, months);
    }

    // Override the toString() method to provide custom string representation of UnsecuredLoan objects
    @Override
    public String toString() 
    {
        // Concatenate the superclass's toString() result with additional information indicating it is an unsecured loan
        return "Unsecured Loan with:\n" + super.toString();
    }
}
