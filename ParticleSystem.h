#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__


#include <vector>
#include "Particle.h"
#include "Emitter.h"
//#include "/apps/sidefx/hfs12.5.436/toolkit/include/OpenEXR/ImathVec.h"


//using namespace IMATH_INTERNAL_NAMESPACE ;



class Emitter;		//forward declare Emitter


class ParticleSystem
{
protected:
	ofVec3f position ;
	std::vector<Particle *> particles;


public:
	ParticleSystem() ;
	~ParticleSystem() ;

	void setPosition();
	ofVec3f getPosition() ;
	int numParticles() ;


	Emitter* addEmitter() ;
	Emitter* addEmitter(std::string _name) ;

	Particle& getParticle(int num) ;
	const std::vector<Particle *>& getAllParticles() const ;


	void addForce(const ofVec3f &force) ;
	void addForce(float x, float y, float z) ;
	void update(float timeStep) ;
	void update(float timeStep, float maxSpeed) ;
	void draw() ;

	

};

#endif