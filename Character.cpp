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
            xp = 0;
            level = 1;
            gold = 0;
        }
        Character::Character(string n) {
          name = n;
          maxhp = 25;
          hp = maxhp;
          strength = 10;
          maxmana = 2;
          mana = maxmana;
          alive = 1;
          xp = 0;
          level = 1;
          gold =0;
        }
        string Character::getName(){
            return name;
        }
        void Character::setName(string s){
            name = s;
        }
        int  Character::getXp(){
          return xp;
        }
        void  Character::setXp(int x){
          xp = x;
          // level up?!
          if (xp   > level * 100) {
            levelup();
          }
        }
        void  Character::levelup(){
          level++;
          cout << "You leveled up! You are now level" << level << endl;
          int nhp = 2 + rand() % level;
          cout << "You gained " << nhp << "maximum HP, and 1 Strength " << endl;
          maxhp += nhp;
          hp += nhp;
          strength ++;
        }
        int  Character::getLevel(){
          return level;
        }
        void  Character::setLevel(int l){
          level = l;
        }
        void  Character::setGold(int g){
          gold = g;
        }
        int  Character::getGold(){
          return gold;
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
