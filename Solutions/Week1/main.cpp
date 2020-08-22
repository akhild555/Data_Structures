#include <iostream>
#include <string>
#include "week1.h"

int main() {

	// Switch which problem you want to run from week 1 assignment //

	int problem = 5;

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

	case 3:
	{
		int size;
		std::cin >> size;
		std::vector <Request> requests = ReadRequests();

		Buffer buffer(size);
		std::vector <Response> responses = ProcessRequests(requests, &buffer);

		PrintResponses(responses);
	}

	case 4:
	{
		stackMax();
	}
	
	case 5:
	{
		int n = 0;
		std::cin >> n;

		std::vector<int> A(n);
		for (size_t i = 0; i < n; ++i)
			std::cin >> A.at(i);

		int w = 0;
		std::cin >> w;

		max_sliding_window_fast(A, w);

		return 0;
	}
	}
}
