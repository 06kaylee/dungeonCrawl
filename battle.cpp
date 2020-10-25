#include <iostream>
//#include <stdlib.h>
using namespace std;

Battle::Battle(Character ca, Monster mo) {
	c = ca;
	m = mo;
}

int Battle::getAttackInput() {
	int attack_option;

  displayStats();
	cout << " Choose an option (1, 2): 1. Fight, 2. Run away" << endl;
	cin >> attack_option;
	return attack_option;
}
void Battle::displayStats() { // this function displays how the battle is going, showing a statblock for you and the enemy
  cout << endl;
  cout << endl;
  cout << "Your HP:" << c.getHp() << "/" << c.getMaxHp() << endl;
  cout << "Your strength:" << c.getStrength() << endl;
  cout << "---"<< endl;
  cout << m.getName() <<  " HP:" << m.getHp() << "/" << m.getMaxHp() << endl;
  cout << m.getName() << " Strength:" << m.getStrength() << endl;
}
int Battle::fight(){
  system("CLS");
  int monsterDmg;
  int characterDmg;
	int attack_option;
  cout << "You have encountered a "<< m.getName() << endl;
  	m.printImage();
	//while character is alive and monster alive , not run away
  while(c.isAlive() && m.isAlive()) {
		//user chooses whether to attack (1) or run away (2)
		attack_option = getAttackInput();
		cout << "The attack option you chose: " << attack_option << endl;
		//if player chooses to run away
		if(attack_option == 2) {
			//something else here...not feeling snarky today // good
			cout << "You run away like a coward. As you run, the " << m.getName() << " strikes you in the back "<< endl;// there's a bug here,( well not here, in map) where if you run away, the monster disappears :(
			//monster deals last attack
			monsterDmg = m.attack();
			c.takeDmg(monsterDmg);
			cout << "The monster dealt \x1B[91m" << monsterDmg << "\x1B[37m damage." << endl;
			//returns 1 if the character is still alive
			if(c.isAlive()) {
					return 1;
				}
				return 0;
			}
		//get damage that the character will deal
		characterDmg = c.attack();
		//subtract that damage from the monster health
		m.takeDmg(characterDmg);
		cout << "You dealt \x1B[32m" << characterDmg<< "\x1B[37m damage." << endl;
		//get damage that the monster will deal
		monsterDmg = m.attack();
		//subtract that damage from the character health
		c.takeDmg(monsterDmg);
		cout << "The "<< m.getName() <<" dealt \x1B[91m" << monsterDmg << "\x1B[37m damage." << endl;
	}
	//breaks out of loop if monster or character is dead
	//returns 0 if character is dead, else it returns 1
	if(c.isAlive() == false) {
		c.characterDieText();
		return 0;
	}
	else {
		m.monsterDieText();
		return 1;
	}
}
