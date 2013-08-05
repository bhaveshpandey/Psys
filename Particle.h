#ifndef __PARTICLE_H__
#define __PARTICLE_H__


#include <iostream>
//#include "/apps/sidefx/hfs12.5.436/toolkit/include/OpenEXR/ImathVec.h" 		//for work env
//#include "/opt/hfs12.5.449/toolkit/include/OpenEXR/ImathVec.h"			//for home env
#include "ofMain.h"

using std::cin ;
using std::cout ;
using std::endl ;
//using namespace IMATH_INTERNAL_NAMESPACE ;



class Particle
{
public:

protected:
	int ptnum ;
	ofVec3f position ;
	ofVec3f velocity ;
	ofVec3f forces	 ;

/*---------------OP OVERLOADS---------------------------*/
public:
	void operator = (const Particle &other) ;

//////////////////////////////////////////////////////////


public:
	Particle();
	~Particle();
	//COPY INITIALIZER
	Particle(const Particle &other) ;
	Particle(int _ptnum, const ofVec3f &pos, const ofVec3f &initialVel) ;
	Particle(int _ptnum, float xpos, float ypos, float zpos, float xvel, float yvel, float zvel) ;

	int getPtnum() ;
	void setPtnum(int _ptnum) ;

	/*-------POSITION------------------------------------*/
	ofVec3f& getPosition() ;
	//setters for position field
	void setPosition(const ofVec3f &pos) ;
	void setPosition(float x, float y, float z) ;
	///////////////////////////////////////////////////////

	/*------VELOCITY--------------------------------------*/
	ofVec3f& getVelocity() ;
	//setters for velocity field
	void setVelocity(const ofVec3f &vel) ;
	void setVelocity(float x, float y, float z) ;
	///////////////////////////////////////////////////////

	/*------FORCES---------------------------------------*/
	//so getters as force is used internally.
	//However we will use setters to add forces into the 
	//system
	void addForce(const ofVec3f &force) ;
	void addForce(float x, float y, float z) ;


	void update(float timeStep) ;
	void update(float timeStep, float maxSpeed) ;

	void draw() ;


};

#endif