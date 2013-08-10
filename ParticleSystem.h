#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__


#include <algorithm>			//for std::find()
#include <vector>
#include <limits>
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
	ofVec3f& getPosition() ;
	int numParticles() ;


	Emitter* addEmitter() ;
	Emitter* addEmitter(std::string _name) ;

	Particle& getParticle(int num) ;
	//can be used to set per particle attributes and fields
	/*------------EXAMPLE--------------
		vector<Particle*> list = ParticleSystem::getAllParticles() ;
		for(vector<Particle*>::const_iterator it = list.begin(); it!= list.end(); ++it)
		{
			(*it)->addForce(-----); //per particle operation
		}
		
	*/
	const std::vector<Particle *>& getAllParticles() const ;


	void addForce(const ofVec3f &force) ;
	void addForce(float x, float y, float z) ;
	void kill(Particle *particleToKill) ;
	void update(float timeStep) ;
	void update(float timeStep, float maxSpeed) ;
	void draw() ;

	void getAABB(ofVec3f &min, ofVec3f &max) ;
	void drawAABB(const ofVec3f &min, const ofVec3f &max) ;


	

};

#endif