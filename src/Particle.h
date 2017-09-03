/*
 * Project: Particle Fire Explosion
 * Stage: 8
 * File: Particle.h
 * Author: suyashd95
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>

namespace particlefire {

struct Particle {

	double m_x;
	double m_y;

public:
	Particle();
	virtual ~Particle();
};

} /* namespace particlefire */

#endif /* SRC_PARTICLE_H_ */
