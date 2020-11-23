1. The attricutes of DList class and why templates are being used.
Answer -> The DList class has many public operation that are usable by the client that were written in the implementation file (dlist.cpp) such as makeEmpty(), inList(), insertHead(), and many more that are used in the methods of the client file to achieve the goal of the method such as adding to the head or tail of the list. The template was used so that if the same project needed to be done with characters instead of integers then a list can be made with characters instead of integers as well. The template allows us to be flexible.


2. A description of each of the operations of the DList class.
Answer -> 
isEmpty: This will look through the list and tell us if it is empty or not. Basically if the head is NULL that means the list is empty;

inList: This will look at the item that you pass in and try to find it in the list and it will tell you if the item exists in the list or not.

makeEmpty: This is used in the destructor. If the list is empty then it will just keep the head NULL. If the the list has more than one value then it will set them null from the tail to the head until theres only one and then set head to null as well.

insertHead: It will find where the head is and insert a value in front of that head and then it will set the area behind that new node to null and the value that was previously the head becomes the newNode -> next. Then the newNode is also set to be the head.

appendTail: It will find the end of the linked list and create a new node there. It will set the newnode -> back the the node that was previosuly there and set the previous node's -> next to be the newNode. It will also set the neNode's -> next to NULL since it is the end/tail of the list.

print: It will print all of the values that are in the list.

lengthIs: It will return the number of items that exist in the length at the time that the method is used.

deleteItem: It takes the location that is passed through and goes to it and deletes the item at that location. Which in turn rremoves that item from the list.

last: Returns the location of the last item in the list.

location: Takes the item that is passed in and finds the address of that item.

deleteLocation: Takes in an adress and deletes the item that is at that address.


3. The role of the Move and Find algorithm.
Answer -> It ensures that the item that needs to be moved is actually in the list and if its not then the access method is stopped. Also, if the item does exist then it does the finding.


4. A description of the main algorithm followed by the client program.
Answer -> The main algorithm uses a switch that will keep going until a q is entered as a choice. Each character in the switch allows for a different action to take place. H will add to the head, T will add to the tail, P will print the list, L will return the length os the list, A will take the item that is entered and move it to the front of the list. Q will quit the program and deallocate the memory that was being used. The client program has methods that use the methods made in the implementation file to achieve their goals of adding to the head, tail, and etc.
