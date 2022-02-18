#ifndef CLUSTERING_H
#define CLUSTERING_H
#include <iostream>
#include <vector>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#define clusterEps 1.0
using namespace std;
class Clustering
{
	public:
		Clustering();
		void readDataFromTXT(const string& fileName);
		void print(void) const;
		void buildClusters(void);
		int getNumberofClusters(void);
		vector<Graph> getClusters(void) const;
		~Clustering();
	protected:
		///Vector to store nodes
		vector<Node> nodes;
		///Vector to store shiftedPoints
		vector<Node> shiftedPoints;
		///Vector to store different clusters
		vector<Graph> clusters;
};

#endif
