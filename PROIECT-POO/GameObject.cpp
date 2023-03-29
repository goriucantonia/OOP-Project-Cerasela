#include "GameObject.h"
#include "Animation.h"


GameObject::GameObject(string i, int x, int y, int a) {
	animationSpeed = a;
	id = i;
	initialPosition.setX(x);
	initialPosition.setY(y);
	animation = new Animation(animationSpeed);
	origin = new Position(x + playerSize, y + playerSize);
	collider = new Collider();
	p = new Position();
	p->setX(x);
	p->setY(y);
	
}
GameObject::~GameObject() {
	if (origin) {
		delete[] origin;
		origin = 0;
	}
	if (animation) {
		delete[] animation;
		animation = 0;
	}
	if (p) {
		delete[] p;
		p = 0;
	}
	if (collider) {
		delete[] collider;
		collider = 0;
	}

}

