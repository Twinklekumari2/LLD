#include<iostream>
#include<vector>
using namespace std;

class Product{
public:
   double price;
   string name;

   Product(double _price, string _name){
     this -> price = _price;
     this -> name = _name;
   }
};

class ShoppingCart{
public:
    vector<Product*> products;

    void addProducts(Product* p){
        products.push_back(p);
    }

    const vector<Product*> getProducts(){
        return products;
    }

    //calculate total price;
    double calcTotal(){
        double total = 0;
        for(int i = 0; i < products.size(); i++){
            total += products[i]->price;
        }
        return total;
    }

    //print invoice
    void printInvoice(){
        cout << "Printing Invoice..." << endl;
        for(auto p : products){
            cout << p -> name << " - $" << p->price << endl;
        }
        cout << "Total - $" << calcTotal() << endl;
    }

    //saving to DB
    void saveToDB(){
        cout << "Saving to database...";
    }
};

int main(){

    ShoppingCart *S = new ShoppingCart();
    S -> addProducts(new Product(10.05, "Pen"));
    S -> addProducts(new Product(50.00, "Register"));

    S->printInvoice();
    S->saveToDB();

    return 0;
}