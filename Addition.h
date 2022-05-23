/*
 * Addition.h
 *
 *  Created on: Jul 26, 2015
 *      Author: franklyn
 */

#ifndef ADDITION_H_
#define ADDITION_H_

#include "Expression.h"

class Addition {
private:
	Expression* leftExp;
	Expression* rightExp;

public:
	Addition();
	virtual ~Addition();
	int getValue();
	int leftSide();
	int rightSide();

	Addition(Expression* left, Expression* right);
};

#endif /* ADDITION_H_ */
