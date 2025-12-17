#include<iostream>
#include<vector>
using namespace std;

class Product{
public:
    string name;
    int price;

    Product(string _name, int _price){
        this->name = _name;
        this->price = _price;
    }
};
 
class ShoppingCart{
public:
    vector<Product*> products;
    
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*> getProduct(){
        return products;
    }

    int calcTotal(){
        int total = 0;
        for(auto p : products){
            total += p->price;
        }
        return total;
    }
};

class InvoicePrinter{
public:
     ShoppingCart* cart;

     InvoicePrinter(ShoppingCart* _cart){
        this -> cart = _cart;
     }

     void printInvoice(){
        for(auto p : cart -> getProduct()){
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total- $" << cart->calcTotal() << endl;
     }
};


int main(){

    ShoppingCart* cart= new ShoppingCart();

    cart->addProduct(new Product("Laptop", 650000));
    cart->addProduct(new Product("Charger", 2000));

    InvoicePrinter* printer = new InvoicePrinter(cart);
    printer->printInvoice();


    return 0;

}