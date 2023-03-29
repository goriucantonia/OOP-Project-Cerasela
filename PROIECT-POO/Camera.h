#pragma once

#include "Position.h"
class Camera {
private:
	Camera() { viewBox = { 0, 0, screenWid, screenHei }; }
	Position* target;
	Position pos;
	SDL_Rect viewBox;
	
public:
	static Camera camera;
	SDL_Rect getViewBox() { return viewBox; }
	Position getPosition() { return pos; }
	void setTarget(Position* t) { target = t; }
	void Update();
};