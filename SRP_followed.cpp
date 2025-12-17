#include<iostream>
#include<vector>
using namespace std;

class Product{
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};


class ShoppingCart{
public:
    vector<Product*> proudcts;

    void addProducts(Product* p){
         proudcts.push_back(p);
    }

    const vector<Product*> getProducts(){
        return proudcts;
    }

    //calculate total
    double calcTotal(){
        double total = 0;
        for(auto p : proudcts){
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
public:
    ShoppingCart* cart;

    ShoppingCartPrinter(ShoppingCart* cart){
        this -> cart = cart;
    }

    void printInvoice(){
        for(auto p : cart->getProducts()){
           cout << p->name << "- $" << p->price << endl;
        }
        cout << "Total -$" << cart->calcTotal() << endl;
    }
};

class ShoppingCartStorage{
public:
    ShoppingCart *cart;

    ShoppingCartStorage(ShoppingCart* cart){
        this -> cart = cart;
    }

    void saveToDb(){
        cout << "Saving to Databse.." << endl;
    }
};

int main(){

    ShoppingCart* S = new ShoppingCart();

    S->addProducts(new Product("Laptop", 65000.00));
    S->addProducts(new Product("Balloon", 6.00));
    S->addProducts(new Product("Cake", 350.00));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(S);
    printer->printInvoice();

    ShoppingCartStorage *save = new ShoppingCartStorage(S);
    save->saveToDb();


    return 0;
}