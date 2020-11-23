#include <iostream>
using namespace std;
int main(){        
	int num = 3;        
	cout << "Value Contained in num Var :  ";
	cout << num << endl;

        cout << "The Address of My num Var :  ";        
	cout << &num << endl << endl;        

	int *numPtr = &num;
        *numPtr = 6;
        cout << "Value Now in Num Var :  " << num << "\n";

        int *ptr = new int;       
	*ptr = 5;        
	
	cout << "Value My Pointer Variable Points To : ";        cout << *ptr << endl;        
	cout << "Address Contained in Pointer Variable : ";        cout << ptr << endl;   

	return 0;  
}
