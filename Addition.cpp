/*
 * Addition.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: franklyn
 */

#include "Addition.h"

Addition::Addition() {
	// TODO Auto-generated constructor stub

}

Addition::~Addition() {
	// TODO Auto-generated destructor stub
}

int Addition::getValue()
{
	return leftExp->getValue() + rightExp->getValue();
}

int Addition::leftSide()
{
	return leftExp->getValue();
}

int Addition::rightSide()
{
	return rightExp->getValue();
}
