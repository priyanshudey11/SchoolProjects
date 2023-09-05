import pandas as pd

# Read the data from the Excel spreadsheet into a DataFrame
df = pd.read_excel('data.xlsx')

# Access the value in cell A1
value = df.at[0, 'A']

# Print the value
print(value)