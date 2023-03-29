#pragma once

#include "Character.h"

#include "RigidBody.h"


#define JUMPTIME 15.0f
#define JUMPFORCE 10.0f

class Player : public Character {
private:
	int speed;
	float jumpTime, jumpForce;
	bool isJumping, isGrounded;
	
	Position lastSafePosition;

	
	
	RigidBody* rigidBody;
	

public:
	
	Player(string i, int x, int y, int as);
	int getSpeed() { return speed; };
	void Update();
	void Render();
	void Clean();
	~Player();
};