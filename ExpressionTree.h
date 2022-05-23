#include <iostream>
#include <cstdlib>
#include <cstdio>     
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>


/** class TreeNode **/
class TreeNode
{
public:
	std::string data;
	TreeNode *left, *right;
	/** constructor **/
	TreeNode(std::string data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/** class StackNode **/
class StackNode
{
public:
	TreeNode *treeNode;
	StackNode *next;
	/** constructor **/
	StackNode(TreeNode *treeNode)
	{
		this->treeNode = treeNode;
		next = NULL;
	}
};


class ExpressionTree
{
private:
	StackNode	*top;
	double		ans;
public:
	/** constructor **/
	ExpressionTree();
	~ExpressionTree();
	/** function to clear tree **/
	ExpressionTree(double ans);

	void clear();

	/** function to push a node **/
	void push(TreeNode *ptr);

	/** function to pop a node **/
	TreeNode *pop();

	/** function to get top node **/
	TreeNode *peek();

	/** function to check if digit **/
	bool is_number(const std::string s);

	bool is_para(const std::string s);

	/** function to insert character **/
	void insert(std::string val);

	/** function to check if operator **/
	bool isOperator(std::string token);


	/** function to convert character to digit **/
	double toDigit(std::string ch);

	/** function to build tree from input */

	void buildTree(std::vector<std::string> eqn);


	/** function to evaluate tree */
	double evaluate();

	/** function to evaluate tree */
	double evaluate(TreeNode *ptr);

};



