#include <iostream>
#include <vector>

using namespace std;

class Character {
protected:
    string name;
    int hp;
    int maxhp;
    int strength;
    int mana;
    int maxmana;
    vector<Item> inventory;
    public:
        // contructor
        Character() {
            name = "husk";
            maxhp = 5;
            hp = maxhp;
            strength = 1;
            maxmana = 2;
            mana = maxmana;
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
        int getMana(){
            return mana;
        }
        void setMana(int m){
            mana = m;
        }
        int getMaxMana(){
            return maxmana;
        }
        void setMaxMana(int m){
            maxmana = m;
        }
};
int main(){
    Character a;
    cout << a.getMana() << endl;
    cout << a.getName() << endl;
}
