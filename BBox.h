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


/*---------------------------track bounds of OFMESH-------------------------*/
//ofMesh is a vector of ofVec3f vertices so this should work for a generic
//version which accepts a vector<ofVec3f> to track.
	void trackBounds( const std::vector<ofVec3f> &meshVertices ) ;
//////////////////////////////////////////////////////////////////////////////


	void draw(const ofColor &color) ;

	ofVec3f& getMin() ;
	ofVec3f& getMax() ;

};





#endif