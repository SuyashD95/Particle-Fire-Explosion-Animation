/*
 * Project: Particle Fire Explosion
 * Stage: 8
 * File: Swarm.cpp
 * Author: suyashd95
 */

#include "Swarm.h"

namespace particlefire {

Swarm::Swarm() {

	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {

	delete [] m_pParticles;
}

} /* namespace particlefire */
