#include <iostream>
#include <string>
#include <bitset>

std::string getBin(const int& num);
long getDec(const std::string& num);

int main()
{
    std::cout << getBin(31) << '\n';
    std::cout << getDec("00101") << '\n';

    return 0;
}

std::string getBin(const int& num)
{
    std::string numAsBin = std::bitset<32>{num}.to_string();

    return numAsBin.erase(0, numAsBin.find('1'));
}

long getDec(const std::string& num)
{
    return std::bitset<32>{num}.to_ulong();
}
