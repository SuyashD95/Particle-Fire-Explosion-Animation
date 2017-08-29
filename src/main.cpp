/*
 * Project: Particle Fire Explosion
 * Stage: 1
 * File: main.cpp
 * Author: suyashd95
 */

#include <iostream>
#include <SDL.h>

using namespace std;

int main() {

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {

		cout << "SDL_Init failed." << endl;
		return 1;
	}

	cout << "SDL_Init succeeded." << endl;
	SDL_Quit();

	return 0;
}
