/*
 * Project: Particle Fire Explosion
 * Stage: 4
 * File: main.cpp
 * Author: suyashd95
 */

#include <iostream>
#include <SDL.h>

using namespace std;

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {

		cout << "SDL_Init Failed: " << SDL_GetError() << endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
																	 SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(window == NULL) {

		cout << "Could not show window: " << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if(renderer == NULL) {

		cout << "Could not create a renderer: " << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
													   SCREEN_WIDTH, SCREEN_HEIGHT);

	if(texture == NULL) {

		cout << "Could not create a texture: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {

//		buffer[i] = 0xff0000ff; // For Red Background
//		buffer[i] = 0x00ff00ff; // For Green Background
//		buffer[i] = 0x0000ffff; // For Blue Background

		buffer[i] = 0x23ff80ff;

//		if(i >= 30000 && i <= 30200) // Setting a color of a group of pixel(s) individually
//			buffer[i] = 0x0000ffff;
	}

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;

	SDL_Event event;

	while(!quit) {

		// Update particles
		// Draw particles
		// Check for messages/events

		while(SDL_PollEvent(&event)) {

			if(event.type == SDL_QUIT) {

				quit = true;
			}
		}
	}

	delete [] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
