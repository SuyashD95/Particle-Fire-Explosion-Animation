/*
 * Project: Particle Fire Explosion
 * Stage: 12
 * File: Particle.h
 * Author: suyashd95
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <math.h>

namespace particlefire {

struct Particle {

	double m_x;
	double m_y;

	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace particlefire */

#endif /* SRC_PARTICLE_H_ */
