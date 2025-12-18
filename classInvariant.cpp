#include<iostream>
using namespace std;

// Invariant : balance cannot be negative
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

class CheatAccount: public Account{
public:
    CheatAccount(double b) : Account(b) {};

    void withdraw(double amount) override{
        balance -= amount;
        cout << "Withdraw: amount is debited. Remaining balance is" << balance << endl;
    }

};

int main(){
    Account* acc = new CheatAccount(100);
    acc->withdraw(500);
    return 0;
}