#pragma once
#ifndef BST_H
#define BST_H
#include "stdafx.h"
#include <iostream>
using namespace std;
class Node {
	int info;
	
public:
	Node(int info);
	Node();
	int getInfo() {
		return this->info;
	}
Node* left;
	Node * right;
	void setInfo(int value);
	void setRight(int value);
	void setLeft(int value);
	int getRight();
	int getLeft();
};
class BST {
private:
	Node * root;
	int sizeOfTree;

public:
	BST();
	// ~BST();
	void insert(int);
	void  search(int);
	void inorderTraversal(Node* orderNode);
	int leavesCount(Node* root);
	Node* getRoot();
	void promptUser();
	void promptForSearch();
	void deleteNode(int value);
	bool isLeaf(Node* node);
};


























#endif
