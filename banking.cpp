#include <iostream>
using namespace std;

class Bank_account
{
private:
    string accountNumber;
    string accountHolderName;
    
    public:
    
    double balance = 0;
    void get(string name, string accNum)
    {
        accountHolderName = name;
        accountNumber = accNum;
        
    }
    void deposite(double amount)
    {
        this->balance = this->balance + amount;
    }

    void withdraw(double amount)
    {
        if (this->balance >= amount)
        {
            this->balance = this->balance - amount;
            cout << "Collect your cash..." << endl;
        }
        else
        {
            cout << "Insufficient Balance..." << endl;
        }
    }

    void displayAccountInfo()
    {
        cout << "account number = " << this->accountNumber << endl
             << "account holder name = " << this->accountHolderName << endl
             << "balance = " << this->balance << endl;
    }

    void getBalance()
    {
        cout << "Your account balance is " << this->balance << endl;
    }
};
class Saving_account : public Bank_account
{
private:
    double intrestRate = 4;

public:
    void calculateIntrest()
    {
        double intrest;
        intrest = this->balance * this->intrestRate * 1 / 100;
        cout << "So your current interst amount is :- " << intrest << endl;
    }
};
class Checking_account : public Bank_account
{
public:
    double overDraftLimit = 10000;

public:
    void withDraw(double num1)
    {
        double amount;
        amount = num1;
        if (this->balance + this->overDraftLimit >= amount)
        {
            this->balance = this->balance - amount;
        }
        else
        {
            cout << "you withdrow exceed your overdraftlimit...." << endl;
        }
    }
    void deposite(double amount)
    {
        this->balance = this->balance + amount;
        if(this->balance >= 0){
            overDraftLimit = 10000;
        }
    }

    void checkOverDarft()
    {
        if (balance < 0 && balance > -10000)
        {
            this->overDraftLimit = overDraftLimit + balance;
            cout << "you have " << this->overDraftLimit << " overDraftLimit left..." << endl;
            overDraftLimit = 10000;
        }
        else
        {
            cout << "You have " << this->overDraftLimit << " overdraftlimit left..." << endl;
        }
    }
};
class Fixed_diposite_account : public Saving_account
{
private:
    int term;

public:
    void compuding(int term, double num1)
    {
        double c_amount;
        c_amount = num1;
        this->term = term;
        for (int i = 1; i <= term; i++)
        {
            int compund;
            compund = c_amount * 1 * 1 / 100;
            c_amount = c_amount + compund;
        }
        cout << "Your fd after your " << this->term << " month term is :- " << c_amount << endl;
    }
    void simple(int term, double num1)
    {
        double s_amount, simply;
        s_amount = num1;
        this->term = term;
        simply = s_amount * 1 * term / 100;
        s_amount = s_amount + simply;
        cout << "your fd after your " << this->term << " month term is :- " << s_amount << endl;
    }
    void calculateIntrest(int term, double num1)
    {
        double t_amount;
        t_amount = num1;
        this->term = term;
        if (term > 6)
        {
            compuding(term, t_amount);
        }
        else
        {
            simple(term, t_amount);
        }
    }
};

