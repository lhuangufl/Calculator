/*
 * Str2Vector.h
 *
 *  Created on: Jun 22, 2015
 *      Author: franklyn
 */

#ifndef Str2Vector_H_
#define Str2Vector_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Str2Vector {
public:
	Str2Vector();
	~Str2Vector();
	std::vector<std::string>	getVector(std::string);
	void						iss_str();

private:
	std::string					str;
	std::vector<std::string>	A;

};

#endif /* Str2Vector_H_ */
