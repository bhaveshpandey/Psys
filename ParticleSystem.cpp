#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() {}

ParticleSystem::~ParticleSystem() {}

void ParticleSystem::setPosition()	{}
ofVec3f ParticleSystem::getPosition() {}

int ParticleSystem::numParticles()
{
	return particles.size() ;
}

Emitter* ParticleSystem::addEmitter()
{
	Emitter *newEmitter = new Emitter(particles); 
	return newEmitter ;
}

Emitter* ParticleSystem::addEmitter(std::string _name)
{
	Emitter *newEmitter = new Emitter(_name, particles); 
	return newEmitter ;
}


Particle& ParticleSystem::getParticle(int num) 
{
	return *(particles.at(num)) ;
}
const std::vector<Particle *>& ParticleSystem::getAllParticles() const 
{
	return particles ;
}

void ParticleSystem::addForce(const ofVec3f &force)
{
	for(std::vector<Particle*>::const_iterator it = particles.begin(); it != particles.end(); ++it)
	{
		(*it)->addForce(force) ;
	}
}

void ParticleSystem::addForce(float x, float y, float z)
{
	for(std::vector<Particle*>::const_iterator it = particles.begin(); it != particles.end(); ++it)
	{
		(*it)->addForce(x, y, z) ;
	}
}

void ParticleSystem::update(float timeStep)
{
for(std::vector<Particle*>::const_iterator it = particles.begin(); it != particles.end(); ++it)
	{
		(*it)->update(timeStep) ;
	}	
}

void ParticleSystem::update(float timeStep, float maxSpeed)
{
	for(std::vector<Particle*>::const_iterator it = particles.begin(); it != particles.end(); ++it)
	{
		(*it)->update(timeStep, maxSpeed) ;
	}
}

void ParticleSystem::draw()
{
	glBegin(GL_POINTS) ;
	glPointSize(2) ;
	for(std::vector<Particle*>::const_iterator it = particles.begin(); it != particles.end(); ++it)
	{
		(*it)->draw() ;
	}
	glEnd() ;
}