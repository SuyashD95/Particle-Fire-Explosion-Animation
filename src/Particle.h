/*
 * Project: Particle Fire Explosion
 * Stage: 13 (Final)
 * File: Particle.h
 * Author: suyashd95
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <math.h>

namespace particlefire {

class Particle {

public:
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace particlefire */

#endif /* SRC_PARTICLE_H_ */
