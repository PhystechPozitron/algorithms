#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

bool types_equal(char first, char last) {
	if ((first == '(')&&(last == ')')) return true;
	if ((first == '[')&&(last == ']')) return true;
	if ((first == '{')&&(last == '}')) return true;
	return false;
}

int main() {
	std::string str;
	std::vector<char> stack;

	std::cin >> str;
	for (unsigned int i = 0; i < str.length(); i++) {
		if ((str[i] == '(')||(str[i] == '[')||(str[i] == '{')) {
			stack.push_back(str[i]);
		} else {
			if ((stack.size() > 0)&&(types_equal(stack[stack.size() - 1], str[i]))) {
				stack.pop_back();
			} else {
				std::cout << i << std::endl;
				exit(0);
			}
		}
	}

	if (stack.size() > 0) {
		std::cout << str.length() << std::endl;
	} else  {
		std::cout << "correct" << std::endl;
	}

	return 0;
}




