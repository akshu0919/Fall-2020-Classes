#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

	int maxElemLength(const vector<string>& v);
	char GetChar(string word, int position);
	vector<queue<string> > ItemsToQueues(const vector<string>& vec, char letter);
	vector<string> QueuesToArray(vector<queue<string> >& QA, int letterCount);
	void RadixSort(vector<string>& vec, int charCount);
	void PrintVector(const vector<string>& vec);
	void padString(vector<string>& v, int maxLength);
	void unPadString(vector<string> &v, int maxLength);	


	int main()
	{
		vector<string> vec;
		string array[]= {"zebra", "apple", "orange", "can", "candy", "a", "top", "pumpkin", "today", "parade"};
		cout << "Pre Radix Sort: ";
		for(int i = 0; i < 10; i++)
		{
			vec.push_back(array[i]);
			cout << array[i] << " ";
		}
		
		cout << endl;
	
		int charCount = maxElemLength(vec);
		
		padString(vec, charCount);	
		RadixSort(vec, charCount);
		unPadString(vec, charCount);

		cout << "Post Radix Sort :";
		PrintVector(vec);
	

		return 0;
	}
	
	int maxElemLength(const vector<string>& v)
	{
		int max = v[0].length();
		for(int i = 0; i < v.size(); i++)
		{
			if(max < v[i].length())
			{
				max = v[i].length();
			}
		}	
		
		return max;
	}
	
	void padString(vector<string>& v, int maxLength)
	{
		for(int i = 0; i < v.size(); i++)
		{
			if(v[i].length() < maxLength)
			{
				int pad = maxLength - v[i].length();
				for (int j = 0; j < pad; j++)
				{
					v[i] = v[i] + " ";
				}
			}
		}	
	}

	void unPadString(vector<string>&v, int maxLength)
	{
		for(int i = 0; i < v.size(); i++)
		{
			string temp = v[i].substr(0, v[i].find(" "));
			v[i] = temp;
		}
	}
	
	char GetChar(string word, int position)
	{
		char letter = word[position];
		return letter;
	
	}
	
	vector<queue<string> > ItemsToQueues(const vector<string>& vec, int j)
	{
		vector<queue<string> > QA(128);
		for(int i = 0; i < vec.size(); i++)
		{
			char charPos = GetChar(vec[i], j);
      			int pos = (int) charPos;
			QA[pos].push(vec[i]);
		}
	
		return QA;
	}
	
	vector<string> QueuesToArray(vector<queue<string> >& QA, int letterCount)
	{
		int place = 0;
		vector<string> v(letterCount);
		for(int i = 0; i < 128; i++)
		{
			while(!QA[i].empty())
			{
				v[place] = QA[i].front();
				QA[i].pop(); 
				place++;				
			}
		}
	
		return v;
	}
	
	void RadixSort(vector<string>& vec, int charCount)
	{
		vector<queue<string> > QA(128);
		for(int i = charCount; i >= 0; i--)
		{
			QA = ItemsToQueues(vec, i);
			vec = QueuesToArray(QA, vec.size()); 
		}
	}


	void PrintVector(const vector<string>& vec)
	{
		for(int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " "; 
		}
		cout << endl;
	}
	
