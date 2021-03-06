// main.cpp : Defines the entry point for the console application.
//

//
#include "stdafx.h"
#include "bst.h"
#include <process.h>
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	// Declaring BST
	BST testBST = BST();
	// prompting user function 
	testBST.promptUser();
	//srand(5);
	// added to fill BST with rand values to test speed with multiple inputs
	//for (int i = 0; i <250; i++) {
	//	testBST.insert(rand());
	//}
	
	// Tell user the number of leaves in BST
	 int numOfLeaves = testBST.leavesCount(testBST.getRoot());
	 cout <<"Number of Leaves: "<< numOfLeaves << endl;
	 cout << "Inorder Traversal" << endl;
	 // Tests inorderTraversal() function
	 testBST.inorderTraversal(testBST.getRoot());
	 // tests search function, calls prompt for search function which will call the search funtion according to user input
	 // testBST.promptForSearch();
	 testBST.deleteNode(3);
	 testBST.inorderTraversal(testBST.getRoot());
	
	
	
	
	
	system("pause");
	return 0;
}

