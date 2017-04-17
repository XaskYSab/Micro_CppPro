/************************************************************************/
/* create by XaskYSab                                                   */
/************************************************************************/

#include<iostream>
#include "Node.h"
#include <vector>
#include <algorithm>

using namespace std;

struct NodeTree
{
	Node* headNode;

};


void mysort(vector<Node*>& nodes)
{

	int size = nodes.size();

	if (size <= 0)
		return;

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (*nodes[i]>*nodes[i + 1])
			{
				Node *temp = nodes[i];
				nodes[i] = nodes[i + 1];
				nodes[i + 1] = temp;

			}
		}
	}

}

void insertSort(vector<Node*>& nodes, Node* node)
{

	nodes.push_back(node);

	int size = nodes.size();

	Node *tempNode = nodes.at(nodes.size() - 1);

	int i;
	for (i = size - 1 - 1; i >= 0; i--)
	{
		Node *node1 = nodes.at(i);
		if (*node1 > *tempNode)
		{
			nodes.at(i + 1) = node1;
		}
		else
		{
			break;
		}
	}

	nodes[i + 1] = tempNode;

}

void travelTree(const Node* node)
{

	if (node == nullptr)
	{
		cout << "0" << "-->";
		return;

	}

	cout << node->data << "-->";
	travelTree(node->leftNode);
	travelTree(node->rightNode);

}

int main()
{
	int n;
	cin >> n;
	vector<Node*>nodes_vc;

	NodeTree node_tree;


	for (int i = 1; i <= n; i++)
	{

		Node *node = new Node;
		cin >> *node;
		nodes_vc.push_back(node);

	}

	//
	mysort(nodes_vc);

	vector<Node*>myvc = nodes_vc;

	for (unsigned i = 0; i < nodes_vc.size(); i++)
	{
		cout << nodes_vc[i]->data << ",";
	}


	if (nodes_vc.size() <= 1)
		return 1;


	while (nodes_vc.size() > 1)
	{
		Node *node1 = nodes_vc[0];
		Node *node2 = nodes_vc[1];

		Node *node = new Node;
		node->data = node1->data + node2->data;
		node->leftNode = node1;
		node->rightNode = node2;


		node_tree.headNode = node;

		nodes_vc.erase(nodes_vc.begin());
		nodes_vc.erase(nodes_vc.begin());

		insertSort(nodes_vc, node);

	}




	Node *headNode = node_tree.headNode;
	travelTree(headNode);



	for_each(myvc.begin(), myvc.end(), [](Node*node)
	{
		delete node;
	});


	system("pause");


	return 0;
}
