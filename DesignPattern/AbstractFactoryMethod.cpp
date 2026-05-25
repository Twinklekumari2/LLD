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

class BasicWheatBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Basic Wheat Burger with simple bun, lattice and sauce\n"; 
    }
};

class StandardWheatBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Standard Wheat Burger with simple bun, lattice and sauce\n"; 
    }
};

class PremiumWheatBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Premium Wheat Burger with simple bun, lattice and sauce\n"; 
    }
};

class GarlicBread {
public:
    virtual void prepare() {};
    virtual ~GarlicBread() {}

};

class NormalGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout << "Preparing normal garlic bread \n";
    }
};

class CheeseGarlicBread : public GarlicBread{
public:  
    void prepare() override{
        cout << "Preparing cheese garlic bread\n";
    }
};

class NormalWheatGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout << "Preparing normal garlic bread \n";
    }
};

class CheeseWheatGarlicBread : public GarlicBread{
public:  
    void prepare() override{
        cout << "Preparing cheese garlic bread\n";
    }
};

class BurgerFactory{
public:
    virtual Burger* createBurger(string& type) {};
    virtual GarlicBread* createGarlicBread(string& type) {};
    virtual ~BurgerFactory() {}
};

class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override{
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
    GarlicBread* createGarlicBread(string& type) override{
        if(type == "normal"){
            return new NormalGarlicBread();
        }else if(type == "cheese"){
            return new CheeseGarlicBread();
        }else{
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override{
        if(type == "basic"){
            return new BasicWheatBurger();
        }else if(type == "standard"){
            return new StandardWheatBurger();
        }else if(type == "premium"){
            return new PremiumWheatBurger();
        }else{
            return nullptr;
        }
    }
    GarlicBread* createGarlicBread(string& type) override{
        if(type == "normal"){
            return new NormalWheatGarlicBread();
        }else if(type == "cheese"){
            return new CheeseWheatGarlicBread();
        }else{
            return nullptr;
        }
    }
};




int main(){
    string typeBurger = "standard";
    string typeGarlicBread = "cheese";
    BurgerFactory* myBurgerFactory = new KingBurger();
    Burger* burger = myBurgerFactory->createBurger(typeBurger);
    GarlicBread* garlicBread = myBurgerFactory->createGarlicBread(typeGarlicBread);
    burger->prepare();
    garlicBread -> prepare();
    return 0;
}