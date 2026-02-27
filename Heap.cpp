#include <cstring>
#include <iostream>
#include <cmath>
#include "Node.h"
#include "fstream"
#include "iterator"
using namespace std;

void add(int value, Node** treeArray){//adds a value
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

void Delete(Node** treeArray, int curIndex){//more like a sorting function, recursively sorts the tree
	int leftVal = 0;
	int rightVal = 0;
	bool foundLeftVal = false;
	bool foundRightVal = false;
	int curVal = treeArray[curIndex]->getValue();
	if (treeArray[curIndex * 2] != NULL){
		leftVal = treeArray[curIndex * 2]->getValue();
		foundLeftVal = true;
	}
	if (treeArray[curIndex * 2 + 1] != NULL){
		rightVal = treeArray[curIndex * 2 + 1]->getValue();
		foundRightVal = true;
	}

	if (foundLeftVal){
		if (!foundRightVal){
			if (leftVal > curVal){
				treeArray[curIndex * 2]->setValue(curVal);//swap values and recursively run function
				treeArray[curIndex]->setValue(leftVal);
				Delete(treeArray, curIndex * 2);
			}
		}
		else{
			if (leftVal > curVal or rightVal > curVal){
				if (leftVal > rightVal){
					treeArray[curIndex * 2]->setValue(curVal); //swap values and recursively run function
					treeArray[curIndex]->setValue(leftVal);
					Delete(treeArray, curIndex * 2);
				}
				else{
					treeArray[curIndex * 2 + 1]->setValue(curVal); //swap values and recursively run function
					treeArray[curIndex]->setValue(rightVal);
					Delete(treeArray, curIndex * 2 + 1);
				}
			}
		}
	}
}

int findLastIndex(Node** treeArray){//gets the last index of the tree
	int searchIndex = 1;
	while (treeArray[searchIndex] != NULL){
		searchIndex++;
	}
	return searchIndex;
}

void DeleteAll(Node** treeArray){//deletes every node in the tree
	while (treeArray[1] != NULL){
		cout << treeArray[1]->getValue() << " ";
		delete treeArray[1]; //delete root
		int lastIndex = findLastIndex(treeArray)-1;
		if (lastIndex != 1){
        		Node* lastNode = treeArray[lastIndex]; //find last node
        		treeArray[1] = lastNode; //insert last node to root position
			treeArray[lastIndex] = NULL;
			Delete(treeArray, 1);
		}
		else{
			treeArray[1] = NULL;
		}
	}
	cout << '\n';
}

void printTree(Node** treeArray, int lastIndex, int currentIndex, int depth){//prints the tree in sideways format
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

int main(){
	Node** tree = new Node*[101];
	for (int i = 0; i < 101; i++){//clears tree
		tree[i] = NULL;
	}
	char addc[] = "ADD";//all the command variables
	char delc[] = "DELETE";
	char delAllc[] = "DELETEALL";
	char quitc[] = "QUIT";
	char printc[] = "PRINT";
	char addfc[] = "ADDF";
	char command[1000];
	bool quitVar = false;
	
	int addValue;

	char addfName[1000];

	int delValue;
	int delIndex;

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
		else if (strcmp(command, delc) == 0){//delete command
			cout << "Delete number: ";
			if (tree[1] != NULL){
				cout << "Root: " << tree[1]->getValue() << endl;
        			Node* lastNode = tree[findLastIndex(tree)-1]; //find last node
        			tree[1] = NULL; //delete root
        			tree[1] = lastNode; //insert last node to root position
				tree[findLastIndex(tree)-1] = NULL;
				Delete(tree, 1); //not really delete, more like rearange tree, but whatever
				cout << "Deleted root!" << endl;
			}
		}
		else if (strcmp(command, delAllc) == 0){ //deleteAll command
			DeleteAll(tree);
		}
		else if (strcmp(command, quitc) == 0){//quit command
			cout << "Quitting program." << endl;
			for (int i = 0; i < 101; i++){//clears the tree
				delete tree[i];
			}
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
		else if (strcmp(command, addfc) == 0){//add file command
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
		else{//if you entered an invalid input:
			cout << "Invalid input." << endl;
		}
	}
	return 0;
}
