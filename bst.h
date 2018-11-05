//BST.H
#include "stdafx.h"
#pragma once

#ifndef BST_H
#define BST_H 

using namespace std;
class Node
{
	int info;
public:
	Node(int info);
	int getInfo() {
		
		return this->info;
	}
	void setInfo(int value);
	Node *left, *right;
};

class BST
{
	Node *root;
public:
	BST() {
		root = 0;
	}
	
	void insert(int);
	void  search(int);  
	void inorderTraversal(Node* orderNode);
	int leavesCount(Node* root);
	Node* getRoot();
	void promptUser();
	void promptForSearch();
	void deleteNode(int value);
	void RemoveRoot();

};


















#endif