#pragma once

#include "Position.h"

#define GRAVITY  3.0f
#define MASS  1.0f
#define DELTATIME 1.0f


class RigidBody {
private:
	float mass, gravity, deltaTime;
	//forte
	Position force;
	Position friction;

	Position distance; //distanta
	Position velocity; //viteza
	Position acceleration; //acceleratie

public:
	RigidBody() {
		mass = MASS;
		gravity = GRAVITY;
		deltaTime = DELTATIME;
	}
	float getMass() { return mass; }

	void setMass(float m) { mass = m; }
	void setGravity(float g) { gravity = g; }

	void applyForce(Position f) { force = f; }
	void applyForceX(float x) { force.setX(x); }
	void applyForceY(float y) { force.setY(y); }
	void unSetForce() { force = Position(0, 0); }

	void applyFriction(Position f) { friction = f; }
	void unSetFriction() { friction = Position(0, 0); }

	Position getDistance() { return distance; }
	Position getVelocity() { return velocity; }
	Position getAcceleration() { return acceleration; }

	void Update() {
		acceleration.setX((force.getX() + friction.getX()) / mass); // acceleratia = forta / masa
		acceleration.setY(gravity + force.getY() / mass);
		velocity = acceleration *deltaTime ; // viteza = acceleratia * timp
		distance = velocity * deltaTime; // distanta = viteza * timp
	}
};