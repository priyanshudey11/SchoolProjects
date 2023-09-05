import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PizzaServingsCalculator extends JFrame 
{
    private JLabel resultLabel;

    public PizzaServingsCalculator()
     {
        // Set the frame title
        setTitle("Pizza Servings Calculator"); 
        // Set the close operation
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        // Set the frame size
        setSize(350, 300); 
        // Set the grid layout with 4 rows and 1 column
        setLayout(new GridLayout(4, 1)); 
        JLabel titleLabel = new JLabel("Pizza Servings Calculator");
        // Set the label color to red
        titleLabel.setForeground(Color.RED); 
        // Add the title label to the frame
        add(titleLabel); 
        // Create a new panel for line 2
        JPanel line2 = new JPanel(); 
        // Add a label to the panel
        line2.add(new JLabel("Enter the size of the pizza in inches: ")); 
        // Create a text field for input
        JTextField sizeTextField = new JTextField(4); 
        // Add the text field to the panel
        line2.add(sizeTextField); 
        // Add the panel to the frame
        add(line2); 
        // Create a button
        JButton calculateButton = new JButton("Calculate Servings"); 
        calculateButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                // Get the size input from the text field
                double size = Double.parseDouble(sizeTextField.getText()); 
                // Calculate the number of servings
                double servings = Math.pow(size / 8, 2); 
                // Set the result label text
                resultLabel.setText(String.format("Number of Servings: %.2f", servings)); 
            }
        });
        // Add the button to the frame
        add(calculateButton); 
        // Create a label for displaying the result
        resultLabel = new JLabel(); 
        // Add the result label to the frame
        add(resultLabel); 
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(new Runnable() 
        {
            
            public void run() {
                PizzaServingsCalculator calculator = new PizzaServingsCalculator();
                // Set the frame visible
                calculator.setVisible(true); 
            }
        });
    }
}
