#include "Emitter.h"


Emitter::Emitter() : fillThis(NULL), isActive(false), position(ofVec3f::zero())
{
	cout << "Default Emitter" << endl ;
}

Emitter::Emitter(std::vector<Particle*> &emitInThis) : 	fillThis(&emitInThis), isActive(false), position(ofVec3f::zero())
{ }

Emitter::Emitter(std::string _name, std::vector<Particle*> &emitInThis) : 
	name(_name), fillThis(&emitInThis), isActive(false), position(ofVec3f::zero())	{ }

Emitter::~Emitter()	{}


/*---------------------------------------------------------EMISSION---------------------------------------------------------*/
//point emission
//Uses emitters position to emit from..
void Emitter::emit(bool activate, int num)
{
	isActive = activate ;
	if(isActive)
	{
		for(int i= 0 ; i< num ; i++ )
		{
			Particle *newParticle = new Particle(fillThis->size(), position, ofVec3f::zero(), 0.f,0.f,0.0f, 1000.f, 100.f) ;
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

void Emitter::emit(bool activate, int num, const ofVec3f &pos, const ofVec3f &vel, 
	float xvelVar, float yvelVar, float zvelVar, float mass, float massVar, const ofColor &color)
{
	isActive = activate ;
	if(isActive)
	{
		for(int i= 0 ; i< num ; i++ )
		{
			//using SIZE() of the vector to set ptnum..
			// Particle *newParticle = new Particle(fillThis->size(), jitterPos, jitterVel, mass) ;
			Particle *newParticle = new Particle(fillThis->size(), pos, vel, xvelVar, yvelVar, zvelVar, mass, massVar) ;
			newParticle->setColor(color) ;
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

void Emitter::emit(bool activate, int num, float xpos, float ypos, float zpos, float xvel, float yvel, float zvel, 
	float xvelVar, float yvelVar, float zvelVar, float mass, float massVar, const ofColor& color)
{
	isActive = activate ;
	if(isActive)
	{
		for(int i= 0 ; i< num ; i++ )
		{
			Particle *newParticle = new Particle(fillThis->size(), xpos, ypos, zpos, xvel, yvel, zvel, xvelVar, yvelVar, zvelVar, mass, massVar) ;
			newParticle->setColor(color) ;
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


//----------------------------------IMPLEMENTATION FOR EMISSION FROM OFMESH-----------------------------------------
// void Emitter::emit(bool activate, const ofMesh& mesh, int num, float mass, float jitterScale) {}

void Emitter::emit(bool activate, ofMesh &mesh, float mass, float massVar)
{
	isActive = activate ;
	if(isActive)
	{
		// std::vector<ofVec3f> verticesInGeo = mesh.getVertices() ;
		// static int ctr = 0;
		// if(mesh.hasColors())
		// {
		// 	std::vector<ofColor> colorsInMesh = mesh.getColors() ;
		// }
		// for(std::vector<ofVec3f>::const_iterator it = verticesInGeo.begin(); it != verticesInGeo.end(); ++it)
		// {
		// // 	// float xpos = xpos + Utility::of_Randomf(ctr) * jitterScale ;
		// // 	// float ypos = ypos + Utility::of_Randomf(22 * ctr) * jitterScale ;
		// // 	// float zpos = zpos + Utility::of_Randomf(33 * ctr) * jitterScale ;
		// // 	// ofVec3f jitterPos = ofVec3f(xpos, ypos, zpos) ;
		// 	float mass = _mass + Utility::of_Randomf(ctr*5) * jitterScale ;
		// // 	// Particle *newParticle = new Particle(ctr, jitterPos, ofVec3f(0.f, 0.f, 0.f), mass) ;
		// 	Particle *newParticle = new Particle(ctr, *it , ofVec3f(0.f, 0.f, 0.f), mass) ;
		// 	fillThis->push_back(newParticle) ;
		// 	ctr++ ;
		// }

		for(int i = 0; i < mesh.getNumIndices(); i+=3)
		{
			ofVec3f curVertex = mesh.getVertex(mesh.getIndex(i)) ;
			Particle *newParticle = new Particle(fillThis->size(), curVertex , ofVec3f(0.f, 0.f, 0.f), 0.f,0.f,0.f, mass, massVar) ;
			//if mesh has colors, particles will inherit those 
			if(mesh.hasColors())
			{
				ofColor curVertexColor = mesh.getColor(mesh.getIndex(i)) ;
				newParticle->setColor(curVertexColor) ;
			}
		 	fillThis->push_back(newParticle) ;
		}

		cout << "Finished emitting " << mesh.getNumIndices() << " particles and set initial position and velocity" ;
		if(name != "")
			cout <<" from MESH " << name << endl ;
		else cout << endl ;
	}

	isActive = false ;
}
//////////////////////////////////////////////////////////////////EMISSION////////////////////////////////////////////////////////////////



/*-----------------------------------------------------------------NAME-----------------------------------------------------------------*/
void Emitter::setName(std::string _name) 
{
	name = _name ;
}

std::string Emitter::getName() 
{
	return name ;
}
///////////////////////////////////////////////////////////////////NAME////////////////////////////////////////////////////////////////////



/*-----------------------------------------------------------EMITTER STATUS--------------------------------------------------------------*/
bool Emitter::isEmitterActive()
{
	return isActive ;
}
/////////////////////////////////////////////////////////////EMITTER STATUS////////////////////////////////////////////////////////////////


/*------------------------------------------------------------EMITTER POSITION------------------------------------------------------------*/
void Emitter::setPosition(const ofVec3f &pos) 
{
	position = pos ;
}
void Emitter::setPosition(float x, float y, float z) 
{
	position.set(x, y, z) ;
}
const ofVec3f& Emitter::getPosition() const 
{
	return position ;
}
//////////////////////////////////////////////////////////////EMITTER POSITION//////////////////////////////////////////////////////////////
