#pragma once

#include <SDL.h>

class Collider {
private:
	SDL_Rect box;
	SDL_Rect buffer;
public:
	SDL_Rect getBox() { return box; }
	void setBuffer(SDL_Rect a) { buffer = a; }
	void set(int x, int y, int w, int h) {
		box = {
			x - buffer.x,
			y - buffer.y,
			w - buffer.w,
			h - buffer.h
		};
	}

};