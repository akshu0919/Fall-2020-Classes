#include <iostream>
#include <queue>
using namespace std;

void insertNames(priority_queue<string>& queue);
void printQueue(priority_queue<string>& queue);

int main()
{

	priority_queue<string> pq;

	insertNames(pq);
	printQueue(pq);	

}

void insertNames(priority_queue<string>& queue)
{	
	queue.push("Alexus");
	queue.push("Nate");
	queue.push("Reilly");
	queue.push("Rodney");
	queue.push("Emily");
	queue.push("Kumar");
	queue.push("Andy");
	queue.push("Sami");
	queue.push("Jacob");
	queue.push("Bryce");
}

void printQueue(priority_queue<string>& queue)
{
	int tempSize = queue.size();

	for(int i = 0; i < tempSize; i++)
	{
		cout <<	queue.top() << endl;
		queue.pop();
	}
}
