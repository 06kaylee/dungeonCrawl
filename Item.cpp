//Authors: Ethan Smith, Aramis Hahne, Kaylee Hall
//Class:CS-3150-Dr.Cantrell
//Version: 10/25/20

#include <iostream>
#include <vector>
#include "obj.h"

using namespace std;

    Item::Item() {
      //picks a random name from the three in the array
      type = 1 + (rand() % 2);
      //cout << type << "type";
      strengthmod = 1 + (rand() % 5);
      if (type == 1){
      name = weps[rand() % sizeof(weps)/sizeof(weps[0])];
    }
    else {
      cout << "It's a tool" << endl;
      name = tools[rand() % sizeof(tools)/sizeof(tools[0])];
      strengthmod += 8;
    }
      //random strength from 1 to the level of the player

      uses =3;
    }
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
    int Item::getUses(){
      return uses;
    }
    void Item::setUses(int u){
      uses = u;
    }
    void Item::printitem(){
      cout << strengthmod;
      cout << uses;
      cout << name << endl;
    }
    int Item::getType(){
      return type;
    }
