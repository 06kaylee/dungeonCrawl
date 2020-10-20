#include <iostream>

using namespace std;

class Item {
protected:
    string name;
    // type ? for magic weapons or something ?
    // for now lets just do strengthmod
    int strengthmod;
public:
    Item(string n,int s){
        name = n;
        strengthmod = s;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    int getStrength(){
        return strengthmod;
    }
    void setStrength(int s){
        strengthmod = s;
    }
};
