#include <iostream>
using namespace std;

bool valFunc(double *ptr1, double *ptr2)
{
        if(*ptr1 == *ptr2){
                cout << "true" << endl;
		return true;
	}
        else{
                cout << "false" <<endl;
		return false;
	}
}

bool addressFunc(double *ptr1, double *ptr2)
{
	if(ptr1 == ptr2){
		cout << "true" << endl;
		return true;
	}
	else{
		cout << "false" << endl;
		return false;
	}	
}

int main()
{

	double *var1 = new double;
	*var1 = 1.0;
	double *var2 = new double;
	*var2 = 2.0;
	
	valFunc(var1, var2);
	addressFunc(var1, var2);

}
