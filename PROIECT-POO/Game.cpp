
#include "Player.h"
#include "Map.h"
#include "KeyboardInput.h"
#include "Camera.h"
#include "CollisionHandler.h"
#include "Coin.h"


GameObject* player = nullptr;
GameObject* crystal[10];

Game Game::game;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
TextureManager TextureManager::tex;
KeyboardInput KeyboardInput::key;
Camera Camera::camera;
CollisionHandler CollisionHandler::colHandler;



Game::Game() {
	window = NULL;
	renderer = NULL;
	isRunning = 0;
	levelMap = new GameMap();
}

Game::~Game() {
	if (levelMap) {
		delete[] levelMap;
		levelMap = 0;
	}
}

void Game::init(const char* title, int x, int y, int width, int height) {

	isRunning = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Initialized!" << endl;
		window = SDL_CreateWindow(title, x, y, width, height, 0); //creare meniu fereastra
		if (window) {
			cout << "Window created!" << endl;
			renderer = SDL_CreateRenderer(window, -1, 0); //creare interfata fereastra
			if (renderer) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				cout << "Renderer created!" << endl;
				isRunning = 1;
			} 
			else {
				cerr << "Renderer cannot be created!" << SDL_GetError()<< endl;
			}
		}
		else {
			cerr << "Window cannot be created!" << SDL_GetError() << endl; //cout error
		}

		TextureManager::tex.Init();
		player = new Player("WAIT", 130,710, 250);
		Camera::camera.setTarget(player->getOrigin());
		crystal[0]= new Coin("crystal", 192, 128, 250);
		crystal[1] = new Coin("crystal", 1024, 704, 250);
		crystal[2] = new Coin("crystal", 512, 448, 250);
		crystal[3] = new Coin("crystal", 128, 384, 250); 
		crystal[4] = new Coin("crystal", 704, 128, 250);
		crystal[5] = new Coin("crystal", 832, 128, 250);
		crystal[6] = new Coin("crystal", 1152, 512, 250);
		crystal[7] = new Coin("crystal", 1408, 832, 250);
		crystal[8] = new Coin("crystal", 1408, 64, 250);
		crystal[9] = new Coin("crystal", 1536, 128, 250);
	
	}
}

void Game::events() {
	contor++;
	cout << contor << endl;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT: isRunning = 0;
		break;
	case SDL_KEYDOWN: KeyboardInput::key.updatePressed();
		break;
	case SDL_KEYUP: KeyboardInput::key.updateReleased();
		break;
	default:
		break;
	}
}

void Game::update() {
	contor++;
	cout << contor << endl;
	levelMap->LoadMap(1);
	player->Update();
	Camera::camera.Update();
	for (int i = 0; i < 10; i++) {
		crystal[i]->Update();
	}
	
}

void Game::render() {
	SDL_RenderClear(renderer);
	Position a(0, 0);
	//add stuff to render
	TextureManager::tex.Draw("level1", a, 1600, 896, 1);
	levelMap->DrawMap();
	player->Render();
	for (int i = 0; i < 10; i++) {
		crystal[i]->Render();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	player->Clean();
	SDL_Quit();
	cout << "Game cleaned!" << endl;
}

bool Game::running() {
	return isRunning;
}