/*
 * Project: Particle Fire Explosion
 * Stage: 3
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

		cout << "SDL_Init failed." << endl;
		return 1;
	}

	// Create an application window
	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
																	 SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// Check that window has been successfully created
	if(window == NULL) {

		printf("Could not show window: %s\n", SDL_GetError()); // Outputs the error code/statement for debugging purposes
		SDL_Quit();
		return 2;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC,
													   SCREEN_WIDTH, SCREEN_HEIGHT);

	if(renderer == NULL) {

		printf("Could not create a renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if(texture == NULL) {

		printf("Could not create a texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)); // 255 (Decimal) -> 0xFF (Hexadecimal)

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;

	SDL_Event event;

	while (!quit) {

		// Update particles
		// Draw particles
		// Check for messages/events


		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {

				quit = true;
			}
		}
	}

	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
