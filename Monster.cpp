#include <iostream>
//#include "obj.h"

using namespace std;

//name will be like " goblin", or "CS professor")
  //
    Monster::Monster(){
      int n = rand() % 3;
      name = "DEFAULT FOOKIN MONSTER";
      maxhp = 10 + rand() % 10;
      hp=  maxhp;
      strength = 3;
      alive = 1;
    }
    Monster::Monster(int diff){

        int n = rand() % 3;// this sets the monster's name
        name = names[n];
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
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMNx:coOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXNMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMW0;   .;o0WMMMMMMMMMMMMMMMMMMMMMMMNOo;;OMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMNd.    .;kNMMMMMMMMMMMMMMMMMMNkc'   cNMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMM0;      ,kNKkoc:;:cccoxONWO;    .oXMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMNx;.    .,.            ;c.    ;kWMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMW0;                     .,oONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMXo.                   ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMX;       o      o     ;0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMNl                     '0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMXc         __         .kMMMMMXOKWMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMXc                   lNMMMMWo .oXMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMNo.               .xNMMMMMWl   lNMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:.          .'oKMMMMMMMMx.   lNMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMNO:.        .oNMMMMMMMMMMk.   .OMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMNo.           'OMMMMMMMMMMk..,cdXMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMXc              ,0MMMMMMMMMx..kWMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMNc                ;KMMMMMMM    cXMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMx.                 ,dkK    oxOOXMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMNc                         kNMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMX:                   '0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMk.                    ;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMM0'                      oWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMX:                       lWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMXc                        ;XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMWo                         .xMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMk.                          ;XMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMM0doool. .:c::;;'''''''.     .xMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMK, oWMMMMMWNWWNNN0, 'xO0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMO..kMMMMMMMMMMMMMk..xMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMx..OMMMMMMMMMMMMMd '0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMx.'0MMMMMMMMMMMMWl ;XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMO..dMMMMMMMMMMMMWl :NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMN: cNMMMMMMMMMMMN: cNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMX: 'xkONMMMMMMMMX; cXXkxXMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMM0;.''':0MMMMMMMMWl .''..xMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMNXXXXNMMMMMMMMMMNOkOOOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
      cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    }
    void Monster::monsterDieText(){
      cout << "The " << getName() << " died!" << endl;
      cout << "You were victorious!" << endl;
    }

    //Needs Attack
    //Needs way to die
