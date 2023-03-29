#include "KeyboardInput.h"



void KeyboardInput::updatePressed() {
    
    if (Game::event.type != SDL_QUIT) {
        if (Game::event.type == SDL_KEYDOWN) {
            //Select surfaces based on key press
            SDL_Keycode s = Game::event.key.keysym.sym;

            switch (s) {
            case SDLK_LEFT:
                left = true;
                break;
            case SDLK_RIGHT:
                right = true;
                break;
            case SDLK_UP:
                up = true;
                break;
         
            case SDLK_x:
                if (xkey == true) { xkey = false; }
                else { xkey = true; }
                break;
            }
        }
    }
}

void KeyboardInput::updateReleased() {

    if (Game::event.type != SDL_QUIT) {
        if (Game::event.type == SDL_KEYUP) {
            //Select surfaces based on key press
            SDL_Keycode s = Game::event.key.keysym.sym;
            switch (s) {
            case SDLK_LEFT:
                left = false;
                break;
            case SDLK_RIGHT:
                right = false;
                break;
            case SDLK_UP:
                up = false;
                break;

            }
        }
    }
}