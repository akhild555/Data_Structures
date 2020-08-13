#include <iostream>
#include <string>
#include "week1.h"

int main() {

	// Switch which problem you want to run from week 1 assignment //

	int problem = 2;

	switch (problem) {

	case 1:
	{
		std::string text;
		getline(std::cin, text);
		int a = isBalanced(text);
		if (a == 0)
		{
			std::cout << "Success" << std::endl;
		}
		else
		{
			std::cout << a << std::endl;
		}
		
	}

	case 2:
	{
		main_with_large_stack_space();
	}

	}
}
