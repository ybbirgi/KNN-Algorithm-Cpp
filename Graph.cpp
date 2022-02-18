#include "Graph.h"
///Assigning the first coming node as the center of the cluster
Graph::Graph(Node& first_node):
	centroid(first_node)
{
	//cout << "A new Cluster has created" << endl;
}
///Get function that returns the center point of the cluster
Node Graph::getCentroid(void) const
{
	return centroid;
}
///A function to add a node to a cluster
void Graph::addNodetoCluster(const Node& n)
{
	node_cluster.push_back(n);
}
///The function that calculates the center point of the cluster
void Graph::computeCentroid(const Node& n)
{
	double sumX=0;
	double sumY=0;
	for(auto it=node_cluster.begin();it!=node_cluster.end();it++){
		sumX+=it->getX();
		sumY+=it->getY();
	}
	sumX+=n.getX();
	sumY+=n.getY();
	centroid.setX(sumX/(this->getNumberOfNodes())+1);
	centroid.setY(sumY/(this->getNumberOfNodes())+1);
}
///Get function that returns the size of cluster
int Graph::getNumberOfNodes(void) const
{
	return node_cluster.size();
}
///Destructor
Graph::~Graph()
{
	//cout << "The Cluster has destroyed" << endl;
}
