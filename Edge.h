#ifndef EDGE_H
#define EDGE_H
#include "Node.h"

class Edge
{
	public:
		Edge(Node,Node);
		double euclideanDistance(void);
		double gaussianKernel(double);
		~Edge();
	private:
		Node n1;
		Node n2;
};

#endif
