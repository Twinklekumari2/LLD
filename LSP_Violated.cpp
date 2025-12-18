#include<iostream>
#include<vector>
using namespace std;

class Account{
public:
    virtual void deposit(double money) = 0;
    virtual void withdraw(double money) = 0;

};

class SavingAccount : public Account{
public:
    double balance;

    SavingAccount(){
        balance = 0;
    }

    void deposit(double money) override  {
        balance += money;
        cout  << money <<  " is deposited in your Saving account" << endl;
    }

    void withdraw(double money) override{
        if(balance >= money){
            balance -= money;
            cout << money <<  " is withdrawn from your Saving Account" << endl;
        }else{
            cout << "Money" << money <<  " is not suffienct in your Saving Account" << endl;
        }
    }
};

class CurrentAccount : public Account{
public:
    double balance;

    CurrentAccount(){
        balance = 0;
    }

    void deposit(double money) override  {
        balance += money;
        cout << money << " is deposited in your Current account" << endl;
    }

    void withdraw(double money) override{
        if(balance >= money){
            balance -= money;
            cout  << money <<  " is withdrawn from your Current Account" << endl;
        }else{
            cout << "Money is not suffienct in your Current Account" << endl;
        }
    }
};

class FixedDepositAccount : public Account{
public:
    double balance;

    FixedDepositAccount(){
        balance = 0;
    }

    void deposit(double money) override  {
        balance += money;
        cout << money << " is deposited in your Saving account" << endl;
    }

    void withdraw(double money) override{
        throw logic_error("Withdrawal not allowed in Fixed Deposit Account");
    }
};

class BankClient {
public:
    vector<Account*> accounts;

    BankClient(vector<Account*> acc){
        this -> accounts = acc;
    }

    void processTranscation(){
        for(auto acc : accounts){
            acc->deposit(1200);

            try{
               acc->withdraw(500);
            }catch(const logic_error& e){
               cout << "Exception " << e.what() << endl;
            }
        }
    }
};

int main(){

    vector<Account*> accounts;
    SavingAccount* saving = new SavingAccount();
    FixedDepositAccount* fixed = new FixedDepositAccount();
    CurrentAccount* current = new CurrentAccount();

    accounts.push_back(saving);
    accounts.push_back(fixed);
    accounts.push_back(current);

    BankClient* client = new BankClient(accounts);
    client->processTranscation();
}