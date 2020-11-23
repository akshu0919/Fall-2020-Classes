//Able to take the last character of a string
//We will be using the substr command

#include <iostream>
#include <cstring>
using namespace std;

int main(){

	string str = "Hi my name is Kumar";
	string str1 = "Hello";
	
	cout << str.substr(18, 1) << endl;
	cout << str1.substr(4, 1) << endl;
	cout << str.substr(str.length()-1, 1) << endl;
	cout << str1.substr(str1.length()-1, 1) << endl;
}
