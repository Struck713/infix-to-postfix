
#include <iostream>
#include <stack>

/*
 * First I need to evaluate a postfix "6 7 + 6 4 * -"
 * 
 */

bool eval(std::stack<int>&, char);

int main() {

	std::stack<int> intStack;
	const char str[] = "6 7 + 6 4 * -";

	int i = 0;
	while (str[i] != 0) {
		char current = str[i++];
		if (current == ' ') continue;
		if (eval(intStack, current)) continue;

		int charToInt = current - int('0');
		intStack.push(charToInt);
	}

	//if (intStack.empty() || intStack.size() != 1) {
	//	std::cout << "Failed to evaluate expression." << std::endl;
	//	return 0;
	//}

	int result = intStack.top();
	std::cout << "The result is: " << result << std::endl;
	

	return 0;
}

bool eval(std::stack<int>& intStack, char c) {
	int top = 0;
	switch (c) {
		case '+':

			top = intStack.top();
			intStack.pop();

			top += intStack.top();
			intStack.pop();

			intStack.push(top);

			return true;
		case '-':

			top = intStack.top();
			intStack.pop();

			top = intStack.top() - top; // reverse because subtraction is not communative
			intStack.pop();

			intStack.push(top);

			return true;
		case '*':

			top = intStack.top();
			intStack.pop();

			top *= intStack.top();
			intStack.pop();

			intStack.push(top);

			return true;
		case '/':

			top = intStack.top();
			intStack.pop();

			top = intStack.top() / top; // reverse because division is not communative
			intStack.pop();

			intStack.push(top);

			return true;
	}
	return false;
}

