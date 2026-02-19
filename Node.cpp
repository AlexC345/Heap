#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;

Node::Node(int inputValue){
	value = inputValue;
	right = NULL;
	left = NULL;
}

Node::~Node(){}

Node* Node::getRight(){
	return right;
}

Node* Node::getLeft(){
	return left;
}

void Node::setRight(Node* input){
	right = input;
}

void Node::setLeft(Node* input){
	left = input;
}

int Node::getValue(){
	return value;
}
