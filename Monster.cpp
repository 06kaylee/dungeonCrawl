//Authors: Ethan Smith, Aramis Hahne, Kaylee Hall
//Class:CS-3150-Dr.Cantrell
//Version: 10/25/20

#include <iostream>
//#include "obj.h"

using namespace std;

//name will be like " goblin", or "CS professor")
  //
    Monster::Monster(){// this should probably never get called :^)
      int n = rand() % 3;
      name = "DEFAULT FOOKIN MONSTER";
      maxhp = 10 + rand() % 10;
      hp=  maxhp;
      strength = 3;
      alive = 1;
    }
    Monster::Monster(int diff){
        int n = rand() % img.size();// this sets the monster's name
        name = img[n][0];
        image = img[n];
        maxhp = 10 + rand() % diff*3;
        hp=  maxhp;
        //Commented out the rand in strength; will change later for different types of monsters
        strength = 3 + rand() % diff; //+ rand() % diff;
        //generates a random monster based on the game's difficulty
        // can use math.random * diff or something :^)
        alive = 1;// it's ALIVE!
    }
    Monster::Monster(string n,int h,int s){
        name = n;
        maxhp = h;
        strength = s;
        alive = 1;
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
    }// test :)

//********************************************.****************

    int Monster::attack(){
      int dmg = rand () % (strength + 1);
      return dmg;
    }
    bool Monster::isAlive(){
      return alive;
    }
    void Monster::setAlive(bool b){
      alive = b;
    }
    void Monster::takeDmg(int dmg){
      int hp = getHp();
      hp = hp - dmg;
      setHp(hp);
      if (hp <= 0){
        setAlive(0);
      //  monsterDieText();
      }
    }
    void Monster::printImage(){// omegalul
      for (int x = 1;x<image.size();x++){
        cout << image[x] << endl;
      }

    }
    void Monster::monsterDieText(){
      cout << "The " << getName() << " died!" << endl;
      cout << "You were victorious!" << endl;
    }

    //Needs Attack
    //Needs way to die
