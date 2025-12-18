#include<iostream>
using namespace std;

class Car{
public:
    int speed;
    Car(){
        speed = 0;
    }
    virtual void accelerate(){
        speed += 20;
        cout << "Accelerate: by 20. New Speed: " << speed << endl;
    }
     
    //post condition: speed should decrease
    virtual void brake(){
        speed -= 20;
        cout << "Brake: by 20. New Speed: " << speed << endl;
    }
};

class Hybrid: public Car{
public:
    int charging;
    Hybrid(){
        charging = 0;
    }
    void accelerate() override{
        speed += 20;
    }

    //post-condition : speed should decrease after applying brake
    //charging musst increase
    void brake() override{
        cout << "Brakes" << endl;
        speed -= 20;
        charging += 10;
    }
};

int main(){
    Car* car = new Car();
    car->accelerate();
    car->brake();
}