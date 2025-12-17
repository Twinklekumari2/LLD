#include<iostream>
#include<vector>
using namespace std;

class Product{
public:
    string name;
    int price;

    Product(string name, int price){
        this->name = name;
        this->price = price;
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

     InvoicePrinter(ShoppingCart* cart){
        this -> cart = cart;
     }

     void printInvoice(){
        for(auto p : cart -> getProduct()){
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total- $" << cart->calcTotal() << endl;
     }
};

class DbStorage{
public:
    ShoppingCart* cart;

    DbStorage(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToSQLDB(){
        cout << "Saving to SQL Db" << endl;
    }

    void saveToMongoDB(){
        cout << "Saving to Mongo Db" << endl;
    }

    void saveToFile(){
        cout << "Saving to File" << endl;
    }
    
};

int main(){

    ShoppingCart* cart= new ShoppingCart();

    cart->addProduct(new Product("Laptop", 650000));
    cart->addProduct(new Product("Charger", 2000));

    InvoicePrinter* printer = new InvoicePrinter(cart);
    printer->printInvoice();

    DbStorage* db = new DbStorage(cart);
    db->saveToFile();
    db->saveToMongoDB();
    db->saveToSQLDB();

    return 0;

}