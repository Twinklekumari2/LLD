#include<iostream>
using namespace std;

class Account{
public:
    double balance;
    Account(double b){
        if(b<0) throw invalid_argument("Balance cannot be negative");
        balance = b;
    }

    virtual void withdraw(double amount){
        if(balance>= amount){
            balance -= amount;
            cout << "Withdraw: amount is debited. Remaining balance is" << balance << endl;
        }else{
            throw runtime_error("Balance is not sufficient");
        }
    }
};


class FixedDepositAccount : public Account{
public:
     FixedDepositAccount(double b) : Account(b) {};

     void withdraw(double amount) override{
        throw runtime_error("Amount cannot be withdraw from fixed deposit account");
     }
};

int main(){
    Account* acc = new Account(800);
    acc->withdraw(600);

    acc = new FixedDepositAccount(700);
    acc->withdraw(90);
    return 0;
}