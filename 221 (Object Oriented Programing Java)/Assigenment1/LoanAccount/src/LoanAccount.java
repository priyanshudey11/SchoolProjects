import java.text.DecimalFormat;
public class LoanAccount 
{
    // instance variable to store the loan principal
    private double principal; 
    // static variable to store the annual interest rate for all accounts
    private static double annualInterestRate; 
    
    public LoanAccount(double principal)
     {
        // constructor to set the loan principal
        this.principal = principal; 
    }

    public double calculateMonthlyPayment(int numberOfPayments) 
    {
        // calculate monthly interest rate
        double monthlyInterest = annualInterestRate / 12; 
        // calculate monthly payment using formula
        double monthlyPayment = principal * (monthlyInterest / (1 - Math.pow(1 + monthlyInterest, -numberOfPayments))); 
        // return calculated monthly payment
        return monthlyPayment; 
    }

    public static void setAnnualInterestRate(double interestRate) 
    {
        // method to set the annual interest rate
        annualInterestRate = interestRate; 
    }

    public static void main(String[] args)
     {
        // format decimal numbers to two decimal places
        DecimalFormat df = new DecimalFormat("0.00"); 
        // instantiate LoanAccount object with $5000.00 principal
        LoanAccount loan1 = new LoanAccount(5000.00); 
        // instantiate LoanAccount object with $31000.00 principal
        LoanAccount loan2 = new LoanAccount(31000.00); 
        // Set annualInterestRate to 1% and calculate monthly payments for loan1 and loan2
        setAnnualInterestRate(0.01);
        System.out.println("Monthly payments for loan 1 of $5000.00 and loan 2 $31000.00 for 3, 5, and 6 years of loans at 1% interest.");
        System.out.println("Loan\t\t3 years\t\t5 years\t\t6 years");
        System.out.println("Loan 1:\t\t$" + df.format(loan1.calculateMonthlyPayment(36)) + "\t\t$" + df.format(loan1.calculateMonthlyPayment(60)) + "\t\t$" + df.format(loan1.calculateMonthlyPayment(72)));
        System.out.println("Loan 2:\t\t$" + df.format(loan2.calculateMonthlyPayment(36)) + "\t\t$" + df.format(loan2.calculateMonthlyPayment(60)) + "\t\t$" + df.format(loan2.calculateMonthlyPayment(72)));
        System.out.println();

        // Set annualInterestRate to 5% and calculate monthly payments for loan1 and loan2
        setAnnualInterestRate(0.05);
        System.out.println("Monthly payments for loan 1 of $5000.00 and loan 2 $31000.00 for 3, 5, and 6 years of loans at 5% interest.");
        System.out.println("Loan\t\t3 years\t\t5 years\t\t6 years");
        System.out.println("Loan 1:\t\t$" + df.format(loan1.calculateMonthlyPayment(36)) + "\t\t$" + df.format(loan1.calculateMonthlyPayment(60)) + "\t\t$" + df.format(loan1.calculateMonthlyPayment(72)));
        System.out.println("Loan 2:\t\t$" + df.format(loan2.calculateMonthlyPayment(36)) + "\t\t$" + df.format(loan2.calculateMonthlyPayment(60)) + "\t\t$" + df.format(loan2.calculateMonthlyPayment(72)));
        System.out.println();
    }
}
