#include <iostream>

using namespace std;

class Monster {
protected:
    // it would be better to do this with inheritence, bc char and monster share a lot of stuff
    string name;
    int hp;
    int maxhp;
    int strength;
public:
    Monster(String n,int h,int s){
        name = n;
        maxhp = h;
        strength = s;
    }
    string getName(){
        return name;
    }
    void setName(string s){
        name = s;
    }
    int getHp(){
        return hp;
    }
    void setHp(int h){
        hp = h;
    }
    int getMaxHp(){
        return maxhp;
    }
    void setMaxHp(int m){
        maxhp = m;
    }
    int getStrength(){
        return strength;
    }
    void setStrength(int s){
        strength = s;
    }




};
