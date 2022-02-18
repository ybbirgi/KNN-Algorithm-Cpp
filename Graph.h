#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <vector>
class Graph
{
	public:
		Graph(Node&);
		Node getCentroid(void) const;
		void computeCentroid(const Node& );
		int getNumberOfNodes(void) const;
		void addNodetoCluster(const Node& );
		~Graph();
	private:
		///The center point of a cluster
		Node centroid;
		///Cluster
		vector<Node> node_cluster;
};

#endif
