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
            maxhp = 25;
            hp = maxhp;
            strength = 10;
            maxmana = 2;
            mana = maxmana;
            alive = 1;
        }
        Character::Character(string n) {
          name = n;
          maxhp = 25;
          hp = maxhp;
          strength = 10;
          maxmana = 2;
          mana = maxmana;
          alive = 1;
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
        bool Character::isAlive(){
          return alive;
        }
        void Character::setAlive(bool b){
          alive = b;
        }
        int Character::attack(){
          int dmg = rand () % (strength + 1);
          return dmg;
        }
        void Character::takeDmg(int dmg){
          int hp = getHp();
          hp = hp - dmg;
          setHp(hp);
          if (hp <= 0){
            setAlive(0);
          //  characterDieText();
          }
        }
        void Character::characterDieText(){
          cout << "You died!" << endl;
          cout << "git good noob!" << endl;
        }
//};
//int ma232in(){
//    Character a;
//   cout << a.getMana() << endl;
//    cout << a.getName() << endl;
//}
