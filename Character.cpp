#include <iostream>
#include <vector>

#include "obj.h"

using namespace std;

//class Character {
//protected:
//    string name;
//    int hp;
//    int maxhp;
//    int strength;
//    int mana;
//    int maxmana;
//    vector<Item> inventory;
//    public:
        // contructor
        Character::Character() {
            name = "husk";
            maxhp = 5;
            hp = maxhp;
            strength = 1;
            maxmana = 2;
            mana = maxmana;
        }
        string Character::getName(){
            return name;
        }
        void Character::setName(string s){
            name = s;
        }
        int Character::getHp(){
            return hp;
        }
        void Character::setHp(int h){
            hp = h;
        }
        int Character::getMaxHp(){
            return maxhp;
        }
        void Character::setMaxHp(int m){
            maxhp = m;
        }
        int Character::getStrength(){
            return strength;
        }
        void Character::setStrength(int s){
            strength = s;
        }
        int Character::getMana(){
            return mana;
        }
        void Character::setMana(int m){
            mana = m;
        }
        int Character::getMaxMana(){
            return maxmana;
        }
        void Character::setMaxMana(int m){
            maxmana = m;
        }
//};
//int ma232in(){
//    Character a;
//   cout << a.getMana() << endl;
//    cout << a.getName() << endl;
//}
