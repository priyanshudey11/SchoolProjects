import java.util.ArrayList;
public class main 
{
    public static void main(String[] args) 
    {
        // Create three different loan objects, one of each type.

        // Create a CarLoan object with the provided loan details and vehicle VIN
        CarLoan carLoan1 = new CarLoan(25000.00, 4.9, 72, "IRQ3458977");
        CarLoan carLoan2 = new CarLoan(12000.00, 5, 60, "NXK6767876");
        // Create an Address object with the provided property address details
        Address propertyAddress1 = new Address("321 Main Street", "State College", "PA", "16801");
        Address propertyAddress2 = new Address("783 Maple Lane", "State College", "PA", "16801");
        // Create a PrimaryMortgage object with the provided loan details, PMI amount, and property address
        PrimaryMortgage propertyLoan1 = new PrimaryMortgage(250000.00, 3.75, 360, 35.12, propertyAddress1);
        PrimaryMortgage propertyLoan2 = new PrimaryMortgage(375000.00, 2.5, 360, 53.12, propertyAddress2);
        
        // Create an UnsecuredLoan object with the provided loan details
        UnsecuredLoan unsecuredLoan = new UnsecuredLoan(5000.00, 10.75, 48);

        Customer customerA = new Customer("Tony", "Stark", "111-22-3333");
        Customer customerB = new Customer("Gal", "Gadot", "444-55-6666");

        customerA.addLoanAccount(carLoan1);
        customerA.addLoanAccount(propertyLoan1);
        customerA.addLoanAccount(unsecuredLoan);

        customerB.addLoanAccount(carLoan2);
        customerB.addLoanAccount(propertyLoan2);

        ArrayList<Customer> customers = new ArrayList<>();
        customers.add(customerA);
        customers.add(customerB);

        System.out.println("Monthly Report of Customers by Loan Account");
        for (Customer customer : customers) {
            System.out.println(customer.printMonthlyReport());
        }
    }
}