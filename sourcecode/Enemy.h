// Enemy Derived Class Header File

#include "Character.h"
#include "Player.h"
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Character {
	
	public:
		Enemy(int=100, int=100);	                     // constructor
		void move(Character&, Character&, Character&);      // moves the enemy while checking for collisions

	private:
		int random;
		int ranCounter;
};

#endif
