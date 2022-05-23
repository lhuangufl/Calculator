#include <iostream>
#include <cstdlib>
#include <cstdio>     
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include "ExpressionTree.h"

using namespace std;


/** constructor **/
ExpressionTree::ExpressionTree(double ans)
{
	top = NULL;
	this->ans = ans;
}

ExpressionTree::~ExpressionTree()
{

}

/** function to clear tree **/
void ExpressionTree::clear()
{
	top = NULL;
}

/** function to push a node **/
void ExpressionTree::push(TreeNode *ptr)
{
	if (top == NULL)
		top = new StackNode(ptr);
	else
	{
		StackNode *nptr = new StackNode(ptr);
		nptr->next = top;
		top = nptr;
	}
}

/** function to pop a node **/
TreeNode * ExpressionTree::pop()
{
	if (top == NULL)
	{
		cout << "Underflow" << endl;
	}
	else
	{
		TreeNode *ptr = top->treeNode;
		top = top->next;
		return ptr;
	}
}

/** function to get top node **/
TreeNode * ExpressionTree::peek()
{
	return top->treeNode;
}

/** function to check if digit **/
bool ExpressionTree::is_number(const string s)
{
	int len = s.length();
		
	for (int i = 0; i < len; i++) 
	{
		if (!isdigit(s[i]) && s[i] != '.')
		{
			return false;
		}
	}
	return true;
}

bool ExpressionTree::is_para(const string s)
{
	if (s == "pi" || s == "e" || s == "ans")
		return true;
	else 
		return false;
}
/** function to insert character **/
void ExpressionTree::insert(string val)
{
	if (is_number(val) || is_para(val))
	{
		TreeNode *nptr = new TreeNode(val);
		push(nptr);
	}
	else if (isOperator(val))
	{
		TreeNode *nptr = new TreeNode(val);
		nptr->right = pop();
		nptr->left = pop();
		push(nptr);
	}
	else
	{
		cout << "Invalid Expression" << endl;
		return;
	}
}

/** function to check if operator **/
bool ExpressionTree::isOperator(string token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "rt")
	{
		return true;
	}
	else return false;
}

/** function to convert character to digit **/
double ExpressionTree::toDigit(string ch)
{
	if (is_number(ch))
		return stod(ch);
	else if (is_para(ch))
	{
		if (ch == "pi")
			return 3.14159265;
		else if (ch == "e")
			return 2.71828182;
		else
			return ans;
	}
}

/** function to build tree from input */

void ExpressionTree::buildTree(vector<string> eqn)
{
	for (int i = 0; i < eqn.size(); i++)
	{
		insert(eqn[i]);
		//cout << "the size is: " << eqn[i] << endl;
	}
}

/** function to evaluate tree */
double ExpressionTree::evaluate()
{
	return evaluate(peek());
}

/** function to evaluate tree */
double ExpressionTree::evaluate(TreeNode *ptr)
{
	if (ptr->left == NULL && ptr->right == NULL)
		return toDigit(ptr->data);
	else
	{
		double result = 0.0;
		double left = evaluate(ptr->left);
		double right = evaluate(ptr->right);
		string op = ptr->data;
		if (op == "+")
			result = left + right;
		else if (op == "-")
			result = left - right;
		else if (op == "*")
			result = left * right;
		else if (op == "/")
			result = left / right;
		else if (op == "^")
			result = pow(left, right);
		else if (op == "rt")
			result = pow(right, 1 / left);
		else
			result = left + right;
		return result;
	}
}



