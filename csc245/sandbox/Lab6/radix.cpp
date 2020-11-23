#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

        int maxElemLength(const vector<int>& v);
        int GetDigit(int number, int k);
        vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
        vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
        void RadixSort(vector<int>& L, int numDigits);
        void PrintVector(const vector<int>& L);


        int main()
        {
                vector<int> vector;
                int array[] = {380,95,345,382,260,100,492};
                cout << "Pre Radix Sort: ";
                for(int i = 0; i < 7; i++)
                {
                        vector.push_back(array[i]);
                        cout << array[i] << " ";
                }

                cout << endl;

                int maxElement = maxElemLength(vector);
                RadixSort(vector, maxElement);

                cout << "Post Radix Sort :";
                PrintVector(vector);


                return 0;
	}


        int maxElemLength(const vector<int>& v)
        {
                int max = v[0];
                for(int i = 0; i < v.size(); i++)
                {
                        if(max < v[i])
                        {
                                max = v[i];
                        }
                }

                if(max < 10)
                        return 1;

                if(max >= 10 && max < 100)
                        return 2;

                if(max >= 100)
                        return 3;
        }

        int GetDigit(int number, int k)
        {

                while(k > 0)
                {
                        number /= 10;
                        k--;
                }

		return number % 10;

        }

        vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
        {
                vector<queue<int> > QA(10);
                for(int i = 0; i < L.size(); i++)
                {
                        int numAtPlace = GetDigit(L[i], k);
                        QA[numAtPlace].push(L[i]);
                }

                return QA;

        }

        vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
        {
                int place = 0;
                vector<int> v(numVals);
                for(int i = 0; i < 10; i++)
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

	void RadixSort(vector<int>& L, int numDigits)
        {
                vector<queue<int> > QA(10);

                for(int i = 0; i < numDigits; i++)
                {

                        QA = ItemsToQueues(L, i);
                        L = QueuesToArray(QA, L.size());
                }
        }

        void PrintVector(const vector<int>& L)
        {
                for(int i = 0; i < L.size(); i++)
                {
                        cout << L[i] << " ";
                }

                cout << endl;
        }

