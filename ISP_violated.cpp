#include<iostream>
#include<vector>
using namespace std;

class Shape{
public:
    virtual void area() = 0;
    virtual void volume() = 0;
};

class Square: public Shape{
public:
    int side;
    Square(int s){
        this->side = s;
    }
    void area() override{
        cout << "Area: " << side*side << endl;
    }

    void volume() override{
        throw runtime_error("volume is not present in square");
    }
};

class Cube: public Shape{
public:
   int side;
   Cube(int s){
    this->side = s;
   }
   void area() override{
    cout << "Area: " << side*side*6 << endl;
   }
   void volume() override{
    cout << "Volume: " << side*side*side << endl;
   }
};

int main(){
    Shape* shape = new Square(9);
    shape->area();
    // shape->volume();

    shape = new Cube(6);
    shape->area();
    shape->volume();
}
