#include <iostream>
#include <string>
#include "week1.h"

int main() {

	// Switch which problem you want to run from week 1 assignment //

	int problem = 1;

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

	}
}
