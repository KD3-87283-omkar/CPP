#include <iostream>
using namespace std;
class InsufficientFundsException
{

    string message;

public:
    InsufficientFundsException()
    {
        cout << "Balance is low\n";
    }
    InsufficientFundsException(string message)
    {
        this->message = message;
    }

    void display() const
    {
        cout << message << endl;
    }
};

enum AccountType
{
    saving,
    current,
    dmat
};
class Account
{
    int accno;
    double balance;
    AccountType at;

public:
    Account()
    {
        balance = 0.0;
    }
    Account(int accno, double balance, AccountType at)
    {
        this->accno;
        this->balance = balance;
        this->at = at;
    }
    int getAccno()
    {
        return accno;
    }
    void deposite(double amt)
    {
        if (amt < 0)
            throw InsufficientFundsException("You can not add negative amount");
        balance += amt;
        cout << "Deposite successfull new Balance is :" << balance << endl;
    }
    void withdraw(double amt)
    {
        if (amt > balance)
            throw InsufficientFundsException("Insufficient Balance");
        balance -= amt;
        cout << "Withdrawal Successful. New Balance: " << balance << endl;
    }
    void accept()
    {
        int type;
        cout << "Enter account no\n";
        cin >> accno;
        cout << "Select Account Type (0 for SAVING, 1 for CURRENT, 2 for DMAT): \n";
        cin >> type;
        at = static_cast<AccountType>(type);
        cout << "Enter Balance\n";
        cin >> balance;
    }
    void display() const
    {
        cout << "Account no is :" << accno << endl;
        cout << "Available Balance is :" << balance << endl;
        cout << "Account type is :" << (at == AccountType::saving ? "saving" : at == AccountType::current ? "Current"
                                                                                                          : "Dmat")
             << endl;
    }
};
int menu()
{
    cout << "********************************\n";
    cout << "For Exit press 0\n";
    cout << "For create account press 1\n";
    cout << "For deposite Money press 2\n";
    cout << "For Withdraw Money press 3\n";
    cout << "For Display Balance press 4\n";
    cout << "*********************************\n";
    cout << "Enter your choice\n";

    int n;
    cin >> n;
    return n;
}
int searchAccount(Account **a, int no)
{
    for (int i = 0; i < 5; i++)
    {
        if (no == a[i]->getAccno())
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    Account *arr[5];
    int index = 0;

    int ch;
    while ((ch = menu()) != 0)
    {
        switch (ch)
        {
        case 1:
            arr[index] = new Account();
            arr[index]->accept();
            index++;
            break;
        case 2:
        {
            cout << "Enter account no for deposit money\n";
            int no;
            cin >> no;
            int i = searchAccount(arr, no);
            int amt;

            if (i != -1)
            {
                try
                {
                    cout << "Enter amount to deposite\n";
                    cin >> amt;
                    arr[i]->deposite(amt);
                }
                catch (InsufficientFundsException ex)
                {
                    ex.display();
                }
            }
            else
            {
                cout << "Else accont not found\n";
            }

            break;
        }
        case 3:
        {
            cout << "Enter account no for withdraw money\n";
            int no;
            cin >> no;
            int i = searchAccount(arr, no);
            int amt;

            if (i != -1)
            {
                try
                {
                    cout << "Enter amount for withdraw money\n";
                    cin >> amt;
                    arr[i]->withdraw(amt);
                }
                catch (InsufficientFundsException ex)
                {
                    ex.display();
                }
            }
            else
            {
                cout << "Else accont not found\n";
            }

            break;
        }
        case 4:
        {
            cout << "Enter account no\n";
            int no;
            cin >> no;
            int i = searchAccount(arr, no);
            if (i != -1)
            {
                arr[i]->display();
            }
            else
            {
                cout << "Else accont not found\n";
            }
            break;
        }
        default:
            break;
        }
    }
}