#include<iostream>
using namespace std;

class Parent{
public:
   virtual void getValue() noexcept(false){
    throw out_of_range("Parent Error");
   }
};

class Child : public Parent{
public:
    void getValue() override{
        throw logic_error("Child Error");
    }
};

class Client{
public:
    Parent* P;

    Client(Parent* P){
        this->P = P;
    }

    void show(){
        try{
            P->getValue();
        }catch(const out_of_range& e){
            cout << "Exception : " << e.what() << endl;
        }
    }
};

int main(){

    Client* client = new Client(new Parent());
    client->show();

    client = new Client(new Child());
    client->show();

    return 0;
}