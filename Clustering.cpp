#include "Clustering.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
///Constructor
Clustering::Clustering()
{
}
///Reading data from txt file
/**
*In the following function Nodes are getting created for each given coordinate and they are getting stored in a vector.
*@param k is used to determine which part of the cell is x and y.
*@param id is used to give identities to created Nodes.
*/
void Clustering::readDataFromTXT(const string& fileName)
{
    ifstream data(fileName);
    string line;
    int k=0;
    int id=1;
    while (getline(data, line)) {
    	Node temp;
    	temp.setID(id);
        stringstream lineStream(line);
        string cell;
        while (getline(lineStream, cell, ' ')) {
        	if(k==1)
        		temp.setY(stod(cell));
        	else
            	temp.setX(stod(cell));
            k++;
        }
        k=0;
        nodes.push_back(temp);
        id++;
    }
    shiftedPoints=nodes;
}
///Print Function
void Clustering::print(void) const
{
	for(auto it=nodes.begin();it!=nodes.end();it++){
		cout << "\n" << *it;
	}
}
/**
*In this function the Clusters are getting created.
*If the nodes are in the distance value they are getting stored in the same vector.
*Otherwise a new Cluster is getting created.
*/
///In this function the Clusters are getting created.
void Clustering::buildClusters(void)
{
    for (int i = 0; i < nodes.size(); ++i) {
        vector<Graph>::iterator iter = clusters.begin();
        vector<Graph>::iterator iterEnd = clusters.end();
        while(iter != clusters.end()){
        	Edge temp(iter->getCentroid(),shiftedPoints[i]);
            if (temp.euclideanDistance() <= clusterEps){
                iter->computeCentroid(shiftedPoints[i]);
                iter->addNodetoCluster(nodes[i]);
                break;
            }
            iter++;
        }
        if(iter == iterEnd){
            Graph newCluster(shiftedPoints[i]);
            newCluster.addNodetoCluster(nodes[i]);
            clusters.push_back(newCluster);
        }
    }
}
///The function that returns the number of clusters.
int Clustering::getNumberofClusters(void)
{
	return clusters.size();
}
///The function that returns the clusters
vector<Graph> Clustering::getClusters(void) const 
{
    return clusters;
}
///Destructor
Clustering::~Clustering()
{
}
