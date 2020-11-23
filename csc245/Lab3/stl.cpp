#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void Initialize(vector<int> &v);
void Print(vector<int> &v);
void Reverse(vector<int> &v);

int main()
{
	stack<string> s1, s2;

	s1.push("Hi there");

	s2.push("Bye! Bye! Bye! Bye!");

	if(s1 == s2)
	{
		cout << "They are Equal!" << endl;
	}
	else if(s1 < s2)
	{
		cout << "s1 is less than s2" << endl;
	}
	else if(s2 < s1)
	{
		cout << "s2 is less than s1" << endl;
	}

	vector<int> v;
	
	cout << endl;
	Initialize(v);
	cout << endl;
	cout << "Your 5 intgers printed: " << endl;
	Print(v);
	cout << endl;

	Reverse(v);
	cout << endl;
	cout << "Your 5 integers reversed: " << endl;
	Print(v);
	cout << endl;
	
	sort(v.begin(), v.end());
	cout << "Your 5 integers printed after being sorted: " << endl;
	Print(v);
}

void Initialize(vector<int> &v)
{
        int a;
        for(int i = 0; i < 5; i++)
	{
		cout << "Enter your integer: " << endl;
		cin >> a;
		v.push_back(a);
	}
}

void Reverse(vector<int> &v)
{
	vector<int> vReversed;
	for(int i = 4; i >= 0; i--)
	{
		vReversed.push_back(v.at(i));
	}

	v = vReversed;
}

void Print(vector<int> &v)
{
	for(int i = 0; i < 5; i++)
	{
		cout << v.at(i) << endl;
	}
}
