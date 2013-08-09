#include "Particle.h"



/*---------------OP OVERLOADS---------------------------*/
void Particle::operator = (const Particle &other)
{
	this->ptnum 		= other.ptnum ;
	this->position 		= other.position ;
	this->velocity 		= other.velocity ;
	this->forces	 	= other.forces ;
	this->mass 			= other.mass ;
	this->radius 		= other.radius ;
	this->color 		= other.color ;
}
//Also need to copy particles attributes (maybe a flag for it)
//Will Implement it later after setting up a functional system

//////////////////////////////////////////////////////////



Particle::Particle() : ptnum(0), position(0), mass(1), radius(1), color(ofColor::white)
{
	// cout << "Initializing default Settings" << endl ;
	// cout << "position( " << position.x << "," << position.y << "," << position.z << " )" << endl ;
}

Particle::~Particle() 	{}

//TO DO copy attributes of the input Particle
Particle::Particle(const Particle &other) : 
	ptnum(other.ptnum), 
	position(other.position),
	velocity(other.velocity),
	forces(other.forces),
	color(other.color)
	{
		cout << "Created Particle(ptnum: " << ptnum << ")" 
		<< " from input Particle(ptnum: " << other.ptnum << ")" << endl ;
	}

Particle::Particle(int _ptnum, const ofVec3f &pos, const ofVec3f &initialVel, float _mass) :
	ptnum(_ptnum), 
	position(pos), 
	velocity(initialVel),
	mass(_mass),
	color(ofColor::white)
	{
		radius = mass ;
		//init forces to zero
		forces.set(0,0,0) ;
	}

Particle::Particle(int _ptnum, float xpos, float ypos, float zpos, float xvel, float yvel, float zvel, float _mass) :
	ptnum(_ptnum),
	position(ofVec3f(xpos, ypos, zpos)) ,
	velocity(ofVec3f(xvel, yvel, zvel)),
	mass(_mass),
	color(ofColor::white)
	{
		radius = mass ;
		// position.set(xpos, ypos, zpos) ;
		// velocity.set(xvel, yvel, zvel) ;
		forces.set(0.f, 0.f, 0.f) ;
	}

/*-------------PTNUM--------------------------------*/
int Particle::getPtnum() const
{
	return ptnum ;
}
void Particle::setPtnum(int _ptnum) 
{
	ptnum = _ptnum ;
}

/*-------POSITION------------------------------------*/
ofVec3f& Particle::getPosition() 
{
	return position ;
}
void Particle::setPosition(const ofVec3f &pos) 
{
	position = pos ;
}
void Particle::setPosition(float x, float y, float z) 
{
	position.set(x,y,z) ;
}
///////////////////////////////////////////////////////

/*------VELOCITY--------------------------------------*/
ofVec3f& Particle::getVelocity() 
{
	return velocity ;
}
void Particle::setVelocity(const ofVec3f &vel) 
{
	velocity = vel ;
}
void Particle::setVelocity(float x, float y, float z) 
{
	velocity.set(x,y,z) ;
}
///////////////////////////////////////////////////////

/*------FORCES---------------------------------------*/
void Particle::addForce(const ofVec3f &force) 
{
	forces += force ;
}
void Particle::addForce(float x, float y, float z) 
{
	forces += ofVec3f(x,y,z) ;
}
//////////////////////////////////////////////////////

/*--------COLOR--------------------------------------*/
	void Particle::setColor(const ofColor &_color) 
	{
		color = _color ;
	}
	void Particle::setColor(const ofVec3f &_color) 
	{
		color.set(_color.x, _color.y, _color.z) ;
	}
	void Particle::setColor(float r, float g, float b) 
	{
		color.set(r, g, b) ;
	}
	ofColor& Particle::getColor() 
	{
		return color ;
	}
//////////////////////////////////////////////////////


/*---------------------------UPDATE-----------------------------*/
void Particle::update(float timeStep)
{
	velocity += forces/max(mass,0.0001f) ;
	position += velocity * timeStep ;
	forces.set(0,0,0) ;
}
void Particle::update(float timeStep, float maxSpeed)
{
	velocity += forces/max(mass,0.0001f) ;
	velocity.limit(maxSpeed) ;
	position += velocity * timeStep ;
	forces.set(0,0,0) ;
}
//////////////////////////////////////////////////////////////////


/*---------------------------DRAW-------------------------------*/
void Particle::draw()
{
	//draw as points
	ofSetColor(color) ;
	glVertex3f(position.x, position.y, position.z) ;
}
//////////////////////////////////////////////////////////////////