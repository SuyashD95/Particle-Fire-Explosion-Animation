/*
 * Project: Particle Fire Explosion
 * Stage: 5
 * File: Screen.cpp
 * Author: suyashd95
 */

#include "Screen.h"

namespace particlefire {

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {};

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		SDL_GetError();
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {

		SDL_GetError();
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1,
			SDL_RENDERER_PRESENTVSYNC);

	if (m_renderer == NULL) {

		SDL_GetError();
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_texture == NULL) {

		SDL_GetError();
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(m_buffer, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {

		m_buffer[i] = 0xffff00ff; // 0xffff00ff -> yellow
	}

	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	return true;
}

bool Screen::processEvents() {

	SDL_Event event;

	while (SDL_PollEvent (&event)) {

		if (event.type == SDL_QUIT) {
			return false;
		}
	}

	return true;
}

void Screen::close() {

	delete[] m_buffer;
	SDL_DestroyTexture (m_texture);
	SDL_DestroyRenderer (m_renderer);
	SDL_DestroyWindow (m_window);
	SDL_Quit();
}

} /* namespace particlefire */