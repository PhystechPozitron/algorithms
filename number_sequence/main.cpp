#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

int main() {
	unsigned int n;
	std::vector<int> input;
	std::vector<int> output;
	std::vector<unsigned int> stack;

	// parse sequence to vector input
	std::string line;
	std::getline(std::cin, line);
	n = std::stoi(line);
	std::getline(std::cin, line);
	std::istringstream iss(line);
	int a;
	while (iss >> a) {
		input.push_back(a);
		output.push_back(-1);
	}

	// algorithm
	stack.push_back(0);
	for (unsigned int i = 0; i < n; i++) {
		while ((stack.size() > 0)&&(input[i] > input[stack[stack.size() - 1]])) {
			output[stack[stack.size() - 1]] = i + 1;
			stack.pop_back();
		}
		stack.push_back(i);
	};

	for (auto it:output) {
		std::cout << it << " ";
	}
	std::cout << std::endl;

	return 0;
}




