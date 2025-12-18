#include<iostream>
using namespace std;

class Parent{
public:
    virtual void printMsg(string message){
        cout << "Message: " << message << endl;
    }
};

class Child : public Parent{
public:
    void printMsg(string message) override{
        cout << "Message: " << message << endl;
    }
};

class BankClient{
public:
    Parent* P;

    BankClient(Parent* P){
        this->P = P;
    }

    void getMessage(){
        P->printMsg("Hello");
    }
};

int main(){

    BankClient* client = new BankClient(new Child());
    client->getMessage();

    return 0;
}