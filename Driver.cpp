//Authors: Ethan Smith, Aramis Hahne, Kaylee Hall
//Version: 10/25/20

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
Character * playerpointer;

//aaaaah
void onexit(Character p){
  // do some shit if you make it to the exit :^)
  int choice;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXNN0KNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXOOOkxdo:',,..;oddxOKXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOdl:'...  'l:. ..;' .,. .,;:oxOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkl;.'.  'o;.. ,ONx.  ,ol:loc',c;.  .;oONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMWKd:. .,'cOo. ,d;.'..dK0:...:l'.colccllc'   'cxXWMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMXx:.,c;. :x;:0o  ...,l,.'kXXx.     .,:clcldxococ.'cONMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMWKo'..'kWNkc.;d;;ko.    ,dx;.:ox:    .,  .lkxlxNMMMXd;.,dXMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMKl.'lOl .,,:l; .c;,xl. .   ,oc. .'.    .... .dNMMMMMMMNOc.'oXMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMNx' cXMWk.  .:,.   ;l:' .';'  .do'''..',oo;;cc:;:OWMMMMMMMWK:.,kNMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMW0;.,';0XXNd...;00c..,cll;  .'.  ;OK00d,,,lNXooKMXo:0MMMMMMMXo,c,.cKMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMWx..dNK:.:oc:'.'.,ONO;cKNWNd. 'lc,;clOWWx,cOWMMMMMMWXNMMMMMMNl.lNXo.'OWMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMNo.,OWMMXc;OKx, ...oWMKOXMMMW0d0WWWWWNWMMWKKWMMMMMMMMMMMMMMWO:.lNMMWk'.xWMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMNl.;KMMMMMXl;OWXl.cx0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKl.:ONMMMMM0'.dWMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMNl.;KMMMMMMMNo:0MWdlXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO''xNMMMMMMMMO'.xWMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMWx..dNWMMMMMMMWXNMMWNWMMMMMW0kO0KWMMMMMMMMMMMMMMMMWKOkxk0NWk.,0MMMMMMMMMMWx.'0MMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMM0'.,::cldx0XWMMMMMMMMMMMMMKc.  ..'cONMMMMMMMMMMMM0:.    .,:.;KMMMMMMMMMMMMNl :XMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMWo :XWKkdlc:::coxOXNMMMMMMNl        .kMMWWNX0OOOOd'         ;XMMMMMMMMMMMMMM0'.xMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMK,.xMMMMMMWWX0kdc:c::ldxkOd.         ;l:;;:::::::,.        .xMMMMMMMMMMMMMMMWo :NMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMk.,KMMMMMMMMMMMMMWN0kdllc:.       .cxxxxkO0XNWMMMNx.      .oXMMMMMMMMMMMMMMMMO.'0MMMMMMMMMM" << endl;
  cout << "MMMMMMMMWo lWMMMMMMMMMMMMMMMMMMMMMNo.     .xNMMMMMMWX00O0NMW0olllloOWMMMMMMMMMMMMMMMMMX;.xMMMMMMMMMM" << endl;
  cout << "MMMMMMMMN: dMMMMMMMMMMMMMMMMMMMMMMMWKOxddxKWMMMMMMMK:.. .lXMMMMMMMMMMMMMMMMMMMMMMMMMMMWc oMMMMMMMMMM" << endl;
  cout << "MMMMMMMMN: oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,    ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMNc oMMMMMMMMMM" << endl;
  cout << "MMMMMMMMWc oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0'    ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMN: oMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMd.:NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd:,.     cNMMMMMMMMMMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMO.'OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMk'.......,kMMMMMMMMMMMMMMMMMMMMMMMMMMMMk.,KMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMN: oWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX00000KNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMNc lWMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMx.,0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMk.'0MMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMNc.cNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNX0KNWMMMMMMMMMMMMMMMX;.oWMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMK,.dWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0kkxoooooc,'....,lx0XWMMMMMMMMXx, :NMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMO..xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0d:.                  ..,::loool:.  ;KMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMWO'.dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo.                                  ;KMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMWO,.lXMMMMMMMMMMMMMMMMMMMMMMMMWXxc.                                   :KMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMXc.'ccloddxkOOKXNWMMMMMMWXko;.                                    .lXMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMWk'          ...,;;;;;;,.                                       ,OWMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMXl.                                                         .dXMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMW0c.                                                     .oXMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMWKd'                                                 ;dXMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMNkc'                                           'lONMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMWXkl,.                                   .;oONMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxl;'.                         .,:okXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0kdlc;,'...........',:coxkKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNK0000000KXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << endl;
  cout << "An old man is guarding an exit to the dungeon. As you approach, he says 'For 100 gold, I'll let you out!' " << endl;
  cout << "1: Pay him the 100 gold" << endl;
  cout << "2: Leave" << endl;
  cin >> choice;
  if (choice == 1 && p.getGold() >= 100) {
    cout << "_|      _|  _|_|_|    _|_|_|  _|_|_|_|_|    _|_|    _|_|_|    _|      _|  _|  " << endl;
    cout << "_|      _|    _|    _|            _|      _|    _|  _|    _|    _|  _|    _|  " << endl;
    cout << "_|      _|    _|    _|            _|      _|    _|  _|_|_|        _|      _|  " << endl;
    cout << "  _|  _|      _|    _|            _|      _|    _|  _|    _|      _|          " << endl;
    cout << "    _|      _|_|_|    _|_|_|      _|        _|_|    _|    _|      _|      _|  " << endl;
    cout << endl;
    cout << "Enter anything to revel in your glory " << endl;
    string winner;
    cin >> winner;
    exit(1);
  }
  else if (choice == 2){
    cout << "you leave" << endl;
  }
  else if (choice ==1 &&p.getGold() <100){
    cout << "The old man shakes his head, and says 'You can't afford the toll yet, go explore more, broke ass'" << endl;
  }
  else {
    cout << "INVALID INPUT, GET THE FRICK OUTTA HERE" << endl;
  }
}
void help(){
  //system("CLS");
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
  // RIGHT HERE JASHDKHASJKDHKJAHSDKJHAKJSHDKJAHSKDHK
  cout << "#     #" << endl;
  cout << "#  #  # ###### #       ####   ####  #    # ######    #####  ####     ##### #    # ###### " << endl;
  cout << "#  #  # #      #      #    # #    # ##  ## #           #   #    #      #   #    # #      " << endl;
  cout << "#  #  # #####  #      #      #    # # ## # #####       #   #    #      #   ###### #####  " << endl;
  cout << "#  #  # #      #      #      #    # #    # #           #   #    #      #   #    # #      " << endl;
  cout << "#  #  # #      #      #    # #    # #    # #           #   #    #      #   #    # #      " << endl;
  cout << " ## ##  ###### ######  ####   ####  #    # ######      #    ####       #   #    # ###### " << endl;
  cout << "                                                                                         " << endl;
  cout << " #####                                       ######                                            " << endl;
  cout << "#     # #####   ####   ####  #    # #   #    #     # #    # #    #  ####  ######  ####  #    # " << endl;
  cout << "#       #    # #    # #    # #   #   # #     #     # #    # ##   # #    # #      #    # ##   # " << endl;
  cout << " #####  #    # #    # #    # ####     #      #     # #    # # #  # #      #####  #    # # #  # " << endl;
  cout << "      # #####  #    # #    # #  #     #      #     # #    # #  # # #  ### #      #    # #  # # " << endl;
  cout << "#     # #      #    # #    # #   #    #      #     # #    # #   ## #    # #      #    # #   ## " << endl;
  cout << " #####  #       ####   ####  #    #   #      ######   ####  #    #  ####  ######  ####  #    # " << endl;
  cout << "                                                                                               " << endl;
  cout << " #####                                            " << endl;
  cout << "#     # #####    ##   #    # #      ###### #####  " << endl;
  cout << "#       #    #  #  #  #    # #      #      #    # " << endl;
  cout << "#       #    # #    # #    # #      #####  #    # " << endl;
  cout << "#       #####  ###### # ## # #      #      #####  " << endl;
  cout << "#     # #   #  #    # ##  ## #      #      #   #  " << endl;
  cout << " #####  #    # #    # #    # ###### ###### #    # " << endl;
  cout << endl;
  cout << endl;

  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNkok0KWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,  ..,cdOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,        .;lx0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;............,xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:oXXXXXXXXXXXXNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:xMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:xMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWWWW0:dWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,,,,,,,,...,,,,,,,,,,,,lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMNK00NWX000NMN000KNMMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMWKOkOXN0kkOXWKkkOKWMMM" << endl;
  cout << "MMMXc...oO,. .oXl.  .kMMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMM0,   dx.   o0;   ,OMMM" << endl;
  cout << "MMMK,   .'    .'.    dWMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMO'   ..    ..    .kMMM" << endl;
  cout << "MMMK,                dWMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMO.               .kMMM" << endl;
  cout << "MMMK,               .xMMMMMMMMMMMMMMN:                       ,KMMMMMMMMMMMMMMMO'               .kMMM" << endl;
  cout << "MMMK,                ;ddddddddddddddo'                       .ldddddddddddddddc.               .kMMM" << endl;
  cout << "MMMK,                                                                                          .kMMM" << endl;
  cout << "MMMK,                                                                                          .kMMM" << endl;
  cout << "MMMK,                                                                                          .kMMM" << endl;
  cout << "MMMK,                                                                                          .kMMM" << endl;
  cout << "MMMK,                                                                                          .kMMM" << endl;
  cout << "MMMK,                                       .,:::;,'..                                         .kMMM" << endl;
  cout << "MMMK,                                      ,0WMMMMWWXKOo.                                      .kMMM" << endl;
  cout << "MMMK,                                     ,KMMMMMMMMMMMMx.                                     .kMMM" << endl;
  cout << "MMMK,                                    .kMMMMMMMMMMMMMWo                                     .kMMM" << endl;
  cout << "MMMK,                                    cNMMMMMMMMMMMMMMK,                                    .kMMM" << endl;
  cout << "MMMK,                                   .OMMMMMMMMMMMMMMMWo                                    .kMMM" << endl;
  cout << "MMMK,                                   lWMMMMMMMMMMMMMMMMx.                                   .kMMM" << endl;
  cout << "MMMK,                                  .xWWWWWWWWWWWWWWWWWo                                    .kMMM" << endl;
  cout << "MMMX;                                   .,,,,,,,,,,,,,,,,,.                                    .OMMM" << endl;
  cout << "MMMNc                                                                                          ,KMMM" << endl;
  cout << "MMMWkccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccxNMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
  cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;


string choice;
//seed the random number generator
srand(time(NULL));
int difficulty;
string cname;
cout << "Enter an int for difficulty level from 1-10. Affects map size and difficulty of monsters. Don't be a coward, put 10" << endl;
cin >> difficulty;
if (difficulty > 10) {
  cout << "Congrats on unlocking the secret difficulty level: 11 ( note, approximately 10% harder than 10 )" <<endl;
  difficulty = 11;
}
cout << "Enter a name for your character. It may never show up again after this textbox, so just punch the keyboard or something " << endl;
cin >> cname;
player = Character(cname);
playerpointer = &player;
Character& playy = player;
Map level = Map(difficulty*9);
help();

// get the users windows account name, and set the character name to that
// generate a Character
// should there be prebuilt characters?

//vector<vector<int>> map = makemap(difficulty,difficulty); // <-- difficulty increases map size ?
// make a dungeon object

// loooooooop
int event = 0;

while (player.getHp() > 0) {
    //cin >> cname;
    system("CLS");
    level.printMap();
    cout << "Select a direction to move! (W A S D ): ";
    cin >> choice;
    if (choice == "w" or choice == "W"){    // movement directions
        event = level.move(-1,0);
    }
    else if (choice == "a" or choice == "A") {
        event = level.move(0,-1);
    }
    else if (choice == "s" or choice == "S") {
        event = level.move(1,0);
    }
    else if (choice == "d" or choice == "D") {
        event = level.move(0,1);
    }
    else if (choice == "exit" or choice == "exit()" or choice == "quit"){// quit the game
      cout << "seeya loser!" << endl;
      exit(1);
    }
    else if (choice == "stats" or choice == "inventory" ){
      //TODO: this LOL
      cout << player.getHp() << "/" << player.getMaxHp() << endl;
      cout << "You have " << player.getGold() << " Gold, and " << player.getXp() << "/" << player.getLevel()*100 << " Xp for next level" << endl;
      cout << "Your inventory: " << endl;
      for (int i=0; i<player.getInventory().size();i++){
        cout << "+" << player.getInventory()[i].getStrength() << " " << player.getInventory()[i].getName() << endl;
      }
      cout << "Enter anything to continue: ";
      cin >> cname;
    }
    else if (choice == "help") {// display the help menu
      help();
    }
    else {
        cout << "Invalid choice. Please choose from W A S D" << endl;
    }
    cout << event << " is your event" <<endl;
//    cout << event;
//    cin >> cname;
    // run a function to generate options < -- this is better than a static setup because you can use it for battle, or for map traversal
    if (event == 1) {// fight
      // generate a monster... it scales based on difficulty, AND player level kekw
      //TODO:: at a higher level, summon cooler monsters ( based on name and art ? )
      Monster m = Monster(difficulty+ (player.getLevel()* 2));
      //cout << "you fight a " << m.getName() << endl;
      //cout << "enter anything to confirm that you read this message:";
      //player.setHp(player.getHp()-3);
      Battle b = Battle(&player,m); // what THE FUCK !!?


      int a = b.fight();
      if (a == 0){
        exit(1); //ya died kid!
      }
      else if (a == 1) {
        int gp = 1 + rand() % m.getMaxHp()/2;
        int xp = 2 + rand() % m.getMaxHp() + (m.getStrength() * 3);
        player.setGold(player.getGold() + gp);
        player.setXp(player.getXp() + xp);
        cout << "You found \x1B[33m"<< gp <<" gold\x1B[37m!, and gained \x1B[32m"<< xp<< " XP\x1B[37m!" << endl;
        cout << "You have \x1B[33m" << player.getGold() << " gold\x1B[37m, and ";
        cout << "\x1B[32m" << player.getXp() << "/" << player.getLevel() * 100 << "\x1B[37m XP for the next level" << endl;
        cout << "Enter anything to leave the battle: ";
      }
      else {
        cout << "You, being the coward that you are, manage to get away just barely" << endl;
        cout << "Enter something to confirm that you are a coward, and get back to the map" << endl;
      }
      // once battle
      //cin >> cname;
      event = 0;
      // maybe this should all go in the battle handler? but here it's not getting calculated after our brave hero is dead... so whatever.

      cin >> cname ; // lets you see the output before screen clears
    }
    if (event == 2) {
      // handle treasure here :^)
      int whathappens = 1 + rand() % 100;
      if (whathappens > 60) {
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNX0OkOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOdlcc;,'..   .;oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKx:.                .lKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl.                     ;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0;     ..                .dWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMWMMMMMMMMMMMMMMMMMMMMMMMMK,    :OXXOc.. .:dkko,     lWMMMMMMMMMMMMMMMMN0XMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMOcxNMMMMMMMMMMMMMMMMMMMMMNo    '0MMMMKx, cNMMMMK,    lNMMMMMMMMMMMMMMNO;.,OWMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMO..:0WMMMMMMMMMMMMMMMMMMM0'    .c0XN0l'. 'xKNX0o.    lWMMMMMMMMMMMMMKc.   .kWMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMNl  .kWMMMMMMMMMMMMMMMMMWo       ....      ....      :XMMMMMMMMMMMWk'      lNMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMM0'  .xWMMMMMMMMMMMMMMMMK;            ......         .xWMMMMMMMMMXo.       cNMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMNc   .dXWMMMMMMMMMMMMMM0'        .lk00KXXK0Od,       ,KMMMMMMWNk,         lWMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMO.    'cdOXWMMMMMMMMMM0'        ;0WMMMMMMMWNo.       ;x0KOxl;'          .xMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMNl        .;clllloodk0d.         .,:cllllc;'           ..               :XMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMM0'                                                                   .oXMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMWd.                                                              .'cdKWMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMX:                                                          .;okKNMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMXl.                                                    .:dOXWMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMWk,                                                .:kXWMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMXd:'........                                    .xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMNXXXXXXXKkc.                                 cNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXk:                               lNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo.                             .oXMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd.                              ;0MMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.                              lWMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.                              oWMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWo                              cXMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNc                            .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNc                         .,oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNl                  ..,:cld0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,               ,kXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXx:.            lWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'           oWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMk.        .cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO.       .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0;      .c0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxo;'..,:ox0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWK0KXXNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << endl;
        cout << "You have come across a ghost!" << endl;
        cout << "Answer his question in order to get a reward!" << endl;
        int ghostChoice = rand() % 5;
        if (ghostChoice == 4) {
          cout << "True or False?" << endl;
          cout << "It's permissible to put pineapple on pizza." << endl;
          cout << "1: True" << endl;
          cout << "2: False" << endl;
          int tf;
          cin >> tf;
          if (tf == 1){
            cout << "WRONG!" << endl;
            cout << "You get nothing!" << endl;
          } else {
            cout << "CORRECT" << endl;
            int randomGold = 3 + (rand() % 15);
            player.setGold(player.getGold() + randomGold);
            cout << "You received " << randomGold << " gold!" << endl;
          }
        }
        else if (ghostChoice == 3) {
          cout << "True or False?" << endl;
          cout << "Signed ints can be positive or negative in C++." << endl;
          cout << "1: True" << endl;
          cout << "2: False" << endl;
          int tf;
          cin >> tf;
          if (tf == 1){
            cout << "CORRECT!" << endl;
            int randomGold = 5 + (rand() % 15);
            player.setGold(player.getGold() + randomGold);
            cout << "You received " << randomGold << " gold!" << endl;
          } else {
            cout << "WRONG!" << endl;
            cout << "You get nothing!" << endl;
          }
        }
        else if (ghostChoice == 2) {
          cout << "True or False?" << endl;
          cout << "It's okay to not put your name on your assignments before you turn them in." << endl;
          cout << "1: True" << endl;
          cout << "2: False" << endl;
          int tf;
          cin >> tf;
          if (tf == 1){
            cout << "WRONG!" << endl;
            cout << "You get nothing!" << endl;
          } else {
            cout << "CORRECT!" << endl;
            int randomGold = 5 + (rand() % 15);
            player.setGold(player.getGold() + randomGold);
            cout << "You received " << randomGold << " gold!" << endl;
          }
        }
        else if (ghostChoice == 1) {
          cout << "True or False?" << endl;
          cout << "Provo is the capital of Utah." << endl;
          cout << "1: True" << endl;
          cout << "2: False" << endl;
          int tf;
          cin >> tf;
          if (tf == 1){
            cout << "WRONG!" << endl;
            cout << "You get nothing!" << endl;
          } else {
            cout << "CORRECT!" << endl;
            int randomGold = 5 + (rand() % 15);
            player.setGold(player.getGold() + randomGold);
            cout << "You received " << randomGold << " gold!" << endl;
          }
        }
        else {
          cout << "True or False?" << endl;
          cout << "SUU was founded in 1897." << endl;
          cout << "1: True" << endl;
          cout << "2: False" << endl;
          int tf;
          cin >> tf;
          if (tf == 1){
            cout << "CORRECT!" << endl;
            int randomGold = 5 + (rand() % 15);
            player.setGold(player.getGold() + randomGold);
            cout << "You received " << randomGold << " gold!" << endl;
          } else {
            cout << "WRONG!" << endl;
            cout << "You get nothing!" << endl;
          }
        }

      }
      else if (whathappens > 40){
        //create item
        Item newItem = Item();
        cout << "You found: " << newItem.getName() << endl;
        //get inventory
        vector<Item> inventory = player.getInventory();
        inventory.push_back(newItem);
        player.setInventory(inventory);
      }
      else if (whathappens > 20) {
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNNNNWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd;'...',,,,,,;:coxOKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0o'                   .':ldx0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNk:.                            .;ldOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx,                                    .;lxOXWMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMX:                                           .,cokXWMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMx.                                                .,lxKNMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMd                                                     .dWMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMWKd;;:,.                                                 .OMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMNklcdOxdxxxdl;..                                         .;OWMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMW0oclxOo,   .':lxkkxo:'.                                   'kWMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMXxccdOx:.          ..;ldkkkdc;..                            ,0MMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMW0oclxkl'                   .,cdkOOkxl:'.                      dMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMXxllx0x;.                          .,;:oxOOkdc,.                 :NMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl.,x00kdl;'.             $$$$            .':lxO0Oxl:'.           cNMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl   ..,:oxkkkxl:,.          $$$$               .;ldO00koc,.     .kMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl          .':ldxxkxoc,..                           .,cOWW0:   'OWMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                ..;coxxxxdc;'.                      .lKXx'    :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                      ..,:ldxxxdl:'.              .lKXx'      :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                             .';ldxxxxdo:,.     .l0Ko.        :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                    ....           ...,codxddocoKKo.          :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                   :0NX0d'                 .':kXo.            :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                   oWMMMK;                    ck.             :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                   '0MWO'                     ck.             :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWl                  'kWMMNc                     ck.             :NMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMN:                  ckkkO0l                     ck.           .lKWMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMNxc;'.                                          ck.         .lKWMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMNX0kdl:,..                                  ck.       .cKWMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMWX0kdlc;'.                           ck.     .:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOxoc;'.                    ck.   .:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kdl:,..            ck. .:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kxolc;'.    ck,:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOxockXKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
        cout << endl;
        int randomGold = 10 + (rand() % 20);
        cout << "You've found " << randomGold << " gold!" << endl;
        player.setGold(player.getGold() + randomGold);
      }
      else if (whathappens > 10) {
        cout << "The room is empty..." << endl;
      }
      else {
        cout << "The walls are closing in..." << endl;
        int randomHealth = 1 + (rand() % 5);
        player.setHp(player.getHp() - randomHealth);
      }
      cout << "Enter anything to leave the room: " << endl;
      cin >> cname;
      event = 0;
    }
    if (event == 3){
      onexit(player);
      event = 0;
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
