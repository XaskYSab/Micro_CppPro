#include "Node.h"
#include <iostream>

Node::Node()
{
	leftNode = nullptr;
	rightNode = nullptr;


}


int Node::big(const BaseClass*base) const {
	const Node * node = reinterpret_cast<const Node*>(base);
	return this->data > node->data;
}


int Node::small(const BaseClass*base) const
{
	const Node * node = reinterpret_cast<const Node*>(base);
	return this->data < node->data;
}

istream& operator >> (istream &in, Node &node){

	cin >> node.data;

	return in;
}