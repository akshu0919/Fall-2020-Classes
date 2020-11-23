#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{

	BinaryHeap<char> PQ (50);

	for(char ch = 'A'; ch <= 'J'; ch++)
	{
		PQ.insert(ch);
	}

	PQ.deleteMin();
	cout << "Printing Left subtree of Root of the Heap: ";
	PQ.printLtSubtree();
	cout << endl;

	cout << "Printing the leaves : ";
	PQ.PrintLeaves();
	cout << endl;

	cout << "The height of our Heap is: " << PQ.Height() << endl;
	cout << "The maximum value in our Heap is: " << PQ.findMax() << endl;

}
