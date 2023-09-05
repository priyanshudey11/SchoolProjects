public class UnsecuredLoan extends LoanAccount 
{
    // Constructor for UnsecuredLoan class
    public UnsecuredLoan(double principal, double annualInterestRate, int months)
     {
        // Call the constructor of the superclass (LoanAccount) with the provided parameters
        super(principal, annualInterestRate, months);
    }


    public String toString() 
    {
        // Concatenate the superclass's toString() result with additional information indicating it is an unsecured loan
        return "Unsecured Loan with:\n" + super.toString();
    }
}
