#ifndef MEANSHIFT_H
#define MEANSHIFT_H
#include "Clustering.h"
#include <vector>
using namespace std;
#define NUM_ITERATIONS 1000

class MeanShift:public Clustering
{
	public:
		MeanShift();
		void meanShift(double);
		Node shiftPoint(const Node &,double);
		~MeanShift();
		
	private:
};

#endif
