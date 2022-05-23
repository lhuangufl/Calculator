#ifndef NUMERICALMENU_H_
#define NUMERICALMENU_H_

#include <string.h>
#include <vector>

class NumericalMenu {

public:

	NumericalMenu();
	~NumericalMenu();

	void setPrompt(std::string text);
	void setPrompt();
	int addOption(std::string text);
	void setCancelText(std::string text);
	void setRepeatPromptOnError(bool repeat);
	void setErrorText(std::string text);
	int run() const;
	int size() const;
	
private:

	std::vector<std::string> 	OptionText;
	std::string 				PromptText;
	std::string 				CancelText;
	std::string 				ErrorText;
	bool doRepeat;
	
};

#endif