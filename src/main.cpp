/*
 * Project: Particle Fire Explosion
 * Stage: 10
 * File: main.cpp
 * Author: suyashd95
 */

#include <iostream>
#include <math.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace particlefire;

int main() {

	srand(time(NULL));

	Screen screen;

	if(screen.init() == false) {

		cout << "Fatal Error: SDL failed to initialize." << endl;
	}

	Swarm swarm;

	const int HALF_SCREEN_WIDTH = Screen::SCREEN_WIDTH / 2;
	const int HALF_SCREEN_HEIGHT = Screen::SCREEN_HEIGHT / 2;

	while(true) {

		// Update particles

		// Draw particles
		int elapsed = SDL_GetTicks();

		screen.clear();
		swarm.update();

		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		const Particle* const pParticles= swarm.getParticles();

		for(int i = 0; i < Swarm::NPARTICLES; i++) {

			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * HALF_SCREEN_WIDTH;
			int y = (particle.m_y  * HALF_SCREEN_WIDTH) + HALF_SCREEN_HEIGHT;

			screen.setPixel(x, y, red, green, blue);
		}

		// Draw the screen
		screen.update();

		// Check for messages/events
		if(screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
