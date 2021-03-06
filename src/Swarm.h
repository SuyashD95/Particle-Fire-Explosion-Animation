/*
 * Project: Particle Fire Explosion
 * Stage: 13 (Final)
 * File: Swarm.h
 * Author: suyashd95
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particlefire {

class Swarm {

public:
	const static int NPARTICLES = 5000;

private:
	Particle* m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	const Particle* const getParticles() { return m_pParticles; };
	void update(int elapsed);
};

} /* namespace particlefire */

#endif /* SRC_SWARM_H_ */
