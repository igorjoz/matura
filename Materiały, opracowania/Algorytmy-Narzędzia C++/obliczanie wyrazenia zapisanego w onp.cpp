#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

unsigned int factorial(const unsigned int& n);
bool operationOneArgument(const std::string& key);
bool operationTwoArguments(const std::string& key);
double calcRpn(std::vector<std::string> postfix);
double stringToDouble(std::string token);

int main()
{
    std::vector<std::string> postfix{"4", "2", "3", "+","*", "3", "2", "-", "*"};
    std::cout << calcRpn(postfix);

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

        } else if (operationTwoArguments(postfix.at(i))) {

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

        } else
            stack.push(stringToDouble(postfix.at(i))); //stack.push(std::stod(postfix.at(i)));
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

double stringToDouble(std::string str)
{
	double key;
	std::stringstream stringKey;
	stringKey << str;
	stringKey >> key;
	return key;
}
