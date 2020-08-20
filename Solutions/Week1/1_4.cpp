#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "classes.h"

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

void stackMax()
{
	int num_queries = 0;
	std::cin >> num_queries;

	string query;
	string value;

	StackWithMax stack;

	for (int i = 0; i < num_queries; ++i) {
		std::cin >> query;
		if (query == "push") {
			std::cin >> value;
			stack.Push(std::stoi(value));
		}
		else if (query == "pop") {
			stack.Pop();
		}
		else if (query == "max") {
			std::cout << stack.Max() << "\n";
		}
		else {
			assert(0);
		}
	}
}