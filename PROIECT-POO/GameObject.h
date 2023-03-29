#pragma once


#include "KeyboardInput.h"
#include "Animation.h"
#include "Collider.h"


//clasa abstracta pentru obiecte si personaje
class GameObject{

protected:
	int animationSpeed; // viteza de animatie a miscarii caracterului
	int frame; //frame-ul actual; va lua valori consecutive din intervalul [0, nrFrames-1]
	int nrFrames; //numarul de frames ale animatiei(enum state)
	Position initialPosition;//pozitia initiala a obiectului
	Position* origin;
	Animation* animation;
	Position* p;
	Collider* collider;
	string id;

public:
	GameObject(string i, int x, int y, int a);
	Position* getOrigin() { return origin; }
	//functii virtuale pure
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Clean() = 0;
	virtual ~GameObject();
};