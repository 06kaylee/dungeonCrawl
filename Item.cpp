#include <iostream>
#include <vector>
#include "obj.h"

using namespace std;


    Item::Item(string n,int s){
        name = n;
        strengthmod = s;
    }
    string Item::getName(){
        return name;
    }
    void Item::setName(string n){
        name = n;
    }
    int Item::getStrength(){
        return strengthmod;
    }
    void Item::setStrength(int s){
        strengthmod = s;
    }
