#include "Character.h"

Character::Character(string i, int x, int y, int as) : GameObject(i, x, y, as) {
    nrFrames = WAIT; //PERSONAJUL STA PE LOC
    direction = FRONT; //DIRECTIA - FATA
    frame = 0;
   
    
}

Character::~Character() {
 
}
