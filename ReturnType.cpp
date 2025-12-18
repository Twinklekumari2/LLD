#include<iostream>
using namespace std;

class Animal {

};

class Dog: public Animal{

};

class Parent{
public:
    virtual Animal* random(){
        cout << "Parent Class Return Type" << endl;
        return new Animal();
    }
};

class Child : public Parent{
public:
    Dog* random() override{
        cout << "Child Class Return Type" << endl;
        return new Dog();
    }
};

class BankClient{
public:
    Parent* P;

    BankClient(Parent* P){
        this->P = P;
    }

    void show(){
        P->random();
    }
};
int main(){
    
    BankClient* client = new BankClient(new Child());
    client->show();

    client = new BankClient(new Parent());
    client->show();
    return 0;
}