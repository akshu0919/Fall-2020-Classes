#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int b = 10;
	int *ptr = &b;
	int &ref = *ptr;

	cout << ptr << " " << *ptr << endl;
	cout << ref << " " << &ref << endl;
}
