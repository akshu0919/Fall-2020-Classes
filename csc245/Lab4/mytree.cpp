#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
	BinarySearchTree<int> T(0);
	
	T.insert(6);
	T.insert(8);
	T.insert(2);
	T.insert(4);
	T.insert(3);
	T.insert(1);
	T.insert(9);
	
	T.postOrder();
	cout << endl;
	T.height();
	cout << endl;
	T.numLeaves();
	cout << endl;
	T.isBalanced();
}
