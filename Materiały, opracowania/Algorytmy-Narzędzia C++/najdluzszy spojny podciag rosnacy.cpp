#include <iostream>
#include <string>

std::string getLongestCoherentIncreasingSequence(std::string str);

int main()
{
    std::cout << getLongestCoherentIncreasingSequence("6934781212345678902321");

    return 0;
}

std::string getLongestCoherentIncreasingSequence(std::string str)
{
    std::string sequence;
    sequence += str.front();
    std::string longest;

    for (std::size_t i = 1; i < str.size(); ++i)
        if (str.at(i) > str.at(i - 1))
            sequence += str.at(i);
        else {
            if (sequence.length() > longest.length())
                longest = sequence;

            sequence.clear();
            sequence += str.at(i);
        }

    return longest;
}
