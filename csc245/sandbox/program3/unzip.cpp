using namespace std;
#include "huffman.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <map>

void Open(ifstream& infile, int argc, char *argv[], char* file);
void Read(ifstream& infile, map <string, char>& map, int& charCount, string& full);
void Inflate(ofstream& outfile, map<string, char>& map, string& full, char* file);

	int main(int argc, char *argv[])
	{
		ifstream infile;
		ofstream outfile;
    
		map <string, char> map;	
		int charCount;
		string full;
    char* file= argv[argc-1];

		Open(infile, argc, argv, file);
		Read(infile, map, charCount, full);
		Inflate(outfile, map, full, file);
	}

 void Open(ifstream& infile, int argc, char *argv[], char* file)
   {
        if (argc == 1)
        {
                cout << "No File Entered! Please Enter a file!" << endl;
                exit(1);
        }	
	if(!file)
	{
		cout<< "File was not found!" << endl;
	}	
	string File = (string) file;
	if(File.substr(File.find('.'), 4) != ".zip")
	{
		cout<< "Not a .zip file!" << endl;
		exit(1);
	}
	
        infile.open(File.c_str());
  }
  
  void Read(ifstream& infile, map <string, char>& map, int& charCount, string& full)
  {

	infile>> charCount;

   
	char letter;
	int temp;
	string code;

	for(int i=0; i<charCount; i++)
	{
		infile>>temp>>code;
		letter=(char) temp;
		map[code]=letter;
	}	
  	
	infile>> full;
  }

 void Inflate(ofstream& outfile, map<string, char>& map, string& full,char* file)
 {
    string str= "";
    str += file;
    str.erase(str.find('.'),4);
    outfile.open(str.c_str());
	
	string checker;
	string reinflated;
	char temp;

	for(int i=0; i<full.length(); i++)
	{
		checker+=full[i];
		if(map.find(checker) != map.end())
		{
			temp=map[checker];
			reinflated+=temp;
			checker="";			
		}	
	}	

	outfile<< reinflated << endl;
	cout<< "File Successfully Inflated Back To Original" << endl;
	
 }
