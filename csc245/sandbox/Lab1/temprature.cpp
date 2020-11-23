#include <iostream>
using namespace std;

double convert(double value);

int main(){
	double celsius;

	cout << "Please enter a Celsius Value: " << endl;
	cin >> celsius;

	cout << celsius << " degrees celsius is " << convert(celsius) << " degrees Farenheit." << endl;
}
double convert (double tmp){
	int farenheit;
	farenheit = (tmp * 1.8)+32;

	return farenheit;
}
