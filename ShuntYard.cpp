#include "ShuntYard.h"


ShuntYard::ShuntYard()
{
}

ShuntYard::~ShuntYard()
{
}

bool ShuntYard::is_number(const std::string& s)
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

bool ShuntYard::is_para(const std::string s)
{
	if (s == "pi" || s == "e" || s == "ans")
		return true;
	else
		return false;
}

bool ShuntYard::isOperat(std::string token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "rt")
	{
		return true;
	}
	else return false;
}

int ShuntYard::token_rank(std::string tokenA, std::string tokenB)
{
	// Checking ADDITION AND SUBTRACTION
	if (tokenA == "+" || tokenA == "-")
	{
		if (tokenB == "-" || tokenB == "+"){ return 0; }
		if (tokenB == "*" || tokenB == "/"){ return 1; }
		if (tokenB == "^" || tokenB == "rt"){ return 0; }
		if (tokenB == "("){ return 0; }
	}
	//  checking MULTIPLICATION AND DIVISION
	if (tokenA == "*" || tokenA == "/")
	{
		if (tokenB == "-" || tokenB == "+"){ return 0; }
		if (tokenB == "*" || tokenB == "/"){ return 0; }
		if (tokenB == "^" || tokenB == "rt"){ return 0; }
		if (tokenB == "("){ return 0; }
	}
	//  checking EXPONENTIATION
	if (tokenA == "^" || tokenA == "rt")
	{
		if (tokenB == "-" || tokenB == "+"){ return 0; }
		if (tokenB == "*" || tokenB == "/"){ return 0; }
		if (tokenB == "^" || tokenB == "rt"){ return 0; }
		if (tokenB == "("){ return 0; }
	}
}

bool ShuntYard::token_IsLParen(std::string token)
{
	if (token == "(")
	{
		return true;
	}
	else return false;
}

bool ShuntYard::token_IsRParen(std::string token)
{
	if (token == ")")
	{
		return true;
	}
	else return false;
}

std::vector<std::string> ShuntYard::Shunt(std::vector<std::string>& InStr) 
{
	for (unsigned int i = 0; i != InStr.size(); i++)
	{
		if (is_number(InStr[i]) || is_para(InStr[i]))
		{
			OuString.push_back(InStr[i]);
		}
		else if (isOperat(InStr[i]))
		{
			if (OperatorStack.empty())
			{
				OperatorStack.push(InStr[i]);
			}
			else if (token_rank(InStr[i], OperatorStack.top()))
			{
				OuString.push_back(OperatorStack.top());
				OperatorStack.pop();
				OperatorStack.push(InStr[i]);
			}
			else
			{
				OperatorStack.push(InStr[i]);
			}
		}
		else if (token_IsLParen(InStr[i]))
		{
			OperatorStack.push(InStr[i]);
		}
		else if (token_IsRParen(InStr[i]))
		{
			while (!token_IsLParen(OperatorStack.top()))
			{
				OuString.push_back(OperatorStack.top());
				OperatorStack.pop();
			}
			if (token_IsLParen(OperatorStack.top())) { OperatorStack.pop(); }
		}
	}

	while (!OperatorStack.empty())
	{
		OuString.push_back(OperatorStack.top());
		OperatorStack.pop();
	}
	return OuString;
}