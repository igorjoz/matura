#include <iostream>
#include <cstdlib>
#include <sstream>

template<typename T>
std::string toString(T val)
{
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

int main()
{

    std::string bin{ "111" };
    std::string oct{ "777" };
    std::string dec{ "999" };
    std::string hex{ "FFF" };

    auto binAsNumber = std::strtol(bin.c_str(), nullptr, 2);
    auto octAsNumber = std::strtol(oct.c_str(), nullptr, 8);
    auto decAsNumber = std::atoi(dec.c_str());
    auto hexAsNumber = std::strtol(hex.c_str(), nullptr, 16);

    std::cout << binAsNumber << '\n';
    std::cout << octAsNumber << '\n';
    std::cout << decAsNumber << '\n';
    std::cout << hexAsNumber << '\n';

    double pi = 3.14;

    std::string piAsString = toString(pi);

    std::cout << piAsString << '\n';

    return 0;
}
