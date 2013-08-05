#include "Particle.h"



/*---------------OP OVERLOADS---------------------------*/
void Particle::operator = (const Particle &other)
{
	this->ptnum 		= other.ptnum ;
	this->position 		= other.position ;
	this->velocity 		= other.velocity ;
	this->forces	 	= other.forces ;
}
//Also need to copy particles attributes (maybe a flag for it)
//Will Implement it later after setting up a functional system

//////////////////////////////////////////////////////////



Particle::Particle() : ptnum(0), position(0)
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
	forces(other.forces)
	{
		cout << "Created Particle(ptnum: " << ptnum << ")" 
		<< " from input Particle(ptnum: " << other.ptnum << ")" << endl ;
	}

Particle::Particle(int _ptnum, const ofVec3f &pos, const ofVec3f &initialVel) :
	ptnum(_ptnum), 
	position(pos), 
	velocity(initialVel)
	{
		//since OpenEXR Vec3f doesn't support something like ofVec3f::zero()
		//cant initialize it in the init list syntax
		#if (OFCODE)	//CODE COMPATIBILITY WITH OF OR OPENEXR
			forces.set(0,0,0) ;				//FOR OF COMPATIBLE CODE

		#else
			forces.setValue(0,0,0) ;		//FOR OPENEXR COMPATIBLE CODE

		#endif
	}

Particle::Particle(int _ptnum, float xpos, float ypos, float zpos, float xvel, float yvel, float zvel) :
	ptnum(_ptnum)
	{
		//since OpenEXR Vec3f doesn't support something like ofVec3f::zero()
		//cant initialize it in the init list syntax
		#if (OFCODE)	//CODE COMPATIBILITY WITH OF OR OPENEXR
			position.set(xpos, ypos, zpos) ;
			velocity.set(xvel, yvel, zvel) ;
			forces.set(0.f, 0.f, 0.f) ;
		#else
			position.setValue(xpos, ypos, zpos) ;
			velocity.setValue(xvel, yvel, zvel) ;
			forces.setValue(0.f, 0.f, 0.f) ;
		#endif
	}

/*-------------PTNUM--------------------------------*/
int Particle::getPtnum()
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
	#if (OFCODE)	//CODE COMPATIBILITY WITH OF OR OPENEXR
		forces.set(0,0,0) ;				//FOR OF COMPATIBLE CODE

	#else
		forces.setValue(0,0,0) ;		//FOR OPENEXR COMPATIBLE CODE

	#endif
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
	#if (OFCODE)	//CODE COMPATIBILITY WITH OF OR OPENEXR
		forces.set(0,0,0) ;				//FOR OF COMPATIBLE CODE

	#else
		forces.setValue(0,0,0) ;		//FOR OPENEXR COMPATIBLE CODE

	#endif
}
///////////////////////////////////////////////////////

/*------FORCES---------------------------------------*/
void Particle::addForce(const ofVec3f &force) 
{
	forces += force ;
}
void Particle::addForce(float x, float y, float z) 
{
	#if (OFCODE)	//CODE COMPATIBILITY WITH OF OR OPENEXR
		forces += ofVec3f(x,y,z) ;				//FOR OF COMPATIBLE CODE

	#else
		ofVec3f tmp;
		tmp.setValue(x,y,z) ;
		forces += tmp ;		//FOR OPENEXR COMPATIBLE CODE

	#endif
}
//////////////////////////////////////////////////////

/*---------------------------UPDATE-----------------------------*/
void Particle::update(float timeStep)
{
	velocity += forces ;
	position += velocity * timeStep ;
	forces.set(0,0,0) ;
}
void Particle::update(float timeStep, float maxSpeed)
{
	velocity += forces ;
	velocity.limit(maxSpeed) ;
	position += velocity * timeStep ;
	forces.set(0,0,0) ;
}
//////////////////////////////////////////////////////////////////


/*---------------------------DRAW-------------------------------*/
void Particle::draw()
{
	ofSetColor(ofColor::red) ;
	// ofFill() ;
	// ofSphere(position.x, position.y, position.z, 1) ;
	glVertex3f(position.x, position.y, position.z) ;
}
//////////////////////////////////////////////////////////////////