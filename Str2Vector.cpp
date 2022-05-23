/*
 * Str2Vector.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: franklyn
 */


#include "Str2Vector.h"

Str2Vector::Str2Vector() 
{
	// Initialize
	str = ' ';
}

Str2Vector::~Str2Vector() 
{
	while (!A.empty())
		A.pop_back();
	// TODO Auto-generated destructor stub
}

std::vector<std::string> Str2Vector::getVector(std::string str)
{
	this->str = str;
	Str2Vector::iss_str();

	return A;

}
void Str2Vector::iss_str() 
{
	std::istringstream	iss(str);
	std::string			str_tmp;

	while (iss >> str_tmp) 
	{
		A.push_back(str_tmp);
	}
}
