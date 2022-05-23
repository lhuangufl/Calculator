/*
 * Expression.h
 *
 *  Created on: Jul 26, 2015
 *      Author: franklyn
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

class Expression {
public:
	Expression();
	virtual ~Expression();
	virtual int getValue() = 0;
	virtual int leftSide() = 0;
	virtual int rightSide() = 0;
};

#endif /* EXPRESSION_H_ */
