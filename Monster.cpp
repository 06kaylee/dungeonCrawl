#include <iostream>
//#include "obj.h"

using namespace std;

//name will be like " goblin", or "CS professor")
  //  

    Monster::Monster(int diff){
        
        int n = rand() % 3;
        name = names[n];
        maxhp = 10 + rand() % diff;
        hp=  maxhp;
        strength = 3 + rand() % diff;
        //generates a random monster based on the game's difficulty
        // can use math.random * diff or something :^) 
    }
    Monster::Monster(string n,int h,int s){
        name = n;
        maxhp = h;
        strength = s;
    }
    string Monster::getName(){
        return name;
    }
    void Monster::setName(string s){
        name = s;
    }
    int Monster::getHp(){
        return hp;
    }
    void Monster::setHp(int h){
        hp = h;
    }
    int Monster::getMaxHp(){
        return maxhp;
    }
    void Monster::setMaxHp(int m){
        maxhp = m;
    }
    int Monster::getStrength(){
        return strength;
    }
    void Monster::setStrength(int s){
        strength = s;
    }



