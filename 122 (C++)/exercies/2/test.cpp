/*
Priyanshu Dey 
2/21/23
File matching program in which changes the balances of a client using there account id from a transactiions file.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Account {
    int accountNumber;
    string firstName;
    string lastName;
    double balance;
};

bool readAccount(Account& account, ifstream& file) {
    if (file >> account.accountNumber >> account.firstName >> account.lastName >> account.balance) {
        return true;
    } else {
        return false;
    }
}

void writeAccount(const Account& account, ofstream& file) {
    file << account.accountNumber << ' ' << account.firstName << ' ' << account.lastName << ' ' << fixed << setprecision(2) << account.balance << endl;
}

int main() {
    string masterFileName, transactionFileName, newMasterFileName;

    // Prompt the user for input file names
    cout << "Enter the name of the master account file: ";
    cin >> masterFileName;
    cout << "Enter the name of the transaction file: ";
    cin >> transactionFileName;
    cout << "Enter the name of the new master account file: ";
    cin >> newMasterFileName;

    // Open the input files and check for errors
    ifstream masterFile(masterFileName);
    if (!masterFile) {
        cout << "Error: Unable to open master account file." << endl;
        return 1;
    }

    ifstream transactionFile(transactionFileName);
    if (!transactionFile) {
        cout << "Error: Unable to open transaction file." << endl;
        return 1;
    }

    // Open the output file and check for errors
    ofstream newMasterFile(newMasterFileName);
    if (!newMasterFile) {
        cout << "Error: Unable to create new master account file." << endl;
        return 1;
    }

    // Read the first account from each input file
    Account masterAccount, transactionAccount;
    bool haveMasterAccount = readAccount(masterAccount, masterFile);
    bool haveTransactionAccount = readAccount(transactionAccount, transactionFile);

    // Process the input files
    while (haveMasterAccount || haveTransactionAccount)
     {
        if (masterAccount.accountNumber == transactionAccount.accountNumber) 
        {
            // Update the master account with the transaction amount
            masterAccount.balance += transactionAccount.balance;

            // Write the updated master account to the new master file
            writeAccount(masterAccount, newMasterFile);

            // Read the next record from both files
            haveMasterAccount = readAccount(masterAccount, masterFile);
            haveTransactionAccount = readAccount(transactionAccount, transactionFile);
        } 
        else 
        { 
            // Write the transaction record to the standard output
            cout << "Unmatched transaction record for account number " << transactionAccount.accountNumber << endl;

            // Read the next transaction account
            haveTransactionAccount = readAccount(transactionAccount, transactionFile);
        }
    }

    // Close all input and output files
    masterFile.close();
    transactionFile.close();
    newMasterFile.close();

    // Inform the user of the name of the new master file
    cout << "New master account file created: " << newMasterFileName << endl;
    return 0;
    //tried doing with an arraylists but could not figure out an effecent way without calling c functions
}
