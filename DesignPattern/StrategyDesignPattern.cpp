#include<iostream>
using namespace std;

class Walk{
public:
    virtual void walk() = 0;
    virtual ~Walk() {};
};

class Walkable : public Walk{
public:
    void walk() override{
        cout << "Walking...." << endl;
    }
};

class NonWalkable: public Walk{
public:
   void walk() override{
    cout << "no walking..." << endl;
   }
};

class Talk{
public:
    virtual void talk() = 0;
    virtual ~Talk() {};
};

class Talkable : public Talk{
public:
    void talk() override{
        cout << "Talking...." << endl;
    }
};

class NonTalkable: public Talk{
public:
   void talk() override{
    cout << "no Talking..." << endl;
   }
};

class Fly{
public:
    virtual void fly() = 0;
    virtual ~Fly() {};
};

class Flyable : public Fly{
public:
    void fly() override{
        cout << "Flying...." << endl;
    }
};

class NonFlyable: public Fly{
public:
   void fly() override{
    cout << "no Flying..." << endl;
   }
};

class Robot{
public:
    Walk* w;
    Talk* t;
    Fly* f;

    Robot(Walk* walk, Talk* talk, Fly* fly){
        this->f = fly;
        this->t = talk;
        this->w = walk;
    }

    void fly(){
        f->fly();
    }
    void walk(){
        w->walk();
    }
    void talk(){
        t->talk();
    }

    virtual void Projection() = 0;
};

class CompanionRobot : public Robot{
public:
    CompanionRobot(Walk* w, Talk* t, Fly* f) : Robot(w,t,f){};
    void Projection() override {
        cout << "Projecting companion robot ..." << endl;
    }
};

class WorkerRobot : public Robot{
public:
    WorkerRobot(Walk* w, Talk* t, Fly* f) : Robot(w,t,f){};
    void Projection() override {
        cout << "Projecting Worker robot ..." << endl;
    }
};

int main(){
    cout << "------------- Companion Robot ---------------\n";
    Robot* robot = new CompanionRobot(new Walkable(), new Talkable(), new NonFlyable());
    robot->Projection();
    robot->fly();
    robot->walk();
    robot->talk();

    cout << "------------- Worker Robot --------------\n";

    robot = new WorkerRobot(new NonWalkable(), new Talkable(), new Flyable());
    robot->Projection();
    robot->fly();
    robot->walk();
    robot->talk();

    delete robot;
}