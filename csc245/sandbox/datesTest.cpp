#include <iostream>
using namespace std;

int main()
{
	string date;
	string first;
	string middle;
	string last;

	cout << "What's the date? " << endl;
	cin >> date;

	first = date.substr(0, date.find("/"));
	middle = date.substr(date.find("/")+1, 2);
	last = date.substr(date.find("/")+4, 4);	
	cout << first << " " << middle << " " << last << endl;
}
