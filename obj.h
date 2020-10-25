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
        bool alive;
        int strength;
    public:
        Monster();
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
        bool isAlive();
        void setAlive(bool b);
        int attack();
        void takeDmg(int dmg); // added these to the header for you so that the program will compile
        void monsterDieText();
        void printImage();
};
#endif

// that's a big class lol
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
        bool alive;
        vector<Item> inventory;
        int level;
        int xp;
        int gold;
    public:
        Character();
        Character(string n);
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
        bool isAlive();
        void setAlive(bool b);
        void takeDmg(int dmg);
        int attack();
        void characterDieText();
        int getXp();
        void setXp(int x);
        int getLevel();
        void setLevel(int l);
        void levelup();
        void setGold(int g);
        int getGold();
};
#endif

#ifndef Map_H
#define Map_H
class Map{
    protected:
        vector<vector<int>> area;
        int playerx;
        int playery;
        int difficult;
    public:
        Map(int x);
        Map();
        void printMap();
        void fillMap();
        int move(int x, int y);
        vector<vector<int>> makeMap(int x,int y);
        vector<vector<int>> generateRooms(vector<vector<int>> vec);
        vector<vector<int>> generateHalls(vector<vector<int>> vec,int x, int y);
        vector<vector<int>> getMap();
        void repopulate(int n);
};

#endif
#ifndef Battle_H
#define Battle_H
class Battle{
    protected:
        Character c;
        Monster m;
    public:
        Battle(Character ca, Monster mo);
        int fight();
        int getAttackInput();
        void displayStats();
};
#endif
