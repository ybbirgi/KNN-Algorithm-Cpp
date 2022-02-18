#include "MeanShift.h"
#include "Edge.h"
#include <vector>
using namespace std;
MeanShift::MeanShift()
{
}
/**
*meanShift function
*The nodes are getting shifted and getting stored on a vector
*@param NUM_ITERATIONS Decides how many times to shift the nodes
*/
///meanShift function
void MeanShift::meanShift(double bandwidth) {

    shiftedPoints = nodes;

    for (int j = 0; j < NUM_ITERATIONS; j++) {
        for (int i = 0; i < nodes.size(); i++) {
            Node newNode = shiftPoint(shiftedPoints[i],bandwidth);
            shiftedPoints[i] = newNode;
        }
    }
}
/**
*meanPoint function
*The nodes are getting shifted based on kernel function
*/
Node MeanShift::shiftPoint(const Node &oldPoint,double bandwidth) {
    float totalWeight = 0.0;
    Node shiftedPoint;
    for (auto it=nodes.begin();it!=nodes.end();it++){
    	Edge func(oldPoint,*it);
        float gaussian = func.gaussianKernel(bandwidth);
        shiftedPoint += *it * gaussian;
        totalWeight += gaussian;
    }

    shiftedPoint /= totalWeight;
    return shiftedPoint;
}
///Destructor
MeanShift::~MeanShift()
{
}

