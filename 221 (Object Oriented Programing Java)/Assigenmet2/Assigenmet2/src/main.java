public class main 
{
    public static void main(String[] args) 
    {
        // Create three different loan objects, one of each type.

        // Create a CarLoan object with the provided loan details and vehicle VIN
        CarLoan carLoan = new CarLoan(25000.00, 4.25, 72, "IRQ3458977");

        // Create an Address object with the provided property address details
        Address propertyAddress = new Address("321 Main Street", "State College", "PA", "16801");

        // Create a PrimaryMortgage object with the provided loan details, PMI amount, and property address
        PrimaryMortgage propertyLoan = new PrimaryMortgage(250000.00, 3.1, 360, 35.12, propertyAddress);

        // Create an UnsecuredLoan object with the provided loan details
        UnsecuredLoan unsecuredLoan = new UnsecuredLoan(5000.00, 10.75, 48);

        // Print out the loan information for each loan using the toString() method.
        // Format the output with line breaks between each loan information for better readability
        System.out.format("%n%s%s%s%n", carLoan, propertyLoan, unsecuredLoan);
    }
}
