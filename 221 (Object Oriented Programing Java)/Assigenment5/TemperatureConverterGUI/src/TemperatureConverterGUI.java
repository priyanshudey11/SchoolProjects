import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class TemperatureConverterGUI extends JFrame 
    {

        private JTextField inputField;
        private JRadioButton celsiusToFahrenheitButton;
        private JRadioButton fahrenheitToCelsiusButton;
        private JButton convertButton;
        private JLabel resultLabel;

        public TemperatureConverterGUI()
            {
                initComponents();
            }

        private void initComponents() 
            {
                setTitle("Temperature Converter");
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                JPanel mainPanel = new JPanel();
                mainPanel.setLayout(null);
                
                //Title
                JLabel titleLabel = new JLabel("Temperature Converter");
                titleLabel.setBounds(60,10, 400, 25);
                // Increase the font size
                titleLabel.setFont(titleLabel.getFont().deriveFont(20f)); 
                //titleLabel.setHorizontalAlignment(JLabel.CENTER);
                mainPanel.add(titleLabel);
                
                
                // Temperature label
                JLabel inputLabel = new JLabel("Enter temperature to Convert:");
                inputLabel.setBounds(40, 60, 400, 25);
                mainPanel.add(inputLabel);

                // Text field for temperature input
                inputField = new JTextField();
                inputField.setBounds(240, 60, 100, 25);
                mainPanel.add(inputField);
                //Conversion label
                JLabel conversionlabel = new JLabel("Choose Conversion Type:");
                conversionlabel.setBounds(120, 90, 200,25);
                mainPanel.add(conversionlabel);
                
                // Buttons for conversion options
                celsiusToFahrenheitButton = new JRadioButton("Celsius  to Fahrenheit");
                celsiusToFahrenheitButton.setBounds(120, 130, 200, 25);
                mainPanel.add(celsiusToFahrenheitButton);

                fahrenheitToCelsiusButton = new JRadioButton("Fahrenheit to Celsius");
                fahrenheitToCelsiusButton.setBounds(120, 160, 200, 25);
                mainPanel.add(fahrenheitToCelsiusButton);

                // Group the radio buttons together
                ButtonGroup conversionGroup = new ButtonGroup();
                conversionGroup.add(celsiusToFahrenheitButton);
                conversionGroup.add(fahrenheitToCelsiusButton);

                // Convert button
                convertButton = new JButton("Convert");
                convertButton.setBounds(120, 200, 100, 25);
                mainPanel.add(convertButton);

                // Result label
                resultLabel = new JLabel();
                resultLabel.setBounds(20, 180, 200, 25);
                mainPanel.add(resultLabel);

                // ActionListener for the convert button
                convertButton.addActionListener(new ActionListener() 
                    {
                        public void actionPerformed(ActionEvent e) 
                            {
                                convertTemperature();
                            }
                    
                    });

                // Set the main panel as the content pane
                setContentPane(mainPanel);
                pack();
                // Set the preferred size of the main panel
                setSize(400, 300); 
                setLocationRelativeTo(null);
            }

        private void convertTemperature() 
            {
                String inputText = inputField.getText();
                if (!inputText.isEmpty()) 
                    {
                        try 
                            {
                                // Parse the input temperature value
                                double temperature = Double.parseDouble(inputText);
                                double convertedTemperature;
                                String resultText;
                                if (celsiusToFahrenheitButton.isSelected())
                                    {
                                        // Convert Celsius to Fahrenheit
                                        convertedTemperature = (9.0 / 5.0) * temperature + 32;
                                        resultText = String.format("%.1f degrees Fahrenheit", convertedTemperature);
                                    } 
                                else if (fahrenheitToCelsiusButton.isSelected()) 
                                    {
                                        // Convert Fahrenheit to Celsius
                                        convertedTemperature = (5.0 / 9.0) * (temperature - 32);
                                        resultText = String.format("%.1f degrees Celsius", convertedTemperature);
                                    } 
                                    else 
                                        {
                                            resultText = "Please select a conversion.";
                                        }
                                resultLabel.setText(resultText);
                            }
                            catch (NumberFormatException ex) 
                                {
                                    resultLabel.setText("Invalid input.");
                                }
                    }
                    else 
                        {
                            resultLabel.setText("Please enter a temperature.");
                        }
            }

        public static void main(String[] args) 
            {
                java.awt.EventQueue.invokeLater(new Runnable() 
                {
                    public void run() 
                        {
                            new TemperatureConverterGUI().setVisible(true);
                        }
                });
            }
    }
