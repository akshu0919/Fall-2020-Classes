#include <iostream>
#include "bet.h"

BET::BET()
{
	root = NULL;
}

BET::~BET()
{
	makeEmpty();
}

bool BET::isEmpty() const
{
	if(root == NULL)
		return true;
	else
		return false;
}

void BET::makeEmpty()
{
	makeEmpty(root);
}

void BET::makeEmpty(BETPtr& t) const
{

	if(t != NULL)
	{
		if(t -> right != NULL)
			makeEmpty(t -> right);
		else if(t -> left != NULL)
			makeEmpty(t -> left);	
		else
			delete t;
	}

	t = NULL;
}

void BET::insertPrefixOperator(char token)
{
	BETPtr operation = new BinaryNode;

        operation -> left = s.top();
        s.pop();

        operation -> right = s.top();
        s.pop();

        operation -> info.whichType = OPERATOR;
        operation -> info.theContent.opsymbol = token;

        s.push(operation);

        root = operation;
	
}

void BET::insertPostfixOperator(char token)
{
	
	BETPtr operation = new BinaryNode;
	
	operation -> right = s.top();
	s.pop();

	operation -> left = s.top();
	s.pop();

	operation -> info.whichType = OPERATOR;
	operation -> info.theContent.opsymbol = token;

	s.push(operation);

	root = operation;
			
}

void BET::insertOperand(char token)
{
	BETPtr operand = new BinaryNode;

	operand -> info.whichType = OPERAND;
	operand -> info.theContent.variable = token;

	//Since this will always be a leaf
	operand -> left == NULL;
	operand -> right == NULL;

	s.push(operand);
}

void BET::preorder() const
{
	preorder(root);
}

void BET::preorder(BETPtr t) const
{
	if(t != NULL)
	{
	
		if(t -> info.whichType == OPERAND)
			cout << t -> info.theContent.variable << " ";
		if(t -> info.whichType == OPERATOR)
			cout << t -> info.theContent.opsymbol << " ";

		preorder(t -> left);	
		preorder(t -> right);
	}
}

void BET::inorder() const
{
	inorder(root);
}

void BET::inorder(BETPtr t) const
{
	if(t != NULL)
	{
		if(t -> left != NULL)
			cout << "( ";
		inorder(t -> left);

		if(t -> info.whichType == OPERAND)
                	cout << t -> info.theContent.variable << " ";
                if(t -> info.whichType == OPERATOR)
                	cout << t -> info.theContent.opsymbol << " ";

		inorder(t -> right);	
		if(t -> right != NULL)
			cout << " )";	
	}
}

void BET::postorder() const
{
	postorder(root);
}

void BET::postorder(BETPtr t) const
{
	if( t != NULL)
	{
		postorder(t -> left);
		postorder(t -> right);

		if(t -> info.whichType == OPERAND)
			cout << t -> info.theContent.variable << " ";
		if(t -> info.whichType == OPERATOR)
			cout << t -> info.theContent.opsymbol << " ";
	}
}