int main()
{
    Saving_account c1;
    Fixed_diposite_account c2;
    Checking_account c3;

    int n,n1,n2,n3;
    string yoo;
    string name;
    string accountNum;
    
    do
    {
        cout << "-----Welcome To Milan Finince Bank-----" << endl
             << endl;
        cout << "If you want to creat saving account press 1" << endl;
        cout << "If you want to creat checking account press 2" << endl;
        cout << "If you want to creat fixed_diposite account press 3" << endl;
        cout << "If you want to exit press 0" << endl;
        cout << "Select your choice :- ";
        cin >> n;
        cout << endl;

        switch (n)
        {
        case 1:
            cout << "Enter account holder name :- " << endl;
            cin >> name;
            cout << "Enter account number :- " << endl;
            cin >> accountNum;
            c1.get(name,accountNum);
            cout<<"Congratulation mrs/ms "<<name<<" your saving account is now active"<<endl<<endl;
            do
            {
                cout << "----saving account----" << endl<< endl;
                cout << "If you want account overview press 1" << endl;
                cout << "If you want view your balance press 2" << endl;
                cout << "If you want deposite cash press 3" << endl;
                cout << "If you want withdrow cash press 4" << endl;
                cout << "If you want check your intrest-amount prees 5" << endl;
                cout << "If you want exit press 0" << endl;
                cout << "press any one number :- ";
                cin >> n1;

                switch (n1)
                {
                case 1:
                    cout << "----account detail----" << endl
                         << endl;
                    c1.displayAccountInfo();
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 2:
                    cout << "----your balance----" << endl
                         << endl;
                    c1.getBalance();
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 3:
                    double money;
                    cout << "----Deposite----" << endl
                         << endl;
                    cout << "Deposite Your Money :- ";
                    cin >> money;
                    if (money > 0)
                    {
                        c1.deposite(money);
                        cout << "Money diposite successfully..." << endl
                             << endl;
                        cout << "Would you like cheak your balance press y/n :- ";
                        cin >> yoo;
                        cout << endl;
                        if (yoo == "y")
                        {
                            c1.getBalance();
                        }
                        else if (yoo == "n")
                        {
                            cout << "Thank you for banking with us..." << endl;
                        }
                        else
                        {
                            cout << "press only y/n..." << endl;
                        }
                    }
                    else
                    {
                        cout << "can't enter minus value" << endl;
                    }
                    break;
                case 4:
                    double withMoney;
                    cout << "----withdrow----" << endl
                         << endl;
                    cout << "Enter amount to withdraw :- ";
                    cin >> withMoney;
                    cout << endl;
                    if (withMoney > 0)
                    {
                        c1.withdraw(withMoney);
                        cout << "Would you like cheak your balance press y/n :- ";
                        cin >> yoo;
                        if (yoo == "y")
                        {
                            c1.getBalance();
                        }
                        else if (yoo == "n")
                        {
                            cout << "Thank you for banking with us..." << endl;
                        }
                        else
                        {
                            cout << "press only y/n..." << endl;
                        }
                    }else{
                        cout<< "can't enter minus value" << endl;
                    }
                    break;
                case 5:
                    cout << "----interestrate_amount----" << endl
                         << endl;
                    c1.calculateIntrest();
                    cout << "Note :- This interestrate amount is for 1 year period..." << endl;
                    cout << "Thank you...." << endl;
                    break;
                case 0:
                    cout << "Exiting...." << endl;
                    break;
                default:
                    cout << "Enter valid chice..." << endl
                         << endl;
                    break;
                }
            } while (n1 > 0);

            break;
        case 2:
            cout << "Enter account holder name :- " << endl;
            cin >> name;
            cout << "Enter account number :- " << endl;
            cin >> accountNum;
            c3.get(name,accountNum);
            cout<<"Congratulation mrs/ms "<<name<<" your credit account is now active"<<endl<<endl;
            do
            {
                cout << "----Checking_account----" << endl
                     << endl;
                cout << "If you want account overview press 1" << endl;
                cout << "If you want view your balance press 2" << endl;
                cout << "If you want deposite cash press 3" << endl;
                cout << "If you want withdrow cash press 4" << endl;
                cout << "If you want check your overdraft limit press 5" << endl;
                cout << "If you want exit press 0" << endl;
                cout << "press any one number :- ";
                cin >> n2;

                switch (n2)
                {
                case 1:
                    cout << "----account detail----" << endl
                         << endl;
                    c3.displayAccountInfo();
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 2:
                    cout << "----your balance----" << endl
                         << endl;
                    c3.getBalance();
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 3:
                    double money3;
                    cout << "----Deposite----" << endl
                         << endl;
                    cout << "Deposite Your Money :- ";
                    cin >> money3;
                    if (money3 > 0)
                    {
                        c3.deposite(money3);
                        cout << "Money diposite successfully..." << endl
                             << endl;
                        cout << "Would you like cheak your balance press y/n :- ";
                        cin >> yoo;
                        cout << endl;
                        if (yoo == "y")
                        {
                            c3.getBalance();
                        }
                        else if (yoo == "n")
                        {
                            cout << "Thank you for banking with us..." << endl;
                        }
                        else
                        {
                            cout << "press only y/n..." << endl;
                        }
                    }
                    else
                    {
                        cout << "can't enter minus value" << endl;
                    }
                    break;
                case 4:
                    double withMoney3;
                    cout << "----withdrow----" << endl
                         << endl;
                    cout << "Enter amount to withdraw :- ";
                    cin >> withMoney3;
                    cout << endl;
                    if (withMoney3 > 0)
                    {
                        c3.withDraw(withMoney3);
                        cout << "Would you like cheak your balance press y/n :- ";
                        cin >> yoo;
                        if (yoo == "y")
                        {
                            c3.getBalance();
                        }
                        else if (yoo == "n")
                        {
                            cout << "Thank you for banking with us..." << endl;
                        }
                        else
                        {
                            cout << "press only y/n..." << endl;
                        }
                    }else{
                        cout << "can't enter minus value." << endl;
                    }
                    break;
                case 5:
                    cout << "----overdraft-limit----" << endl
                         << endl;
                    c3.checkOverDarft();
                    break;
                case 0:
                    cout << "Exiting....." << endl;
                default:
                    cout << "Enter valid choice..." << endl
                         << endl;
                    break;
                }
            } while (n2 > 0);

            break;
        case 3:
            cout << "Enter account holder name :- " << endl;
            cin >> name;
            cout << "Enter account number :- " << endl;
            cin >> accountNum;
            c2.get(name,accountNum);
            cout<<"Congratulation mrs/ms "<<name<<" your fixed_diposite account is now active"<<endl<<endl;
            do
            {
                cout << "----fixed-diposite_account----" << endl
                     << endl;
                cout << "If you want account overview press 1" << endl;
                cout << "If you want view your balance press 2" << endl;
                cout << "If you want deposite cash press 3" << endl;
                cout << "If you want withdrow cash press 4" << endl;
                cout << "If you want start fd press 5" << endl;
                cout << "If you want exit press 0" << endl;
                cout << "press any one number :- ";
                cin >> n3;

                switch (n3)
                {
                case 1:
                    cout << "----account detail----" << endl
                         << endl;
                    c2.displayAccountInfo();
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 2:
                    cout << "----your balance----" << endl
                         << endl;
                    c2.getBalance();
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 3:
                    double money1;
                    cout << "----Deposite----" << endl
                         << endl;
                    cout << "Deposite Your Money :- ";
                    cin >> money1;
                    if (money1 > 0)
                    {
                        c2.deposite(money1);
                        cout << "Money diposite successfully..." << endl
                             << endl;
                        cout << "Would you like cheak your balance press y/n :- ";
                        cin >> yoo;
                        cout << endl;
                        if (yoo == "y")
                        {
                            c2.getBalance();
                        }
                        else if (yoo == "n")
                        {
                            cout << "Thank you for banking with us..." << endl;
                        }
                        else
                        {
                            cout << "press only y/n..." << endl;
                        }
                    }
                    else
                    {
                        cout << "can't enter minus value" << endl;
                    }
                    break;
                case 4:
                    double withMoney1;
                    cout << "----withdrow----" << endl
                         << endl;
                    cout << "Enter amount to withdraw :- ";
                    cin >> withMoney1;
                    cout << endl;
                    if (withMoney1 > 0)
                    {
                        c2.withdraw(withMoney1);
                        cout << "Would you like cheak your balance press y/n :- ";
                        cin >> yoo;
                        if (yoo == "y")
                        {
                            c2.getBalance();
                        }
                        else if (yoo == "n")
                        {
                            cout << "Thank you for banking with us..." << endl;
                        }
                        else
                        {
                            cout << "press only y/n..." << endl;
                        }
                    }
                    break;
                case 5:
                    int t, u;
                    cout << "----FD----" << endl;
                    cout << "Welcome to fixed-diposite department..." << endl;
                    cout << "Note :- if your fd term is less than or equal 6 month then the interst rate are calculate on simple intrest-rate if your fd is above 6 month then the intrest rate are calculate on compunding intrest-rate...." << endl;
                    cout << "Note :- we are calucate interst per month and our intrest-rate are 1(%) per month" << endl;
                    cout << "Deposite Your Principle Amount for FD :- ";
                    cin >> u;
                    cout << endl;
                    cout << "Enter your term(in month) here :- ";
                    cin >> t;
                    c2.calculateIntrest(t, u);
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 0:
                    cout << "Exiting....." << endl<< endl;
                    break;

                default:
                    cout << "Enter valid choice..." <<endl<<endl;
                    break;
                }

            } while (n3 > 0);

            break;
        case 0:
                cout<<"Thank you for visiting our bank..."<<endl;
            break;

        default:
                cout<<"Enter valid choice..."<<endl<<endl;
            break;
        }

    } while (n > 0);

    return 0;
}
