#include <iostream>
#include <algorithm>
#include <string>
#include "bet.h"
using namespace std;

void printMenu();
BET prefixExpression(string exp);
BET postfixExpression(string exp);
BET infixExpression(string exp);
void printFinal(BET expTree);
bool pemdas(char prev, char curr);


int main()
{
	printMenu();

	/*char again = 'y';
	
	while(tolower(again) != 'n')
	{
		cout << "Build Another Tree? (Y/N) ";
		cin >> again;

		if(tolower(again) == 'y')
			printMenu();
		
		if(tolower(again) == 'n')
		{
			cout << "Programming Now Deconstructin Tree & Exiting..." << endl;
			break;
		}
	}*/
	return 0;
}

void printMenu()
{
	char input, again;
	string exp = "";
	cout << "************ Building Binary Expression Trees ************" << endl;
	cout << "	(1) Prefix	(2) Infix	(3) Postfix	" << endl;
	cout << "Your Expression Type ==> " ;
	cin >> input;
	cout << "Your Expression ==> ";
	cin >> exp;

	exp.erase( remove( exp.begin(), exp.end(), ' ' ), exp.end() );

	if(input == '1')
		printFinal( prefixExpression(exp) );
	else if(input == '2')
		printFinal( infixExpression(exp) );
	else if(input == '3')
		printFinal( postfixExpression(exp) );
	else 
		cout << "Invalid Expression Type! " << endl;

	cout << "Build Another Tree? (Y/N)" << endl;
	cin >> again;
	
	if(tolower(again) == 'y')
		printMenu();
	else if(tolower(again) == 'n')
		cout <<"Program Now Deconstructing Tree & Exiting..."<<endl;
	else
		cout <<"Invalid Input!" << endl;

}

BET prefixExpression(string exp)
{
	BET expTree = BET();

	for(int i = exp.length() - 1; i >= 0; i--)
	{
		if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
			expTree.insertPrefixOperator(exp[i]);
		else
			expTree.insertOperand(exp[i]);
	}

	return expTree; 		
}

BET postfixExpression(string exp)
{
	BET expTree = BET();
        
        for(int i = 0; i < exp.length(); i++)
        {
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
                        expTree.insertPostfixOperator(exp[i]);
                else
                        expTree.insertOperand(exp[i]);
        }

        return expTree;
}

BET infixExpression(string exp)
{
	stack<char> s;
	string result = "";
	char curr;

	exp = "(" + exp;
	exp = exp + ")";
	for(int i = 0; i < exp.length(); i++)
	{
		curr = exp[i];

		if(curr == '(')
                        s.push(curr); 
                else if(curr == '+' || curr == '-' || curr == '*' || curr == '/')
                {
                        while(pemdas(s.top(), curr) == true)
                        {
                                result = result + s.top();
                                s.pop();
                        }
                        s.push(curr);
                }
                else if(curr == ')')
                {
                        while(s.top() != '(')
                        {
                                result = result + s.top();
                                s.pop();
                        }
                        s.pop();
                }
                else
                        result = result + curr;
        }


	return postfixExpression(result);
}

bool pemdas(char prev, char curr)
{
	if((prev == '+' || prev == '-') && (curr == '+' || curr == '-'))
		return true;
	else if((prev == '*' || prev == '/') && (curr == '*' || prev == '/'))
		return true;
	else if((prev == '*' || prev == '/') && (curr == '+' || curr == '-'))
		return true;
	else
		return false;
}

void printFinal(BET expTree)
{

	cout << "Prefix Expression Produced From Tree: " << endl;
	expTree.preorder();
	cout << endl;

	cout << "Infix Expression Produced From Tree: " << endl;
	expTree.inorder();
	cout << endl;

	cout << "Postfix Expression Produced From Tree: " << endl;
	expTree.postorder();
	cout << endl;

	expTree.makeEmpty();
}
