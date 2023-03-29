#include "Coin.h"
#include "Camera.h"

Coin::Coin(string i, int x, int y, int a) : GameObject(i, x, y, a) {
	nrFrames = 4;
	collider->setBuffer({  0,0 ,0, 0 });
}

void Coin::Update() {
	animation->Init(id, 1, nrFrames);
	animation->Update();
}

void Coin::Render() {
	animation->Render(p, 0);
}

void Coin::Clean() {
}

Coin::~Coin() {

}