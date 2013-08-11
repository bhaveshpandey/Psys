#ifndef __EMITTER_H__
#define __EMITTER_H__


#include <vector>
#include "Particle.h"



class Emitter
{
public:
	//friend class ParticleSystem ;

protected:
	//pointer to the vector<Particle*> to emit into
	//this is then set to the current psys emitter is 
	//added into. so when it emits it fills up the 
	//relevent particleSystem
	std::vector<Particle*> *fillThis;
	std::string name ;
	//to check if the emitter is active
	bool isActive ;
	//position of the Emitter..
	//will only be considered for LOCATION EMISSION and
	//not for Emission from 
	ofVec3f position ;


public:
	Emitter() ;
	//Emitter(const ParticleSystem &psys) ;
	~Emitter() ;
	//Just to create an emitter without name
	//name can then be set using setName()
	Emitter(std::vector<Particle*> &emitInThis) ;
	//Bind name to the emitter when using multiple emitters.
	Emitter(std::string _name, std::vector<Particle*> &emitInThis) ;


/*---------------------------------------------------------EMISSION---------------------------------------------------------*/
	//point emission
	//Uses emitters position to emit from..
	void emit(bool activate, int num) ;

	//set Initial position and velocity of particles
	//using ofVec3f
	//Constructor's getting too cluttered. Need to find a 
	//better solution for initialising and applying variance
	void emit(bool activate, int num, const ofVec3f &pos, const ofVec3f &vel, float xvelVar, float yvelVar, float zvelVar, 
		float _mass, float massVar, const ofColor& color) ;
	//using floats
	void emit(bool activate, int num, float xpos, float ypos, float zpos, float xvel, float yvel, float zvel, 
		float xvelVar, float yvelVar, float zvelVar, float _mass, float massVar, const ofColor& color) ;

	//Emit using an ofMesh
	//Disabled input Num of Particles to emit from geo
	//will implement in next commit
	//void emit(bool activate, const ofMesh& mesh, int num, float mass, float jitterScale) ;
	void emit(bool activate, ofMesh &mesh, float mass, float jitterScale) ;

//////////////////////////////////////////////////////////EMISSION///////////////////////////////////////////////////////////


/*------------------------------------------------------------NAME-----------------------------------------------------------*/
	//set emitter's name
	void setName(std::string _name) ;
	std::string getName() ;
//////////////////////////////////////////////////////////////NAME//////////////////////////////////////////////////////////////


/*---------------------------------------------------EMITTER STATUS-----------------------------------------------------------*/
	bool isEmitterActive() ;
/////////////////////////////////////////////////////EMITTER STATUS/////////////////////////////////////////////////////////////


/*-------------------------------------------------------EMITTER POSITION-------------------------------------------------------*/
	void setPosition(const ofVec3f &pos) ;
	void setPosition(float x, float y, float z) ;
	const ofVec3f& getPosition() const ;
/////////////////////////////////////////////////////////EMITTER POSITION/////////////////////////////////////////////////////////


};

#endif



/*
-----------TO DO--------------------
1)	The emitter just creates particles at origin
	Fix it so we can set the INITIAL POS and INITIAL VEL
	of the particle being emitted.
	RESOLVED

2)	Parent the position of Emitter to the Particle System

3)	Also if the emitter is being moved the particles will move
	accordingly..like the SOURCE POP in the POPNET

4)	An Emitter which takes in the geometry and emits from its
	points/vertices etc.
	RESOLVED

5)	Extend this to emission from surfaces later on.
*/