#include<iostream>

using namespace std;

class BankAccount
{
protected:
	
    string accountNumber;
    string accountHolderName;
    double balance;

	public:
    		BankAccount(string accNum, string holderName, double initialBalance)
       			 : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    void deposit(double amount) 
	{
        if (amount > 0)
		 {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else 
		{
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) 
	{
        if (amount > 0 && amount <= balance) 
		{
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else 
		{
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    void displayAccountInfo()
	 {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void calculateInterest()
	 {
        cout << "No interest calculation for this account type." << endl;
    }

    virtual ~BankAccount() {}
};
	class SavingsAccount : public BankAccount 
	{
    double interestRate;

	public:
			SavingsAccount(string accNum, string holderName, double initialBalance, double rate)
        		: BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        cout << "Interest (Savings Account): " << interest << endl;
    }
};


	class CheckingAccount : public BankAccount 
	{
    double overdraftLimit;

		public:
   			 CheckingAccount(string accNum, string holderName, double initialBalance, double limit)
       				 : BankAccount(accNum, holderName, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override 
	{
        if (amount > 0 && balance - amount >= -overdraftLimit)
		 {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } 
		else
		 {
            cout << "Exceeds overdraft limit!" << endl;
        }
    }
};


	class FixedDepositAccount : public BankAccount {
    int term;  
    double interestRate;

		public:
   			 FixedDepositAccount(string accNum, string holderName, double initialBalance, int termDuration, double rate)
       			 : BankAccount(accNum, holderName, initialBalance), term(termDuration), interestRate(rate) {}

    void calculateInterest() override 
	{
        double interest = balance * (interestRate / 100) * (term / 12.0);
        cout << "Interest (Fixed Deposit): " << interest << endl;
    }
};

int main() 
{
    BankAccount* account = nullptr;
    int choice;

    do {
        cout << "\n--- Bank Account Management ---\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Display Account Info\n";
        cout << "7. Calculate Interest\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
			{
                string accNum, holderName;
                double balance, rate;
                
                cout << "Enter Account Number: ";
                cin >> accNum;
                
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holderName);
                
                cout << "Enter Initial Balance: ";
                cin >> balance;
                
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
            cin >> rate;
            account = new SavingsAccount(accNum, holderName, balance, rate);
                cout << "Savings Account Created.\n";
                break;
            }
            case 2:
			 {
                string accNum, holderName;
                double balance, limit;
                
                cout << "Enter Account Number: ";
                cin >> accNum;
                
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holderName);
                
                cout << "Enter Initial Balance: ";
                cin >> balance;
                
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
                account = new CheckingAccount(accNum, holderName, balance, limit);
                cout << "Checking Account Created.\n";
                break;
            }
            case 3:
			 {
                string accNum, holderName;
                double balance, rate;
                int term;
                
                cout << "Enter Account Number: ";
                cin >> accNum;
                
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holderName);
                
                cout << "Enter Initial Balance: ";
                cin >> balance;
                
                cout << "Enter Term (months): ";
                cin >> term;
                
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                account = new FixedDepositAccount(accNum, holderName, balance, term, rate);
                cout << "Fixed Deposit Account Created.\n";
                break;
            }
            case 4:
			 {
                if (account)
				 {
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                }
				 else
				 {
                    cout << "No account created yet.\n";
                }
                break;
            }
            
            case 5: 
			{
                if (account) 
				{
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                }
				 else 
				{
                    cout << "No account created yet.\n";
                }
                break;
            }
            
            case 6: 
			{
                if (account) 
				{
                    account->displayAccountInfo();
                } else 
				{
                    cout << "No account created yet.\n";
                }
                break;
            }
            case 7:
			 {
                if (account) 
				{
                    account->calculateInterest();
                } else 
				{
                    cout << "No account created yet.\n";
                }
                break;
            }
            case 8:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } 
	while (choice != 8);

    delete account;
    return 0;
}
