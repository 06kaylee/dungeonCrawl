// yeah so this is a header LOL 
#include <iostream>
#include <vector>

using namespace std;


#ifndef Item_H
#define Item_H
class Item 
{
    protected:
        string name;
        int strengthmod;
    public:
        Item(string n, int s);
        string getName();
        void setName(string n);
        int getStrength();
        void setStrength(int s);
};
#endif


#ifndef Monster_H
#define Monster_H
class Monster 
{
    protected:
        string names [3] = {"goblin","Orc","Troll"};
        string name;
        int hp;
        int maxhp;
        int strength;
    public:
        Monster(int diff);
        Monster(string n,int h,int s);
        string getName();
        void setName(string s);
        int getHp();
        void setHp(int h);
        int getMaxHp();
        void setMaxHp(int m);
        int getStrength();
        void setStrength(int s);
};
#endif


#ifndef Character_H
#define Character_H
class Character 
{
    protected:
        string name;
        int hp;
        int maxhp;
        int strength;
        int mana;
        int maxmana;
        vector<Item> inventory;
    public:
        Character();
        string getName();
        void setName(string s);
        int getHp();
        void setHp(int h);
        int getMaxHp();
        void setMaxHp(int m);
        int getStrength();
        void setStrength(int s);
        int getMana();
        void setMana(int m);
        int getMaxMana();
        void setMaxMana(int m);
    
};
#endif