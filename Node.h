#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node
{
	friend ostream &operator<<(ostream&,const Node&);
	public:
		Node(double xValue=0.0,double yValue=0.0);
		double getX(void) const;
		double getY(void) const;
		static int getCountNodes(void);
		int getID(void)	const;
		void setX(double);
		void setY(double);
		void setID(int);
		Node operator+(Node const &objNode) const;
		Node operator+=(Node const &objNode);
		Node operator-(Node const &objNode) const;
		Node operator*(double x) const;
		Node operator*=(double x);
		Node operator/(Node const &objNode) const;
		Node operator/=(Node const &objNode);
		~Node();
	private:
		///X coordinate
		double x;
		///Y coordinate
		double y;
		///Identity of Node
		int ID;
		///Count of Created Nodes
		static int countNodes;
};

#endif
