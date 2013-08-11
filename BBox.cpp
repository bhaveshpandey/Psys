#include "BBox.h"


BBox::BBox()
{
	min.set(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max() ) ;
	max.set( -1.f * std::numeric_limits<float>::max(), -1.f * std::numeric_limits<float>::max(), -1.f * std::numeric_limits<float>::max() );

}
// BBox::BBox()
// {

// }
BBox::~BBox()
{

}

//Will remove this in favour of a more central/generic input type 
//Multiple versions will make things confusing. Might look into something like
//this later.
// /*--------------------------track bounds of a vector of Particle pointers-------------------------*/
// void BBox::trackBounds(const std::vector<Particle*> &particles) 
// {
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

// 	}
// }
// ////////////////////////////////////////////////////////////////////////////////////////////////////////


/*------------------------------------track bounds of OFMESH-------------------------------------------*/
//to avoid any dynamic memory alloc supply this a Vector of Vertices.
void BBox::trackBounds(const std::vector<ofVec3f> &meshVertices )
{
if(!meshVertices.empty())
	{
		//unable to use numeric_limits in initialisation
		//need to get a way to use that instead of these
		//hardcoded numbers..
		min.set(1000000.f, 1000000.f, 1000000.f) ;
		max.set(-1000000.f, -1000000.f, -1000000.f) ;

		// min = ofVec3f(tmp_min, tmp_min, tmp_min) ;
		for(std::vector<ofVec3f>::const_iterator it = meshVertices.begin(); it != meshVertices.end(); ++it)
		{
			//set min and max XPOS
			if( it->x < min.x )
				min.x = it->x ;
			if( it->x > max.x )
				max.x = it->x ;

			//set min and max YPOS
			if( it->y < min.y )
				min.y = it->y ;
			if( it->y > max.y )
				max.y = it->y ;

			//set min and max XPOS
			if( it->z < min.z )
				min.z = it->z ;
			if( it->z > max.z )
				max.z = it->z ;
		}

	}	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////


void BBox::draw(const ofColor &color) 
{
	ofSetColor(color) ;
	//only need to draw 6 faces..
	//no need to draw common/shared edges for each face

	//draw MIN ZX plane
	ofLine(min.x, min.y, min.z, max.x, min.y, min.z) ;
	ofLine(min.x, min.y, max.z, max.x, min.y, max.z) ;
	ofLine(min.x, min.y, min.z, min.x, min.y, max.z) ;
	ofLine(max.x, min.y, min.z, max.x, min.y, max.z) ;
	//draw MAX ZX plane
	ofLine(min.x, max.y, min.z, max.x, max.y, min.z) ;
	ofLine(min.x, max.y, max.z, max.x, max.y, max.z) ;
	ofLine(min.x, max.y, min.z, min.x, max.y, max.z) ;
	ofLine(max.x, max.y, min.z, max.x, max.y, max.z) ;

	//draw xy plane


	//draw MIN YZ plane
	ofLine(min.x, min.y, min.z, min.x, max.y, min.z) ;
	ofLine(min.x, min.y, max.z, min.x, max.y, max.z) ;
	ofLine(min.x, min.y, min.z, min.x, max.y, min.z) ;
	//draw MIN YZ plane
	ofLine(max.x, min.y, min.z, max.x, max.y, min.z) ;
	ofLine(max.x, min.y, max.z, max.x, max.y, max.z) ;
	ofLine(min.x, min.y, min.z, min.x, max.y, min.z) ;

}


ofVec3f& BBox::getMin()
{
	return min ;	
}

ofVec3f& BBox::getMax()
{
	return max ;
}