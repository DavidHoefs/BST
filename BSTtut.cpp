// BSTtut.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "BST.h"
#include <process.h>
using namespace std;


int main()
{
	BST testBST;
	//testBST.promptUser();
	testBST.insert(3);
	testBST.inorderTraversal(testBST.getRoot());
	testBST.deleteNode(3);

	testBST.inorderTraversal(testBST.getRoot());

	










	system("pause");
    return 0;
}

