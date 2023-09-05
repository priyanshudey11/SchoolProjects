public class CarLoan extends LoanAccount 
{
    // Private property to store the vehicle VIN
    private String vehicleVIN;

    // Constructor for CarLoan class
    public CarLoan(double principal, double annualInterestRate, int months, String vehicleVIN)
     {
        // Call the constructor of the superclass (LoanAccount) with the provided parameters
        super(principal, annualInterestRate, months);

        // Assign the vehicle VIN to the class property
        this.vehicleVIN = vehicleVIN;
    }


    public String toString()
     {
        // Concatenate the superclass's toString() result with additional information about the vehicle VIN
        return "Car Loan with:\n" + super.toString() + "Vehicle VIN: " + vehicleVIN + "\n";
    }
}
