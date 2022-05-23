#pragma once

#include <stack>
#include <string>
#include <vector>

class ShuntYard
{
private:
	std::vector<std::string>		  	InString;
	std::vector<std::string>		  	OuString;
	std::stack<std::string>  			OperatorStack;

public:
	ShuntYard();
	~ShuntYard();
	int		Option_Selected;
	bool	is_number(const std::string& s);
	bool	is_para(const std::string s);
	bool	isOperat(std::string token);
	int		token_rank(std::string tokenA, std::string tokenB);
	bool	token_IsLParen(std::string token);
	bool	token_IsRParen(std::string token);
	std::vector<std::string> 
			ShuntYard::Shunt(std::vector<std::string>& InStr);

};

