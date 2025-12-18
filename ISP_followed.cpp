#include<iostream>
#include<vector>
using namespace std;

class ThreeDShape{
public:
    virtual void area() = 0;
    virtual void volume() = 0;
};

class TwoDShape{
public:
    virtual void area() = 0;
};

class Square: public TwoDShape{
public:
    int side;
    Square(int s){
        this->side = s;
    }
    void area() override{
        cout << "Area: " << side*side << endl;
    }
};

class Cube: public ThreeDShape{
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
    ThreeDShape* shape1 = new Cube(9);
    shape1->area();
    shape1->volume();

    TwoDShape* shape2 = new Square(90);
    shape2->area();
}
