#include "Utility.h"



float Utility::of_Randomuf(int seed)
{
	ofSeedRandom(seed) ;
	return ofRandomuf() ;	
}

float Utility::of_Randomf(int seed)
{
	ofSeedRandom(seed) ;
	return ofRandomf() ;
}
