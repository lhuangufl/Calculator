/*
* main.cpp
*
*  Created on: Jun 19, 2015
*      Author: franklyn
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <ctype.h>
#include "Str2Vector.h"
#include "ShuntYard.h"
#include "ExpressionTree.h"
#include "NumericalMenu.h"
using namespace std;

int main()
{
	int					UserInput = 0;
	bool				isRepeat = true;
	double				ans = 0;
	string				line;
	vector<string>		InString;
	vector<string>		OuString;


	//std::getline(std::cin, str_tmp);
	NumericalMenu menu;
	
	/** Main Contains menu **/
	menu.setPrompt("Choose an option : ");
	menu.addOption("Enter new values ");
	menu.addOption("Help");
	menu.addOption("Save");
	menu.setCancelText("Exit");


	while (isRepeat)
	{

		UserInput = menu.run();
		if (UserInput == 1)
		{
			Str2Vector			_StrVect;
			ShuntYard			shuntyard;
			ExpressionTree		et(ans);

			cin.ignore();
			getline(cin, line);  // read a line from std::cin into line

			//std::cout << "Your Line Was (" << line << ")\n";
			//str_tmp = "3 + 2 * 4";


			//obtain the vector of strings based on spaces between any values and operators
			InString = _StrVect.getVector(line);
			OuString = shuntyard.Shunt(InString);

			et.buildTree(OuString);
			ans = et.evaluate();
			cout << "\n\nEvaluated Result : " << ans << endl;

			//decontruct the object instances
			_StrVect.~Str2Vector();
			shuntyard.~ShuntYard();
			et.~ExpressionTree();
		}
		else if (UserInput == 2)
		{
			cout << "################################################################################" << endl;
			cout << "################################################################################" << endl;
			cout << "##			Welcome to My Calculator							##" << endl;
			cout << "## (Programmer: Lin Huang;		UFID: 09107917)  			    ##" << endl;
			cout << "## The following operators are allowed:                                       ##" << endl;
			cout << "## + add 			##" << endl;
			cout << "## - subtract			##" << endl;
			cout << "## * multiply			##" << endl;
			cout << "## / divide 			##" << endl;
			cout << "## The following expressions are allowed: 				      ##" << endl;
			cout << "## e - Euler's number 2.71828182				      ##" << endl;
			cout << "## pi - 3.141592653589793238462643383279502884197136939937510582097494	      ##" << endl;
			cout << "## log - logarithm. Example: log3(3) - log base 3 of 3			      ##" << endl;
			cout << "## rad - radical. Example: rad3(9) - cubic root of 9			      ##" << endl;
			cout << "## ^ - exponent. Example 2^3 - 2 to the power of 3			      ##" << endl;
			cout << "## () - Grouping							      ##" << endl;
			cout << "################################################################################" << endl;
			cout << "################################################################################" << endl;
			cout << endl;
		}
		else if (UserInput == -1)
		{
			cout << "Program Exit!" << endl;
			isRepeat = false;
		}
	}
	system("pause");

}

