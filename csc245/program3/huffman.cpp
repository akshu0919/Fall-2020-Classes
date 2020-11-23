#include "huffman.h"
#include <iostream>
#include <climits>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, 0, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}

bool HuffmanTree:: inTree(char ch) {
	bool in = false;

	for(int i = 0; i < numChars; i++)
	{
		if(nodes[i].ch == ch)
		{
			in = true;
		}
	}

	return in;
}

int HuffmanTree:: GetFrequency(char ch) {

	int loc = lookUp(ch);
	GetFrequency(loc);

}

int HuffmanTree:: GetFrequency(int i) {

	return nodes[i].weight;

}

int HuffmanTree:: lookUp(char ch) {

	int loc = -1;

	if(inTree(ch))
	{
		for(int i = 0; i < numChars; i++)
		{
			if(nodes[i].ch == ch)
			{
				loc = i;
			}
		}
	}

	return loc;

}

string HuffmanTree:: GetCode(char ch) {

	int loc = lookUp(ch);
	return GetCode(loc);

}


string HuffmanTree:: GetCode(int i) {

	if(nodes[i].parent == 0)
	{
		return "";
	}
	else
		return (GetCode(nodes[i].parent) + (char)(nodes[i].childType + '0'));
}

void HuffmanTree:: PrintTable() {

	cout << "\t" << "++++	Encoding Table	++++" << endl;
	cout << "Index" << "\t" << "Char" << "\t" << "Weight" << "\t" << "Parent" << "\t" << "ChildType" << endl;

	int count = 1;
	for(int i = 0; i < numChars; i++)
	{
		if(nodes[i].ch == '\0')
		{
			cout << i << "\t" << "T" << count++ << "\t" << nodes[i].weight << "\t"
				<< nodes[i].parent << "\t" << nodes[i].childType << endl;
		}
		else if(nodes[i].ch == '\n')
		{
			cout << i << "\t" << "nl" << "\t" << nodes[i].weight << "\t"  
				<< nodes[i].parent << "\t" << nodes[i].childType << endl;
		}
		else if(nodes[i].ch == ' ')
		{
			cout << i << "\t" << "sp" << "\t" << nodes[i].weight << "\t"
                                << nodes[i].parent << "\t" << nodes[i].childType << endl;
		}
		else
		{
			cout << i << "\t" << nodes[i].ch << "\t" << nodes[i].weight << "\t"
                                << nodes[i].parent << "\t" << nodes[i].childType << endl;
		}	
	}	
}

int HuffmanTree:: numNodes() {

	return numChars;	

}

void HuffmanTree:: build() {
		
	int exit = (2 * numChars) - 1;
	int min, min2;
		
	while(numChars < exit)
	{
		int small;
		small = INT_MAX;
	
		for(int i = 0; i < numChars; i++)
		{
			if((nodes[i].parent == 0) && (nodes[i].weight < small))
			{
				min = i;
				small = nodes[i].weight;
			}
		}

		small = INT_MAX;
		
		for(int j = 0; j < numChars; j++)
		{
			if((nodes[j].parent == 0) && (nodes[j].weight < small)  && (j != min) )
			{
		  		min2 = j;
				small = nodes[j].weight;
			}
		}
		
		HNode total = {'\0', (nodes[min].weight + nodes[min2].weight), 0, -1};
		nodes.push_back(total);

		nodes[min].parent = numChars;
	  	nodes[min2].parent = numChars;

		nodes[min].childType = 0;
	  	nodes[min2].childType =1;

		numChars++;
	}

	built = true;
}

char HuffmanTree:: getChar(int index) {
		
	return nodes[index].ch;

}
