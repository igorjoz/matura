#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

bool isOperand(const char& c);
bool isOperator(const char& c);
short operatorPriority(const char& c);
bool heightPriorities(const char& a, const char& b);
bool isNegativeNumber(const std::string& str, const std::size_t& index);
std::vector<std::string> infixToPostfix(const std::string& infix);

int main()
{
    std::string infix{"2*(-3+5)^2"};
    auto postfix = infixToPostfix(infix);

    for (const auto& val : postfix)
        std::cout << val << ' ';

    return 0;
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

            while(isOperand(infix.at(i))) {
                operand += infix.at(i++);

                if (i == infix.length())
                    break;
            }

            postfix.emplace_back(operand);
            operand.clear();
            i--;
        }

        if (isOperator(infix[i]) && !isNegativeNumber(infix, i  + 1)) {
            while (!stack.empty() && stack.top() != '(' && !heightPriorities(infix.at(i),stack.top())) {
                postfix.emplace_back(std::string(1, stack.top()));
                stack.pop();
            }
            stack.push(infix.at(i));
        }

    }

    while (!stack.empty()){
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
