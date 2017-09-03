/*
 * Project: Particle Fire Explosion
 * Stage: 1
 * File: main.cpp
 * Author: suyashd95
 */

#include <iostream>
#include <SDL.h>

using namespace std;

void setWindowToBlack(SDL_Window* window) {

	//	We must call SDL_CreateRenderer in order for draw calls to affect this window.
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	//	Select the color for drawing. It is set to black here.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	//	Clear the entire screen to our selected color.
		SDL_RenderClear(renderer);

	//	Up until now everything was drawn behind the scenes. This will show the new, black contents of the window.
		SDL_RenderPresent(renderer);

}

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		cout << "SDL_Init Failed." << endl;
		return 1;
	}

//	Create an application window.
	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
														 SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// Set Window background to Black.
	setWindowToBlack(window);

	// Check that window has been successfully created
	if(window == NULL) { // Same as if(!window)

		printf("Could not show window: %s\n", SDL_GetError()); // Outputs the error code/statement for debugging purposes
		SDL_Quit();
		return 2;
	}

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

//	SDL_Delay(10000); Pauses or delays the execution of the program

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
