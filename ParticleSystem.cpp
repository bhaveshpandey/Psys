#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() {}

ParticleSystem::~ParticleSystem() 
{
	cout << "Deleting ParticleSystem! Removing " << particles.size() << " particles." << endl ;

	for(std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it)
	{
		delete *it ;
	}
	particles.clear() ;
}

void ParticleSystem::setPosition()	{}
ofVec3f& ParticleSystem::getPosition() 
{
	return position ;
}

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

void ParticleSystem::kill(Particle *particleToKill)
{
	std::vector<Particle *>::iterator it = std::find(particles.begin(), particles.end(), particleToKill) ;
	delete *it ;
	particles.erase(it) ;
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
	glPointSize(1) ;
	for(std::vector<Particle*>::const_iterator it = particles.begin(); it != particles.end(); ++it)
	{
		(*it)->draw() ;
	}
	glEnd() ;
}











//Ported over to BBox class..
//Idea is to make this into a generic BBox type.
// void ParticleSystem::getAABB(ofVec3f &min, ofVec3f &max)
// {
// 	//run only if the particles vector is not empty
// 	if(!particles.empty())
// 	{
// 		//unable to use numeric_limits in initialisation
// 		//need to get a way to use that instead of these
// 		//hardcoded numbers..
// 		min.set(1000000.f, 1000000.f, 1000000.f) ;
// 		max.set(-1000000.f, -1000000.f, -1000000.f) ;

// 		// min = ofVec3f(tmp_min, tmp_min, tmp_min) ;
// 		for(std::vector<Particle*>::const_iterator it = particles.begin(); it != particles.end(); ++it)
// 		{
// 			//set min and max XPOS
// 			if( (*it)->getPosition().x < min.x )
// 				min.x = (*it)->getPosition().x ;
// 			if( (*it)->getPosition().x > max.x )
// 				max.x = (*it)->getPosition().x ;

// 			//set min and max YPOS
// 			if( (*it)->getPosition().y < min.y )
// 				min.y = (*it)->getPosition().y ;
// 			if( (*it)->getPosition().y > max.y )
// 				max.y = (*it)->getPosition().y ;

// 			//set min and max XPOS
// 			if( (*it)->getPosition().z < min.z )
// 				min.z = (*it)->getPosition().z ;
// 			if( (*it)->getPosition().z > max.z )
// 				max.z = (*it)->getPosition().z ;
// 		}

// 		// cout << "xmin:" << min.x << " xmax:" << max.x << endl ;
// 	}
// }

// void ParticleSystem::drawAABB(const ofVec3f &min, const ofVec3f &max)
// {
// 	//only need to draw 6 faces..
// 	//no need to draw common/shared edges for each face

// 	//draw MIN ZX plane
// 	ofLine(min.x, min.y, min.z, max.x, min.y, min.z) ;
// 	ofLine(min.x, min.y, max.z, max.x, min.y, max.z) ;
// 	ofLine(min.x, min.y, min.z, min.x, min.y, max.z) ;
// 	ofLine(max.x, min.y, min.z, max.x, min.y, max.z) ;
// 	//draw MAX ZX plane
// 	ofLine(min.x, max.y, min.z, max.x, max.y, min.z) ;
// 	ofLine(min.x, max.y, max.z, max.x, max.y, max.z) ;
// 	ofLine(min.x, max.y, min.z, min.x, max.y, max.z) ;
// 	ofLine(max.x, max.y, min.z, max.x, max.y, max.z) ;

// 	//draw xy plane


// 	//draw MIN YZ plane
// 	ofLine(min.x, min.y, min.z, min.x, max.y, min.z) ;
// 	ofLine(min.x, min.y, max.z, min.x, max.y, max.z) ;
// 	ofLine(min.x, min.y, min.z, min.x, max.y, min.z) ;
// 	//draw MIN YZ plane
// 	ofLine(max.x, min.y, min.z, max.x, max.y, min.z) ;
// 	ofLine(max.x, min.y, max.z, max.x, max.y, max.z) ;
// 	ofLine(min.x, min.y, min.z, min.x, max.y, min.z) ;

// }