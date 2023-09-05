public class LoanAccount 
{
    // Private properties to store the loan details
    private double principal;
    private double annualInterestRate;
    private int months;

    // Constructor for LoanAccount class
    public LoanAccount(double principal, double annualInterestRate, int months) 
    {
        // Assign the provided values to the corresponding properties
        this.principal = principal;
        this.annualInterestRate = annualInterestRate;
        this.months = months;
    }

    // Calculate the monthly payment for the loan
    public double calculateMonthlyPayment() 
    {
        // Calculate the monthly interest rate
        double monthlyInterestRate = annualInterestRate / 1200;

        // Use the provided formula to calculate the monthly payment
        return principal * monthlyInterestRate / (1 - Math.pow(1 + monthlyInterestRate, -months));
    }

    // Getter method for the principal property
    public double getPrincipal()
    {
        return principal;
    }

    // Getter method for the annualInterestRate property
    public double getAnnualInterestRate() 
    {
        return annualInterestRate;
    }

    // Getter method for the months property
    public int getMonths()
    {
        return months;
    }

    // Override the toString() method to provide custom string representation of LoanAccount objects
    @Override
    public String toString()
     {
        // Use String.format() to create a formatted string with the loan details
        return String.format("Principal: %.2f%nAnnual Interest Rate: %.2f%nMonths: %d%n",
                principal, annualInterestRate, months);
    }
}
