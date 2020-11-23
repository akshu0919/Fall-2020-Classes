#include <cstddef> 
#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
	makeEmpty();
}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
	NodeType<ItemType>* tempNode = new NodeType<ItemType>;
	tempNode = head;

	if(tempNode == NULL)
	{
		head = NULL;
		delete tempNode;
	}
	else if(tempNode -> next == NULL && tempNode -> back == NULL)
	{
		head == NULL;
		delete tempNode;
	}
	else
	{
		while(tempNode -> next != NULL)
		{
			tempNode = tempNode -> next;
		}
		if(tempNode -> next == NULL && tempNode -> back != NULL)
		{
			tempNode -> back -> next == NULL;
		}
		head == NULL;
		delete tempNode;
	}
}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 

	deleteLocation(location(item));

}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 

	NodeType<ItemType>* tempNode = new NodeType<ItemType>;
	tempNode = head;

	while(tempNode != NULL)
	{
		if(tempNode -> info == item)
			return true;
		else
			tempNode = tempNode -> next;
	}

	tempNode == NULL;
        delete tempNode;

	return false;
}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
	
	if(head == NULL)
		return true;
	else
		return false;	
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
	NodeType<ItemType>* tempNode = new NodeType<ItemType>;
	tempNode = head;

	cout << "Your current list is: " << endl;
	
	while(tempNode != NULL)
	{
		cout << tempNode -> info << " ";
		tempNode = tempNode -> next;
	}
	cout << endl;

}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 

	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode -> info = item;
	newNode -> back = NULL;

	if(head != NULL)
	{
		head -> back = newNode;
		newNode -> next = head;
	}
	else
	{
		newNode -> next = NULL;
	}

	head = newNode;
	length++;
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 

	NodeType<ItemType>* tempNode = new NodeType<ItemType>;
	tempNode = head;
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode -> info = item;
	newNode -> next = NULL;
	
	if(tempNode != NULL)
	{
		while(tempNode -> next != NULL)
        	{
                	tempNode = tempNode -> next;
        	}
	
		if(tempNode -> next == NULL)
        	{
                	tempNode -> next = newNode;
                	newNode -> back = tempNode;
			length++;
        	}
	}
	else
	{
		newNode -> back = NULL;
		head = newNode;
		length++;
	}
	
	tempNode = NULL;
	delete tempNode;
	
}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  

	return length;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
	
	NodeType<ItemType>* tempNode = new NodeType<ItemType>;
	tempNode = head;

	while(tempNode != NULL)
	{
		if(tempNode -> info == item)
			return tempNode;
		else
			tempNode = tempNode -> next;
	}	
	
	tempNode = NULL;
	delete tempNode;

	return NULL;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
	NodeType<ItemType>* tempNode = new NodeType<ItemType>;
        tempNode = head;

	while(tempNode -> next != NULL)
	{
		tempNode = tempNode -> next;
	}

	return tempNode;

	tempNode = NULL;
	delete tempNode;
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exists in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List

	if(delPtr -> next == NULL && delPtr -> back == NULL)
	{
		head = NULL;
	}
	else if(delPtr -> back == NULL)
	{
		delPtr -> next -> back = NULL;
		head = delPtr -> next;
	}
	else if(delPtr -> next == NULL)
	{
		delPtr -> back -> next = NULL;		
	}
	else
	{
		delPtr -> back -> next = delPtr -> next;
		delPtr -> next -> back = delPtr -> back;
	}

	delete delPtr;
	length--;
}
