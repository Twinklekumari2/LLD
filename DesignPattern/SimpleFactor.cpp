#include<iostream>
using namespace std;

class Burger{
public:
    virtual void prepare() {};
    virtual ~Burger() {}
};

class BasicBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Basic Burger with simple bun, lattice and sauce\n"; 
    }
};

class StandardBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Standard Burger with simple bun, lattice and sauce\n"; 
    }
};

class PremiumBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Premium Burger with simple bun, lattice and sauce\n"; 
    }
};

class BurgerFactory{
public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }else if(type == "standard"){
            return new StandardBurger();
        }else if(type == "premium"){
            return new PremiumBurger();
        }else{
            return nullptr;
        }
    }
};


int main(){
    string type = "standard";
    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->prepare();
    return 0;
}