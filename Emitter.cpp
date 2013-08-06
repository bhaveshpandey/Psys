#include "Emitter.h"


Emitter::Emitter() : fillThis(NULL), isActive(false)
{
	cout << "Default Emitter" << endl ;
}

Emitter::Emitter(std::vector<Particle*> &emitInThis) : 	fillThis(&emitInThis), isActive(false) { }

Emitter::Emitter(std::string _name, std::vector<Particle*> &emitInThis) : 
	name(_name), fillThis(&emitInThis), isActive(false)	{ }

Emitter::~Emitter()	{}

void Emitter::emit(bool activate, int num)
{
	isActive = activate ;
	if(isActive)
	{
		for(int i= 0 ; i< num ; i++ )
		{
			Particle *newParticle = new Particle() ;
			//newParticle->setPtnum(i) ;
			fillThis->push_back(newParticle) ;
		}	

		cout << "Finished emitting " << num << " particles" ;
		if(name != "")
			cout <<" from " << name << endl ;
		else cout << endl ;
	}

	//set it to false after one cycle..
	//activate parameter will be used to 
	//set isActive again in next cycle
	isActive = false ;

}

void Emitter::emit(bool activate, int num, const ofVec3f &pos, const ofVec3f &vel, float _mass, float jitterScale)
{
	isActive = activate ;
	if(isActive)
	{
		for(int i= 0 ; i< num ; i++ )
		{
			ofVec3f jitterPos(pos.x + bp_ofRandomf(i) * jitterScale, pos.y + bp_ofRandomf(i*2) * jitterScale, pos.z + bp_ofRandomf(i*3) * jitterScale) ;
			ofVec3f jitterVel(vel.x + bp_ofRandomf(i) * jitterScale, vel.y + bp_ofRandomf(i*2) * jitterScale, vel.z + bp_ofRandomf(i*3) * jitterScale) ;
			float mass = _mass + bp_ofRandomf(i*5) * jitterScale ;
			Particle *newParticle = new Particle(i, jitterPos, jitterVel, mass) ;
			//newParticle->setPtnum(i) ;
			fillThis->push_back(newParticle) ;
		}	

		cout << "Finished emitting " << num << " particles and set initial position and velocity" ;
		if(name != "")
			cout <<" from " << name << endl ;
		else cout << endl ;
	}

	//set it to false after one cycle..
	//activate parameter will be used to 
	//set isActive again in next cycle
	isActive = false ;
}

void Emitter::emit(bool activate, int num, float xpos, float ypos, float zpos, float xvel, float yvel, float zvel, float _mass, float jitterScale)
{
	isActive = activate ;
	if(isActive)
	{
		//NEED TO FIND A BETTER WAY INSTEAD OF STATIC ctr to make new random every cycle.
		static int ctr = 0;
		for(int i= 0 ; i< num ; i++ )
		{
			ofVec3f jitterPos(xpos + bp_ofRandomf(i + ctr) * jitterScale, ypos + bp_ofRandomf(i*22 +ctr) * jitterScale, zpos + bp_ofRandomf(i*33 +ctr) * jitterScale) ;
			ofVec3f jitterVel(xvel + bp_ofRandomf(i +ctr) * jitterScale, yvel + bp_ofRandomf(i*22 +ctr) * jitterScale, zvel + bp_ofRandomf(i*33 +ctr) * jitterScale) ;
			float mass = _mass + bp_ofRandomf(i*5) * jitterScale ;
			Particle *newParticle = new Particle(i, jitterPos, jitterVel, mass) ;
			//newParticle->setPtnum(i) ;
			fillThis->push_back(newParticle) ;
			ctr++ ;
		}	

		cout << "Finished emitting " << num << " particles and set initial position and velocity" ;
		if(name != "")
			cout <<" from " << name << endl ;
		else cout << endl ;
	}

	//set it to false after one cycle..
	//activate parameter will be used to 
	//set isActive again in next cycle
	isActive = false ;
}


//--------------------IMPLEMENTATION FOR EMISSION FROM OFMESH---------------------------
void Emitter::emit(bool activate, const ofMesh& mesh, int num, float mass, float jitterScale)
{
	
}






void Emitter::setName(std::string _name) 
{
	name = _name ;
}

std::string Emitter::getName() 
{
	return name ;
}

bool Emitter::isEmitterActive()
{
	return isActive ;
}


//////////////////HELPER----------
float Emitter::bp_ofRandomf(int seed)
{
	ofSeedRandom(seed) ;
	return ofRandomf() ;
}