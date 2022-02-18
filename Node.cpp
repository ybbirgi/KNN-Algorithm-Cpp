#include "Node.h"
#include <iostream>
using namespace std;
int Node::countNodes=0;
///ostream operator overloading
ostream &operator<<(ostream &output,const Node &temp)
{
	output << temp.getID() << "(" << temp.getX() << "," << temp.getY() << ")";
	return output;
}
///Constructor
Node::Node(double xValue,double yValue)
{
	countNodes++;
	//cout << "Node Constructor Called:\nCurrent Number of Nodes:" << getCountNodes() << endl;
}
///Get function to return x
double Node::getX(void) const
{
	return x;
}
///Get function to return y
double Node::getY(void) const
{
	return y;
}
///Get function to return ID 
int Node::getID(void)	const
{
	return ID;
}
///Get function to return number of nodes created.
int Node::getCountNodes(void)
{
	return countNodes;
}
///Set function for x
void Node::setX(double xValue)
{
	x=xValue;
}
///Set function for y
void Node::setY(double yValue)
{
	y=yValue;
}
///Set function for ID
void Node::setID(int num)
{
	ID=num;
	
}
///Operator overloading for +=
Node Node::operator+=(Node const &objNode)
{
	this->setX(this->getX()+objNode.getX());
	this->setY(this->getY()+objNode.getY());
	return *this;//for cascading purposes
}
///Operator overloading for +
Node Node::operator+(Node const &objNode) const
{
	Node temp;
	temp+=objNode;
	return temp;
}
///Operator overloading for -
Node Node::operator-(Node const &objNode) const
{
	Node temp;
	temp.setX(this->getX()-objNode.getX());
	temp.setY(this->getY()-objNode.getY());
	return temp;
}
///Operator overloading for *=
Node Node::operator*=(double x)
{
	this->setX(this->getX()*x);
	this->setY(this->getY()*x);
	return *this;
}
///Operator overloading for *
Node Node::operator*(double x) const
{
	Node temp;
	return (temp*=x);
}
///Operator overloading for /=
Node Node::operator/=(Node const &objNode)
{
	Node temp;
	this->setX(this->getX()/objNode.getX());
	this->setY(this->getY()/objNode.getY());
	return temp;
}
///Operator overloading for /
Node Node::operator/(Node const &objNode) const
{
	Node temp;
	return (temp/=objNode);
}
///Destructor
Node::~Node()
{
	countNodes--;
	//cout << "Node Destructor Called:\nCurrent Number of Nodes:" << getCountNodes() << endl;
}
