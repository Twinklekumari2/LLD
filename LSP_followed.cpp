#include<iostream>
#include<vector>
using namespace std;

class DepositOnlyAccount{
public:
      virtual void deposit(double amount) = 0;
};

class WithdrawalAccount : public DepositOnlyAccount{
public:
      virtual void withdraw(double amount) = 0;

};

class SavingAccount : public WithdrawalAccount{
public:
    double balance;

    SavingAccount(){
        balance = 0;
    }

    void deposit(double money) override  {
        cout << "SAVING" << endl;
        balance += money;
        cout <<"Deposited:" << money << " to your Account. New Balance is " << balance << endl;
    }

    void withdraw(double money) override{
        if(balance >= money){
            balance -= money;
            cout <<"Withdrawal: " << money << " from your Account. New Balance is " << balance << endl;
        }else{
            cout << "Money" << money <<  " is not suffienct in your Saving Account" << endl;
        }
    }
};

class CurrentAccount : public WithdrawalAccount{
public:
    double balance;

    CurrentAccount(){
        balance = 0;
    }

    void deposit(double money) override  {
        cout << "CURRENT" << endl;
        balance += money;
        cout <<"Deposited:" << money << " to your Account. New Balance is " << balance << endl;
    }

    void withdraw(double money) override{
        if(balance >= money){
            balance -= money;
            cout <<"Withdrawal: " << money << " from your Account. New Balance is " << balance << endl;
        }else{
            cout << "Money is not suffienct in your Current Account" << endl;
        }
    }
};

class FixedAccount : public DepositOnlyAccount{
public:
    double balance;

    FixedAccount(){
        balance = 0;
    }

    void deposit(double amount) override{
        cout << "FIXED" << endl;
        balance += amount;
        cout <<"Deposited:" << amount << " to your Account. New Balance is " << balance << endl;
    }
};

class BankClient{
public:
    vector<DepositOnlyAccount*> depositAccounts;
    vector<WithdrawalAccount*> withdrawalAccounts;

    BankClient(vector<DepositOnlyAccount*> deposit, vector<WithdrawalAccount*> withdraw){
        this->depositAccounts = deposit;
        this->withdrawalAccounts = withdraw;
    }

    void depositAccTransaction(){
         for(auto acc : depositAccounts){
            acc->deposit(3000);
         }
    }
    void withdrawalAccTransaction(){
        for(auto acc: withdrawalAccounts){
            acc->deposit(6000);
            acc->withdraw(500);
        }
    }
};

int main(){
    vector<DepositOnlyAccount*> depositAccounts;
    depositAccounts.push_back(new FixedAccount());

    vector<WithdrawalAccount*> withdrawalAccounts;
    withdrawalAccounts.push_back(new SavingAccount());
    withdrawalAccounts.push_back(new CurrentAccount());

    BankClient* client = new BankClient(depositAccounts, withdrawalAccounts);
    client->depositAccTransaction();
    client->withdrawalAccTransaction();
}