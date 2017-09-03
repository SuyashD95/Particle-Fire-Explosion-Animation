/*
 * Project: Particle Fire Explosion
 * Stage: 9
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

	double m_xspeed;
	double m_yspeed;

public:
	Particle();
	virtual ~Particle();
	void update();
};

} /* namespace particlefire */

#endif /* SRC_PARTICLE_H_ */
