#include <iostream>
using namespace std;
#include "dlist.h"

void HeadInsert(DList<int>& list);
void TailInsert(DList<int>& list);
void AccessItem(DList<int>& list);
void Delete(DList<int>& list);
void PrintList(const DList<int>& list);
void PrintLength(const DList<int>& list);
char PrintMenu(char& sel);
void FindandMove(DList<int>& list, int& item);

int main()
{
	DList<int> list;
	char sel;

	do
	{
		PrintMenu (sel);
		switch (toupper(sel))
		{
			case 'H' :   HeadInsert(list);  break;
			case 'T' :   TailInsert(list);  break;
			case 'A' :   AccessItem(list);  break;
			case 'D' :   Delete(list);  break;
			case 'P' :   PrintList(list); break;
			case 'L' :   PrintLength(list); break;
			case 'Q' :   cout << "\tExiting Program...\n"; break;
			default  :   cout << "\tError.  Try Again." << endl;
		}
	} while (toupper(sel) != 'Q');

	

	return 0;
}

void HeadInsert (DList<int>& list)
{
	int item;
	
	cout << "\v\tItem to be Inserted Onto Head of List : ";
	cin >> item;
	
	if (list.inList(item) == false)
		list.insertHead(item);
	else
    		cout << "\t Item Already Exists in List. No Duplicates Allowed." << endl;
}

void PrintLength(const DList<int>& list)
{
	cout << "The length of the list is: " << list.lengthIs() << endl;	
}

char PrintMenu(char& sel)
{
	char input;

	cout << "********************************" << endl;
	cout << "**************Menu**************" << endl;
	cout << "********************************" << endl;
	cout << "*                              *" << endl;
	cout << "* H: Insert item at front      *" << endl;
	cout << "* T: Insert item at back       *" << endl;
	cout << "* A: Access an item in list    *" << endl;
	cout << "* D: Delete an item in list    *" << endl;
	cout << "* P: Print the list            *" << endl;
	cout << "* L: Print the list's length   *" << endl;
	cout << "* Q: Quit the program          *" << endl;
	cout << "*                              *" << endl;
	cout << "********************************" << endl;
	cout << "*                              *" << endl;
	cout << "* Please enter your choice:    *" << endl;
	cout << "*                              *" << endl;
	
	cin >> input;
	sel = input;

	return sel;
}

void PrintList(const DList<int>& list)
{
	if(list.isEmpty() == true)
		cout << "List is Empty!" << endl;
	else
		list.print();
}

void TailInsert(DList<int>& list)
{
	int item;

        cout << "\v\tItem to be Inserted Onto Head of List : ";
        cin >> item;

	if (list.inList(item) == false)
		list.appendTail(item);
	else
		cout << "\t Item Already Exists in List. No Duplicates Allowed." << endl;

}

void Delete(DList<int>& list)
{
	int item;

	if(list.lengthIs() == 0)
		cout << "The list is empty" << endl;
	else
	{
		cout << "\v\tItem to be Deleted: " ;
		cin >> item;	
	
		if(list.inList(item) == false)
			cout << "That item is not in the list" << endl;
		else
			list.deleteItem(item);
	}
}

void AccessItem(DList<int>& list)
{
	int item;
	
	if(list.lengthIs() == 0)
		cout << "List is empty!" << endl;
	else
	{
        	cout << "\v\tItem to be moved to front: ";
        	cin >> item;
		FindandMove(list, item);
	}
}


void FindandMove(DList<int>& list, int& item)
{
	if(list.inList(item) == true)
        {
                list.deleteItem(item);
                list.insertHead(item);
        }
        else
                cout <<"Item is not in list!"<< endl;

}
