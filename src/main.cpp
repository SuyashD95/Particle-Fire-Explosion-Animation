/*
 * Project: Particle Fire Explosion
 * Stage: 5
 * File: main.cpp
 * Author: suyashd95
 */

#include <iostream>
#include <SDL.h>

#include "Screen.h"

using namespace std;
using namespace particlefire;

int main() {

	Screen screen;

	if(screen.init() == false) {

		cout << "Fatal Error: SDL failed to initialize." << endl;
	}

	while(true) {

		// Update particles
		// Draw particles
		// Check for messages/events

		if(screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
