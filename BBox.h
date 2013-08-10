#ifndef __BBOX_H__
#define __BBOX_H__


#include <vector>
#include <limits>
#include "ofMain.h"
#include "Particle.h"


class BBox
{
private:
	ofVec3f min ;
	ofVec3f max ;


public:
	BBox() ;
	// BBox() ;
	~BBox() ;


	void trackBounds(const std::vector<Particle*> &particles ) ;
	void draw(const ofColor &color) ;

	ofVec3f& getMin() ;
	ofVec3f& getMax() ;

};





#endif