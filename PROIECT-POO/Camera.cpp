#include "Camera.h"

void Camera::Update() {
	if (target != nullptr){
		viewBox.x = target->getX() - screenWid / 2;
		if (viewBox.x < 0) { viewBox.x = 0; }

		viewBox.y = target->getY() - screenHei / 2;
		if (viewBox.y < 0) { viewBox.y = 0; }

		float raport = 30.0 / colCount; //30-numarul de coloane ale mapei nivelului 1

		if (viewBox.x > (raport* screenWid - viewBox.w)) { viewBox.x = (raport* screenWid - viewBox.w); }
		if (viewBox.y > (screenHei - viewBox.h)) { viewBox.y = (screenHei - viewBox.h); }

		pos = Position(viewBox.x, viewBox.y);
	}
}