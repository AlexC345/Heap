#include <cstring>
#include <iostream>
#include <cmath>
#include "Node.h"
using namespace std;

void add(int value, Node** treeArray){
	//adding newNode to next available index
	Node *newNode = new Node(value);
	if (treeArray[1] = NULL){ //root is empty case
		treeArray[1] = newNode;
	}
	else{
		int searchIndex = 1;
		while (treeArray[searchIndex] != NULL){
			searchIndex = (searchIndex*4)-1;
			int numOfChecks = floor(searchIndex/2);
			while (numOfChecks > 0){ //check from right to left, while you still have checks left:
				searchIndex--; //check from right to left
				numOfChecks--;
			}//if numOfChecks = 0, that means we move onto next layer
		}
		treeArray[searchIndex] = newNode;//sets next available index to newNode
	}
	int newNodeIndex = searchIndex;
	int newNodeValue = newNode->getValue();
	//sorting newNode
	if (newNodeValue > treeArray[floor(newNodeIndex/2)]->getValue()){//if addedNode value is greater than the parent node value:
		int parentValue = treeArray[floor(newNodeIndex/2)]->getValue();
		treeArray[newNodeIndex] = parentValue;
		treeArray[floor(newNodeIndex/2)] = newNodeValue; //swap values
	}
}

void Delete(Node** treeArray);
void DeleteAll(Node** treeArray);

int main(){
	Node* tree = new Node*[101];
	for (int i = 0; i < 101; i++){
		tree[i] = NULL;
	}
	char add[] = "ADD";
	char del[] = "DELETE";
	char delAll[] = "DELETEALL";
	char quit[] = "QUIT";
	char command[1000];
	bool quitVar = false;
	
	

	while(!quitVar){
		cout << "Enter a command: (ADD, DELETE, DELETEALL, QUIT) ";
		cin >> command;
		command[9] = '\0';

		if (strcmp(command, add) == 0){
			//add
		}
		else if (strcmp(command, del) == 0){
			//del
		}
		else if (strcmp(command, dellAll) == 0){
			//delAll
		}
		else if (strcmp(command, quit) == 0){
			cout << "Quitting program." << endl;
			quitVar = true;
		}
		else{
			cout << "Invalid input." << endl;
		}
	}
	return 0;
}
