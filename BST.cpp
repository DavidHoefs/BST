#include "stdafx.h"
#include "BST.h"
using namespace std;

BST::BST() {
	root = 0;
}
void Node::setInfo(int value) {
	this->info = value;
}
void Node::setLeft(int value) {
	this->left->info = value;

}
void Node::setRight(int value) {
	this->right->info = value;
}
int Node::getLeft() {
	return this->left->info;
}

int Node::getRight() {
	return this->right->info;
}
Node::Node(int info) {
	this->info = info;
	right = 0;
	left = 0;
}
Node::Node() {
	this->info = 0;
	this->right = 0;
	this->left = 0;
}
// insert function for BST
// input: int value, this is the value you want to add to tree
// output: nothing
// Purpose: adds values to BST
void BST::insert(int value) {
	//creating insertNode with user input value
	Node* insertNode = new Node(value);
	//creating a temp node
	Node* temp = new Node(0);
	// if this is the first value, it is the root of the BST
	if (!this->root) {
		this->root = insertNode;
	}
	// Otherwise, if not the root
	else {
		// temp is now equal to root of BST
		Node* temp = this->root;
		// Endless While loop to traverse BST
		while (true) {
			// if the user input value is less than the root value, check if root ->left has a node already, if not insertNode goes there, otherwise loop until open spot
			if (value < temp->getInfo()) {
				if (temp->left != NULL) {
					temp = temp->left;
				}
				else {
					temp->left = insertNode;
					break;
				}
			}
			// if the user input value is greater than the root of BST
			else if (value > temp->getInfo()) {
				if (temp->right != NULL) {
					temp = temp->right;

				}
				else {
					temp->right = insertNode;
					break;
				}
			}
			// if this value is already in the BST, throw exception
			else {
				throw "Duplicates not allowed";
			}
		}
	}
}

Node* BST::getRoot() {
	return this->root;
}
// Search function for BST
// Input: int value, this is the value to search for in the BST
// Output: Nothing
//Purpose: Searches BST for user input value, tells user if it was found or not
void BST::search(int value) {
	// creating searchNode with user input value
	Node* searchNode = new Node(value);
	// if there are no values, throw exception
	if (!this->root) {
		throw "No Values In BST";
	}
	// if the value is the root of the BST, tell user
	if (value == this->root->getInfo()) {
		cout << "Value found, it is the Root" << endl;
	}
	else {
		// creating tempNode
		Node* temp = this->root;
		// infinite while loop to traverse BST
		while (true) {
			// if the value is less than the root, go left
			if (value < temp->getInfo()) {
				searchNode = temp->left;
				temp = temp->left;
				// if we reach the end, we havent found the value, tell user that BST does not contain user input value
				if (searchNode == NULL) {
					cout << "value not found!" << endl;
					break;
				}
				// if we found the value, tell user
				if (value == searchNode->getInfo()) {
					cout << "Value Found" << endl;
					break;
				}

			}
			// if value is greater than root, go right
			// same as previous code, just with searchNode ->right
			else {
				searchNode = temp->right;
				temp = temp->right;
				if (searchNode == NULL) {
					cout << "value not found!" << endl;
					break;
				}
				if (value == searchNode->getInfo()) {
					cout << "Value Found" << endl;
					break;
				}
			}


		}
	}
}
// Function to count number of leaves in BST
// Input: Node* root, this is the pointer that points to the root of the BST
// Output: int value that represents the number of leaves
int BST::leavesCount(Node* root) {
	int numOfLeaves = 0;
	// if there are no values in BST, number of leaves is zero
	if (root == NULL)
		return 0;
	// if the root is the only value, root is only leaf, 
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	// otherwise, recursively call leavesCount function and add together the result of left and right traversals through BST
	else {
		return leavesCount(root->left) + leavesCount(root->right);
	}
}
// Function to print BST in order
// input: Node* orderNode
// output: Nothing
// Purpose: Traverses BST in numeric order
void BST::inorderTraversal(Node* orderNode) {
	// if there are no values, return
	if (orderNode == NULL) {
		return;
	}
	// otherwise, recursively call inorderTraversal() function on left and right sides until you reach the end
	inorderTraversal(orderNode->left);
	cout << orderNode->getInfo() << endl;
	inorderTraversal(orderNode->right);


}
// function to prompt user for values to fill BST
void BST::promptUser() {
	cout << "BINARY SEARCH TREE" << endl;
	cout << "ENTER MIN OF 5 NUMBERS" << endl;
	cout << "----------------------" << endl;
	int input = 0;
	int numOfInputs = 0;
	int choice = NULL;
	bool a = true;
	// infinite loop to fill BST until user is done
	while (a == true) {
		// prompts user to enter num
		cout << "Enter num" << endl;
		cin >> input;
		// calling insert function to add user input value to the BST
		insert(input);
		cout << input << " imported into list" << endl;
		numOfInputs++;
		// if statement to ensure atleast 5 values are entered, then user can choose to continue or keep adding
		if (numOfInputs >= 5) {
			cout << "1 to insert more numbers, 0 to stop input" << endl;
			cin >> choice;
			if (choice == 1) {
				continue;
			}
			if (choice == 0) {
				a = false;
			}
		}
	}




}
// function to prompt user to enter value for search funtion test
void BST::promptForSearch() {
	int searchNum = 0;
	int cont = NULL;
	while (true) {
		cout << "Enter number to check if it is in the tree: " << endl;
		cin >> searchNum;
		BST::search(searchNum);
		cout << "Search Again? Enter 1 to continue, any other number to exit" << endl;
		cin >> cont;
		if (cont != 1) {
			break;
		}

	}

}

void BST::deleteNode(int value) {
	if (root != NULL) {
		if (root->getInfo() == value) {
			cout << root->getInfo() << " delete from root" << endl;
			root = nullptr;
			delete root;

		}
		else 
		{
			Node* deleteNode = root;
			if (value < root->getInfo() && root->left != NULL) {
				if (deleteNode->left->getInfo()==value) {
					deleteNode->left = deleteNode->left->left;

				}
				else {

				}

			}
		}
	}
	else {
		cout << "No Values In Tree!" << endl;
	}
}

bool BST::isLeaf(Node* node) {
	if (node->left == NULL && node->right == NULL)
		return true;
	else
		return false;
}
