using namespace std;
#include "huffman.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>

void OpenFile(ifstream& infile, int argc, char *argv[], char* filename);
void compressFile(ofstream& outfile, int totalChar, HuffmanTree& H, char* filename, string& str);
void readFile(ifstream& infile, HuffmanTree& H, int letters[], string& str);
void makeTree(HuffmanTree& H, int letters[], int& totalChar);

int main(int argc, char *argv[])
{
	HuffmanTree H;
	ifstream infile;
	ofstream outfile;

	int letters[256];		
	int totalChar = 0;
	char* filename = argv[argc-1];
	string str = "";

	OpenFile(infile, argc, argv, filename);		
	readFile(infile, H, letters, str);
	makeTree(H, letters, totalChar);
	compressFile(outfile, totalChar, H, filename, str);

	return 0;
}

void OpenFile (ifstream& infile, int argc, char *argv[], char* filename)
{
        if(argc == 1)
        {
                cout << "Error!! No File Entered." << endl;
                exit(1);
        }
	if(!filename)
	{
		cout<< "File does not exist." << endl;
		exit(1);
	}

        string file = (string) filename;
        infile.open(file.c_str());
}
  
void compressFile(ofstream& outfile, int totalChar, HuffmanTree& H, char* filename, string& str)
{
	
	string line= "";
	line += filename;
        line +=".zip";
        outfile.open(line.c_str());
	
	outfile << totalChar << endl;
	char ch;

	for(char ch = char(1); ch <= char(126); ch++)
	{
		bool inTree = H.inTree(ch);
		if(inTree)
		{
			int ascii = (int) ch;
			outfile << ascii << " " << H.GetCode(ch) << endl;
		}
	}

	string end = "";

	for(int i = 0; i < str.length(); i++)
	{
		end += H.GetCode(str[i]);	
	}

	outfile << end << endl;

	double Bits = (double) end.length();
	double chars = (double) totalChar * 8.0;
	double ratio = (1 - (Bits / chars)) * 100;

	cout << "File Successfully Compressed to " << end.length() 
		<< " Bits ("<< setprecision(4)  << fabs(ratio) << "%)" << endl;
}

void readFile(ifstream& infile, HuffmanTree& H, int letters[], string& str)
{
	char ch;

	for(char ch = char(0); ch <= char(126); ch++)
	{
		letters[ch]=0;
	}
	
	
	infile.get(ch);
	while(infile)
	{
		str += ch;
		letters[ch] += 1;
		infile.get(ch);
	}
		
}

void makeTree(HuffmanTree& H, int letters[], int& totalChar)
{	
	for(char ch = char(0); ch <= char(126); ch++)
	{
		if(letters[ch] != 0)
		{
			totalChar++;
			H.insert(ch, letters[ch]);		
				
		}
	}
	
	H.build();
}
