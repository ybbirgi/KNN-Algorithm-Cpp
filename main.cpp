#include <iostream>
#include <vector>
#include "Node.h"
#include "Clustering.h"
#include "MeanShift.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	MeanShift a;
	a.readDataFromTXT("20.txt");
	a.print();
	a.meanShift(16050.0);
	a.buildClusters();
	cout << "Number of clusters: " << a.getClusters().size() << endl;
	return 0;
}

