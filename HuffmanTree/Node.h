#pragma once
#include <iostream>
#include "BaseClass.h"
using namespace std;

class Node :public BaseClass
{
public:
	Node();

	friend istream& operator >> (istream &in, Node &node);

	Node(const Node& node) = delete;

	virtual int big(const BaseClass*base) const override;

	virtual int small(const BaseClass*base) const override;

public:
	const Node*leftNode;
	const Node*rightNode;
	int data;
};

