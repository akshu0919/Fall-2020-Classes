#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct RecType
{
	int age;
	float weight;
	char gender;
};


int main()
{

	//Steps 1 through 4
	int num = 5;
	int *intPtr = nullptr;
	
	intPtr = &num;
	
	cout << "intPtr points to : " <<  *intPtr * 10 << endl;

	//Steps 5 through 10
	RecType *recPtr = new RecType;

	recPtr -> age = 25;
	recPtr -> weight = 190;
	recPtr -> gender = 'M';

	recPtr -> age += 5;

	cout << "Three Fields Pointed to By recPtr : " << recPtr -> age << " " << recPtr -> weight << " " << recPtr -> gender << endl;

	delete recPtr;
	recPtr = nullptr;

	//Steps 11 through 17
	char *strPtr = new char [50];
	
	strcpy(strPtr, "Operating Systems");

	cout << "strPtr points to : " << strPtr << endl;

	int count = 0;
	for(int i = 0; i < strlen(strPtr); i++)
	{
		cout << (strPtr+i) << endl; //test
		if(islower(*(strPtr+i)) != 0)
		count++;
	}		

	cout << "LowerCase Letters Pointed to by strPtr : " << count << endl;
	
	strPtr = strPtr + 10;
	cout << "Printing strPtr after adding 10 : " << (strPtr) << endl;

	strPtr = (strPtr - 10);	


}
