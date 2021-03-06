#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <cctype>
#include <cstdlib>

unsigned int factorial(const unsigned int& n);
bool operationOneArgument(const std::string& key);
bool operationTwoArguments(const std::string& key);
double calcRpn(std::vector<std::string> postfix);
bool isOperand(const char& c);
bool isOperator(const char& c);
short operatorPriority(const char& c);
bool heightPriorities(const char& a, const char& b);
bool isNegativeNumber(const std::string& str, const std::size_t& index);
std::vector<std::string> infixToPostfix(const std::string& infix);

int main()
{
	std::string infix;
	std::cout << "Wpisz dzialanie... ";
	std::getline(std::cin, infix);
	std::cout << calcRpn(infixToPostfix(infix)) << std::endl;

	return 0;
}

double calcRpn(std::vector<std::string> postfix)
{
	std::stack<double> stack;

	for (std::size_t i = 0; i < postfix.size(); ++i) {
		if (operationOneArgument(postfix.at(i))) {
			double a = stack.top();
			stack.pop();

			if (postfix.at(i) == "!")
				stack.push(factorial(a));
			else if (postfix.at(i) == "abs")
				stack.push(std::abs(a));
			else if (postfix.at(i) == "log")
				stack.push(std::log10(a));
			else if (postfix.at(i) == "sin")
				stack.push(std::sin(a));
			else if (postfix.at(i) == "cos")
				stack.push(std::cos(a));
			else if (postfix.at(i) == "tg")
				stack.push(std::tan(a));
			else if (postfix.at(i) == "sqrt")
				stack.push(std::sqrt(a));
		}
		else if (operationTwoArguments(postfix.at(i))) {
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();

			if (postfix.at(i) == "+")
				stack.push(b + a);
			else if (postfix.at(i) == "-")
				stack.push(b - a);
			else if (postfix.at(i) == "*")
				stack.push(b * a);
			else if (postfix.at(i) == "/")
				stack.push(b / a);
			else if (postfix.at(i) == "%")
				stack.push(std::fmod(b, a));
			else if (postfix.at(i) == "^")
				stack.push(std::pow(b, a));
		}
		else {
			 stack.push(std::strtod(postfix.at(i).c_str(), nullptr)); //stack.push(std::stod(postfix.at(i)));
		}
	}

	return stack.top();
}

unsigned int factorial(const unsigned int& n)
{
	unsigned int score = 1;

	for (std::size_t i = 1; i <= n; ++i)
		score *= i;

	return score;
}

bool operationOneArgument(const std::string& key)
{
	return (key == "!" || key == "abs" || key == "sin" || key == "cos" || key == "tg" || key == "sqrt" || key == "log");
}

bool operationTwoArguments(const std::string& key)
{
	return (key == "+" || key == "-" || key == "*" || key == "/" || key == "^" || key == "%");
}

std::vector<std::string> infixToPostfix(const std::string& infix)
{
	std::vector<std::string> postfix;
	std::stack<char> stack;
	std::string operand;

	for (std::size_t i = 0; i < infix.length(); ++i) {
		if (infix.at(i) == '(')
			stack.push(infix[i]);

		if (infix.at(i) == ')') {
			while (stack.top() != '(') {
				postfix.emplace_back(std::string(1, stack.top()));
				stack.pop();
			}
			stack.pop();
		}

		if (isOperand(infix.at(i))) {
			if (isNegativeNumber(infix, i))
				operand += '-';

			while (isOperand(infix.at(i))) {
				operand += infix.at(i++);

				if (i == infix.length())
					break;
			}

			postfix.emplace_back(operand);
			operand.clear();
			i--;
		}

		if (isOperator(infix[i]) && !isNegativeNumber(infix, i + 1)) {
			while (!stack.empty() && stack.top() != '(' && !heightPriorities(infix.at(i), stack.top())) {
				postfix.emplace_back(std::string(1, stack.top()));
				stack.pop();
			}
			stack.push(infix.at(i));
		}

	}

	while (!stack.empty()) {
		postfix.emplace_back(std::string(1, stack.top()));
		stack.pop();
	}

	return postfix;
}

bool isOperand(const char& c)
{
	if (std::isdigit(c))
		return true;

	if (std::isalpha(c))
		return true;

	if (c == '.')
		return true;

	return false;
}

bool isOperator(const char& c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' || c == '!');
}

short operatorPriority(const char& c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	if (c == '^' || c == '!')
		return 3;
}

bool heightPriorities(const char& a, const char& b)
{
	return operatorPriority(a) > operatorPriority(b);
}

bool isNegativeNumber(const std::string& str, const std::size_t& index)
{
	if (index >= str.size() || (isOperand(str.at(index)) && index == 0))
		return false;

	return (str.at(index - 1) == '-' && (index - 1 == 0 || str.at(index - 2) == '('));
}
