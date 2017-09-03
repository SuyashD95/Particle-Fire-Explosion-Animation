/*
 * Project: Particle Fire Explosion
 * Stage: 5
 * File: Screen.h
 * Author: suyashd95
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace particlefire {

class Screen {

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;

public:
	Screen();
	bool init();
	bool processEvents();
	void close();
};

} /* namespace particlefire */

#endif /* SCREEN_H_ */
