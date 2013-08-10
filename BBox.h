#ifndef __BBOX_H__
#define __BBOX_H__


#include <vector>
#include <limits>
#include "ofMain.h"
#include "Particle.h"


class BBox
{
private:
	//private data members to store min and max values
	ofVec3f min ;
	ofVec3f max ;


public:
	BBox() ;
	~BBox() ;

/*--------------track bounds of a vector of Particle pointers---------------*/
	void trackBounds( const std::vector<Particle*> &particles ) ;
//////////////////////////////////////////////////////////////////////////////

/*---------------------------track bounds of OFMESH-------------------------*/
	void trackBounds( const std::vector<ofVec3f> &meshVertices ) ;
//////////////////////////////////////////////////////////////////////////////


	void draw(const ofColor &color) ;

	ofVec3f& getMin() ;
	ofVec3f& getMax() ;

};





#endif