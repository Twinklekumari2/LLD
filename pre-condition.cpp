#include<iostream>
using namespace std;

//pre: password length must be ge than 8
class User{
public:
    virtual void createPassword(int length){
        if(length < 8) throw runtime_error("Password length cannot be less than 8");
        cout << "Password successfully created" << endl;
    }
};

class AdminUser: public User{
public:
    void createPassword(int length) override{
        if(length < 6) throw runtime_error("Password length cannot be less than 6");
        cout << "Password successfully created" << endl;
    }

};

int main(){
    User* user = new AdminUser();
    user->createPassword(7);
    return 0;
}