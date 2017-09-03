/*
 * Project: Particle Fire Explosion
 * Stage: 8
 * File: main.cpp
 * Author: suyashd95
 */

#include <iostream>
#include <math.h>
#include <SDL.h>

#include "Screen.h"

using namespace std;
using namespace particlefire;

int main() {

	Screen screen;

	if(screen.init() == false) {

		cout << "Fatal Error: SDL failed to initialize." << endl;
	}

//	int max = 0;

	while(true) {

		// Update particles

		// Draw particles

		int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

//		cout << "Elapsed: " << elapsed << "; Red: " << (int)red << "; Green: " << (int)green << "; Blue: " << (int)blue << endl;

//		if(green > max)
//			max = green;

//		cout << elapsed << ":" << green << endl;

		for(int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for(int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}

		// Draw the screen
		screen.update();

		// Check for messages/events
		if(screen.processEvents() == false) {
			break;
		}
	}

//	cout << "Max: " << max << endl;

	screen.close();

	return 0;
}
