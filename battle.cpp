//Authors: Ethan Smith, Aramis Hahne, Kaylee Hall
//Class:CS-3150-Dr.Cantrell
//Version: 10/25/20

#include <iostream>
//#include <stdlib.h>
using namespace std;

Battle::Battle(Character* ca, Monster mo) {

	cha = ca;
	m = mo;
}

int Battle::getAttackInput() {
	int attack_option;

  displayStats();
	//cout << " Choose an option: (1, 2): 1. Fight, 2. Run away" << endl;
	cout << "1: Attack with your strength" << endl;
	int i = 0;
	for (i=0;i<cha->getInventory().size();i++){
		if (cha->getInventory()[i].getType() == 1){
			cout << i+2 << ": Attack with your +"<<cha->getInventory()[i].getStrength()<<" " << cha->getInventory()[i].getName() << endl;//"(durability remaining:" << cha->getInventory()[i].getUses() << ")" << endl;
		}
		else {
			cout << i+2 << ": Heal yourself with your +"<<cha->getInventory()[i].getStrength()<<" " << cha->getInventory()[i].getName() << endl;//"(durability remaining:" << cha->getInventory()[i].getUses() << ")" << endl;
		}
	}
	cout << i+2 << ": Run away, like a coward!" << endl;

	cin >> attack_option;
	return attack_option;
}
void Battle::healthbar(int max, int current){ // draws a healthbar based on numbahs
	double ratio = double(current) / double(max);
	int curr = 20 * ratio;
	cout << "\x1B[32m";
	for (int i=0;i<curr;i++){
		cout <<"=";
	}
	cout << "\x1B[91m";
	for (int i=curr;i<20;i++){
		cout <<"=";
	}
	cout << "\x1B[37m";
	cout << endl;
}
void Battle::displayStats() { // this function displays how the battle is going, showing a statblock for you and the enemy
  cout << endl;
  cout << endl;
  cout << "Your HP:" << cha->getHp() << "/" << cha->getMaxHp();
	healthbar(cha->getMaxHp(),cha->getHp());
  cout << "Your strength:" << cha->getStrength() << endl;
	//cout << "your other stuff" << cha->getXp() <<", " << cha->getGold() << endl;
  cout << "---"<< endl;
  cout << m.getName() <<  " HP:" << m.getHp() << "/" << m.getMaxHp();
	healthbar(m.getMaxHp(),m.getHp());
  cout << m.getName() << " Strength:" << m.getStrength() << endl;
}
int Battle::fight(){
  //system("CLS");
  int monsterDmg;
  int characterDmg;
	int attack_option;
  cout << "You have encountered a "<< m.getName() << endl;
  m.printImage();
	//while character is alive and monster alive , not run away
  while(cha->isAlive() && m.isAlive()) {
		//user chooses whether to attack (1) or run away (2)
		attack_option = getAttackInput();
		//cout << "The attack option you chose: " << attack_option << endl;
		//if player chooses to run away
		int possiblerange = cha->getInventory().size();
		if (attack_option == 1){
			// attack with your hands
			characterDmg = cha->attack();
			cout << "You dealt \x1B[32m" << characterDmg<< "\x1B[37m damage." << endl;
			m.takeDmg(characterDmg);
		}
		else if (attack_option == possiblerange+2){
			// run away
			cout << "You run away like a coward. As you run, the " << m.getName() << " strikes you in the back "<< endl;
			return 2;

			//TODO: actually get away here
		}
		else {
			attack_option -=2;
			if (cha->getInventory()[attack_option].getType() == 1){
				// if item is a weapon attack with it
				//use an item here
				cout << "You attack with your " << cha->getInventory()[attack_option].getName() << endl;
				cha->getInventory()[attack_option].setUses(cha->getInventory()[attack_option].getUses()-1);// decreases item durability by 1

				//cout << cha->getInventory()[attack_option].getStrength();
				characterDmg = cha->attack() + cha->getInventory()[attack_option].getStrength();
				m.takeDmg(characterDmg);
				cout << "You dealt \x1B[32m" << characterDmg<< "\x1B[37m damage." << endl;
			}
			else {
				// if item is not a weapon, then use it
				cout << "You consume your " << cha->getInventory()[attack_option].getName() << endl;
				cha->getInventory()[attack_option].setUses(cha->getInventory()[attack_option].getUses()-1);

				int heal = cha->getInventory()[attack_option].getStrength() + (rand() % 5);
				cout << "It heals you for \x1B[32m" << heal << "HP\x1B[37m!" << endl;
				cha->setHp(cha->getHp()+heal);
			}

		}
		monsterDmg = m.attack();
		//subtract that damage from the character health
		cha->takeDmg(monsterDmg);
		cout << "The "<< m.getName() <<" dealt \x1B[91m" << monsterDmg << "\x1B[37m damage." << endl;

		// if(attack_option == 2) {
		// 	//something else here...not feeling snarky today // good
		// 	// there's a bug here,( well not here, in map) where if you run away, the monster disappears :(
		// 	//monster deals last attack
		// 	monsterDmg = m.attack();
		// 	cha->takeDmg(monsterDmg);
		// 	cout << "The monster dealt \x1B[91m" << monsterDmg << "\x1B[37m damage." << endl;
		// 	//returns 1 if the character is still alive
		// 	if(cha->isAlive()) {
		// 			return 1;
		// 		}
		// 		return 0;
		// 	}
		// //get damage that the character will deal
		// characterDmg = cha->attack();
		// //subtract that damage from the monster health
		// m.takeDmg(characterDmg);
		// cout << "You dealt \x1B[32m" << characterDmg<< "\x1B[37m damage." << endl;
		// //get damage that the monster will deal
		// monsterDmg = m.attack();
		// //subtract that damage from the character health
		// cha->takeDmg(monsterDmg);
		// cout << "The "<< m.getName() <<" dealt \x1B[91m" << monsterDmg << "\x1B[37m damage." << endl;
	}
	//breaks out of loop if monster or character is dead
	//returns 0 if character is dead, else it returns 1
	//cout << "player Hp is " << cha->getHp() << endl;
	if(cha->isAlive() == false) {
		cha->characterDieText();
		return 0;
	}
	else {
		m.monsterDieText();
		return 1;
	}
}
