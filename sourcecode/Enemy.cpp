// Enemy derived class implementation

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Enemy.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Constants
const int CHARACTER_WIDTH  = 100;  // character width
const int CHARACTER_HEIGHT = 89;   // character height
const int BULLET_WIDTH     = 40;   // character width
const int BULLET_HEIGHT    = 28;   // character height
const int ROOM_WIDTH       = 960;  // room width
const int ROOM_HEIGHT      = 768;  // room height


// Functions

Enemy::Enemy(int a, int b) : Character(a, b){        // constructor
	// initialize values
    charVel    = 3;
	random     = 0;
	ranCounter = 100;
	health     = 3;
}

void Enemy::move(Character player, Character e2, Character e3){
	if (ranCounter == 100){
		random = rand() % 4 + 1;
		ranCounter = 0;
	} else{
		ranCounter++;
	}
	if (random == 1){
		yVel -= charVel;
	} else if (random == 2){
		yVel += charVel;
	} else if (random == 3){
		xVel -= charVel;
	} else if (random == 4){
		xVel += charVel;
	}    
	//Move the character left or right
    img_rectangle.x += xVel;

    //If the character went too far to the left
    if(img_rectangle.x < 0){
		img_rectangle.x = 0;
	}
	//If the character went too far to the right
	if(img_rectangle.x + CHARACTER_WIDTH > ROOM_WIDTH){
		img_rectangle.x = ROOM_WIDTH - CHARACTER_WIDTH;
	}
	//If Collision with another Character after changing x position
	if (collision_detect(img_rectangle,player.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        // change x position back
        img_rectangle.x -= xVel;
    }

    //Move the character up or down
    img_rectangle.y += yVel;

    //If the character went too far up
    if(img_rectangle.y < 0){
		img_rectangle.y = 0;
	}
	//If the character went too far updown
	if(img_rectangle.y + CHARACTER_HEIGHT > ROOM_HEIGHT){
		img_rectangle.y = ROOM_HEIGHT - CHARACTER_HEIGHT;
    }

	//If Collision with another Character after changing y position
	if (collision_detect(img_rectangle,player.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        // change x position back
        img_rectangle.y -= yVel;
    }

/*	if (random == 1){
		yVel += charVel;
	} else if (random == 2){
		yVel -= charVel;
	} else if (random == 3){
		xVel += charVel;
	} else if (random == 4){
		xVel -= charVel;
	}    */
	if (xBullet > ROOM_WIDTH || xBullet < 0 || yBullet > ROOM_HEIGHT || yBullet < 0){
		bullet = 0;
		xBullet = img_rectangle.x;
		yBullet = img_rectangle.y;
	}
}



