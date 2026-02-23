#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
using namespace std;

class Node{
	public:
		Node(int);
		~Node();
		Node* getRight();
		Node* getLeft();
		void setRight(Node*);
		void setLeft(Node*);
		int getValue();
		void setValue(int);
	private:
		int value;
		Node* right;
		Node* left;
};
#endif
