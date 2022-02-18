#include "Edge.h"
#include <iostream>
#include <cmath>
#include "Node.h"
Edge::Edge(Node node1,Node node2)
:n1(node1),n2(node2)
{
	//cout << "Edge Constructor Called: << endl;
}
///The function to find distance between two nodes
double Edge::euclideanDistance(void)
{
	return sqrt((pow((n1.getX()-n2.getX()),2))+(pow((n1.getY()-n2.getY()),2)));
}
///The kernel function
double Edge::gaussianKernel(double bandwidth)
{
	return exp(-(pow(euclideanDistance(),2))/(2*powf(bandwidth,2)));
}
Edge::~Edge()
{
	//cout << "Edge Destructor Called: << endl;
}
