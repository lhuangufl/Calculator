/*
 * NumericalMenu.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: franklyn
 */


#include <iostream>
#include "NumericalMenu.h"
#include <string>
#include <vector>
#include <numeric>

NumericalMenu::NumericalMenu() 
{
	doRepeat = true;
	PromptText = "Choose an option: ";
	CancelText =  "Cancel";
	ErrorText = "Error!";
}

NumericalMenu::~NumericalMenu() 
{

}

int NumericalMenu::run() const 
{
	int Option_Selected;
	int option_size = OptionText.size();
	std::string input;
	std::cout << PromptText << std::endl;
	for (int i=0; i<option_size; i++) 
	{
		std::cout << i+1 << " - " << OptionText[i] << std::endl;
	}
	std::cout << option_size+1 << " - " << CancelText << std::endl;

	do
	{
		std::cin >> Option_Selected;
		
		//std::cout << option_size << std::endl;
		switch (Option_Selected)
		{
		case 1:
		case 2:
		case 3:
			return Option_Selected;
		case 4:
			return -1;
		default:
			std::cout << ErrorText << std::endl;
			if (doRepeat)
			{
				std::cout << PromptText << std::endl;
				for (int i = 0; i < option_size; i++)
				{
					std::cout << i + 1 << " - " << OptionText[i] << std::endl;
				}
				std::cout << option_size + 1 << " - " << CancelText << std::endl;
			}
		}
	}
	while (Option_Selected != 1 || Option_Selected != 2 || 
	Option_Selected != 3 || Option_Selected != 4);
}

void NumericalMenu::setPrompt(std::string s) 
{
	this->PromptText = s;
}


int NumericalMenu::addOption(std::string s)
{
	this->OptionText.push_back(s);
	return OptionText.size();
}

void NumericalMenu::setCancelText(std::string s) 
{
	this->CancelText = s;
}

int NumericalMenu::size() const 
{
	return this->OptionText.size();

}

void NumericalMenu::setErrorText(std::string s) 
{
	this->ErrorText = s;
}

void NumericalMenu::setRepeatPromptOnError(bool repeat) 
{
	if (!repeat)
		this->doRepeat = false;
}
