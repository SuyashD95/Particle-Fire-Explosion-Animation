/*
 * Project: Particle Fire Explosion
 * Stage: 8
 * File: Particle.cpp
 * Author: suyashd95
 */

#include "Particle.h"

namespace particlefire {

Particle::Particle() {

	m_x = ((2.0 * rand()) / RAND_MAX) - 1;
	m_y = ((2.0 * rand()) / RAND_MAX) - 1;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

} /* namespace particlefire */
