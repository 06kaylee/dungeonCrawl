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
void help(){
  system("CLS");
  string randy; // this is just used to store the user input that keeps this window visible
  cout << "GUIDE:"<<endl;
  cout << "O  <-- this is your character, move this around" << endl;
  cout << "M  <-- This is a monster. avoid these, or fight them for money and experience" << endl;
  cout << "E  <-- This is The exit. get here to win, but be warned, you'll have to pay money or do a task to use it!" << endl;
  cout << "T  <-- This is Treasure of some kind... assuming it isn't also a TRAP! " << endl;
  cout << char(178) ;
  cout << "  <-- This is a wall... you can't walk through these :^)" << endl;
  cout << "Type 'help' at anytime to see this again! now input anything to continue the game" << endl;
  cin >> randy;
}
int main(){
string choice;
//seed the random number generator
srand(time(NULL));
int difficulty;
string cname;
cout << "enter an int for difficulty level from 1-10. affects map size, and difficulty of monsters. don't be a coward, put 10" << endl;
cin >> difficulty;
if (difficulty > 10) {
  cout << "Congrats on unlocking the secret difficulty level: 11 ( note, approximately 10% harder than 10 )" <<endl;
  difficulty = 11;
}
cout << "enter a name for your character. It may never show up again after this textbox, so just punch the keyboard or something " << endl;
cin >> cname;
player = Character(cname);
Map level = Map(difficulty*9);
help();

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
    cout << "select a direction to move! (W A S D ):";
    cin >> choice;
    if (choice == "w" or choice == "W"){    // movement directions
        inbattle = level.move(-1,0);
    }
    else if (choice == "a" or choice == "A") {
        inbattle = level.move(0,-1);
    }
    else if (choice == "s" or choice == "S") {
        inbattle = level.move(1,0);
    }
    else if (choice == "d" or choice == "D") {
        inbattle = level.move(0,1);
    }
    else if (choice == "exit" or choice == "exit()" or choice == "quit"){// quit the game
      cout << "seeya looser!" << endl;
      exit(1);
    }
    else if (choice == "stats" or choice == "inventory" ){
      //TODO: this LOL
    }
    else if (choice == "help") {// display the help menu
      help();
    }
    else {
        cout << "invalid choice, please choose from W A S D" << endl;
    }
//    cout << inbattle;
//    cin >> cname;
    // run a function to generate options < -- this is better than a static setup because you can use it for battle, or for map traversal
    if (inbattle) {
      // generate a monster... it scales based on difficulty, AND player level kekw
      //TODO:: at a higher level, summon cooler monsters ( based on name and art ? )
      Monster m = Monster(difficulty+ (player.getLevel()* 2));
      //cout << "you fight a " << m.getName() << endl;
      //cout << "enter anything to confirm that you read this message:";
      Battle b = Battle(player,m);

      int a = b.fight();
      if (!a){
        exit(1); //ya fuckin died kid!
      }
      // once battle
      //cin >> cname;
      inbattle = 0;
      // maybe this should all go in the battle handler? but here it's not getting calculated after our brave hero is dead... so whatever.
      int gp = 1 + rand() % m.getMaxHp()/2;
      int xp = 2 + rand() & m.getMaxHp() + (m.getStrength() * 3);
      player.setGold(player.getGold() + gp);
      player.setXp(player.getXp() + xp);
      cout << "You found \x1B[33m"<< gp <<" gold\x1B[37m!, and gained \x1B[32m"<< xp<< " XP\x1B[37m!" << endl;
      cout << "you have \x1B[33m" << player.getGold() << " gold\x1B[37m, and ";
      cout << "\x1B[32m" << player.getXp() << "/" << player.getLevel() * 100 << "\x1B[37m XP for the next level" << endl;

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
