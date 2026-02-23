#include <cstring>
#include <iostream>
#include <cmath>
#include "Node.h"
#include "fstream"
using namespace std;

void add(int value, Node** treeArray){
	//adding newNode to next available index
	Node *newNode = new Node(value);
	if (treeArray[1] == NULL){ //root is empty case
		treeArray[1] = newNode;
	}
	else{
		/* //FOR ADDING FROM RIGHT TO LEFT
		int searchIndex = 1;
		while (treeArray[searchIndex] != NULL){
			searchIndex = (searchIndex*4)-1;
			int numOfChecks = (int)floor(searchIndex/2);
			while (numOfChecks > 0 and treeArray[searchIndex] != NULL){ //check from right to left, while you still have checks left:
				searchIndex--; //check from right to left
				numOfChecks--;
			}//if numOfChecks = 0, that means we move onto next layer
		}
		treeArray[searchIndex] = newNode;//sets next available index to newNode
		*/
		//adding new node;
		int searchIndex = 1;
		while (treeArray[searchIndex] != NULL){//find next available index
			searchIndex++;
		}
		treeArray[searchIndex] = newNode;

		int newNodeIndex = searchIndex;
		int newNodeValue = newNode->getValue();
		//sorting newNode
		
		while(newNodeIndex != 1 and newNodeValue > treeArray[(int)floor(newNodeIndex/2)]->getValue()){
		//if (newNodeValue > treeArray[floor(newNodeIndex/2)]->getValue()){//if addedNode value is greater than the parent node value:
			int parentValue = treeArray[(int)floor(newNodeIndex/2)]->getValue();
			treeArray[newNodeIndex]->setValue(parentValue);
			treeArray[(int)floor(newNodeIndex/2)]->setValue(newNodeValue); //swap values
			
			newNodeIndex = (int)floor(newNodeIndex/2);
		}
		
	}
}

void Delete(Node** treeArray);
void DeleteAll(Node** treeArray);

void printTree(Node** treeArray, int lastIndex, int currentIndex, int depth){
	if ((currentIndex * 2) + 1 < lastIndex){
		printTree(treeArray, lastIndex, (currentIndex * 2) + 1, depth + 1); //right recursion
	}
	for (int i = 0; i < depth; i++){ //print tabs
		cout << '\t';
	}
	if (treeArray[currentIndex] != NULL){
		cout << treeArray[currentIndex]->getValue() << endl;
	}
	if ((currentIndex * 2) < lastIndex){
		printTree(treeArray, lastIndex, (currentIndex * 2), depth + 1); //left recursion
	}
}

int findLastIndex(Node** treeArray){
	int searchIndex = 1;
	while (treeArray[searchIndex] != NULL){
		searchIndex++;
	}
	return searchIndex;
}

int main(){
	Node** tree = new Node*[101];
	for (int i = 0; i < 101; i++){
		tree[i] = NULL;
	}
	char addc[] = "ADD";
	char delc[] = "DELETE";
	char delAllc[] = "DELETEALL";
	char quitc[] = "QUIT";
	char printc[] = "PRINT";
	char addfc[] = "ADDF";
	char command[1000];
	bool quitVar = false;
	
	int addValue;

	char addfName[1000];

	while(!quitVar){
		cout << "Enter a command: (ADD, DELETE, DELETEALL, QUIT, PRINT, ADDF) ";
		cin >> command;
		command[9] = '\0';

		if (strcmp(command, addc) == 0){//add command
			cout << "Add number: ";
			cin >> addValue;
			add(addValue, tree);
			cout << "Added number!" << endl;
		}
		else if (strcmp(command, delc) == 0){
			//del
		}
		else if (strcmp(command, delAllc) == 0){
			//delAll
		}
		else if (strcmp(command, quitc) == 0){
			cout << "Quitting program." << endl;
			quitVar = true;
		}
		else if (strcmp(command, printc) == 0){//print command
			/*
			for (int i = 1; i < 101; i++){
				if (tree[i] != NULL){
					cout << "I: " << i << " V: " << tree[i]->getValue() << endl;
				}
			}
			*/
			printTree(tree, findLastIndex(tree), 1, 0);	
		}
		else if (strcmp(command, addfc) == 0){
			cout << "Enter file name: (include the .txt) ";
			cin >> addfName;

			ifstream numFile(addfName);
			if (!numFile){
				cout << "Invalid file name!" << endl;
			}
			else{
				int number;
				while (numFile >> number){
					add(number, tree);
				}
				numFile.close();
				cout << "Added numbers!" << endl;
			}
		}
		else{
			cout << "Invalid input." << endl;
		}
	}
	return 0;
}
