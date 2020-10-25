#include <iostream>
#include <vector>
#include <time.h>
#include "obj.h"

#include "Monster.cpp"
#include "Character.cpp"
#include "Map.cpp"
#include "Item.cpp"
#include "battle.cpp"

#include <stdlib.h>

//#include "Item.cpp"
//#include "Character.cpp"
//#include "Monster.cpp"
//#include "map.cpp"

using namespace std;
// this is the file that will "run" the game, basically setting variables, and then running the game loop

Character player;

//aaaaah

int main(){
string choice;
//seed the random number generator
srand(time(NULL));
int difficulty;
string cname;
cout << "enter an int for difficulty... 1-10 suggested but put whatever you want, go wild" << endl;
cin >> difficulty;
cout << "enter a name for your character. or enter 1 and I give your character a dumb sounding name " << endl;
cin >> cname;
player = Character(cname);
Map level = Map(difficulty*10);
// get the users windows account name, and set the character name to that
// generate a Character
// should there be prebuilt characters?

//vector<vector<int>> map = makemap(difficulty,difficulty); // <-- difficulty increases map size ?
// make a dungeon object

// loooooooop
int inbattle = 0;
while (player.getHp() > 0) {
    //cin >> cname;
    system("CLS");
    level.printMap();
    cout << "select an option from the list" << endl;
    cin >> choice;
    if (choice == "w"){
        inbattle = level.move(-1,0);
    }
    else if (choice == "a") {
        inbattle = level.move(0,-1);
    }
    else if (choice == "s") {
        inbattle = level.move(1,0);
    }
    else if (choice == "d") {
        inbattle = level.move(0,1);
    }
    else {
        cout << "invalid choice, please choose from W A S D" << endl;
    }
//    cout << inbattle;
//    cin >> cname;
    // run a function to generate options < -- this is better than a static setup because you can use it for battle, or for map traversal
    if (inbattle) {
      // generate a monster
      Monster m = Monster(difficulty);
      //cout << "you fight a " << m.getName() << endl;
      //cout << "enter anything to confirm that you read this message:";
      Battle b = Battle(player,m);

      int a = b.fight();
      if (!a){
        exit(1);
      }
      // once battle
      //cin >> cname;
      inbattle = 0;
      cout << "You found some gold!" << endl;
      cout << "Enter anything to leave the battle!";
      cin >> cname ; // lets you see the output before screen clears
    }
}

// read user input

// resolve user input ( battle handler? )

return 1;
}
// is the enemy generated in here? or before?
void battle(Character p, int difficulty){
    // make a monster object
    Monster m(difficulty);
    while (p.getHp() > 0 and m.getHp() > 0) {
        // get player action

        // generate a random monster action
    }
    // start looping to get user input to see what they did
}
