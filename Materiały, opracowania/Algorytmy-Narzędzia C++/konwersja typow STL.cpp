#include <iostream>
#include <string>

int main()
{
	std::string bin{ "111" };
	std::string oct{ "777" };
	std::string dec{ "999" };
	std::string hex{ "FFF" };

	auto binAsNumber = std::stoi(bin, nullptr, 2);
	auto octAsNumber = std::stoi(oct, nullptr, 8);
	auto decAsNumber = std::stoi(dec);
	auto hexAsNumber = std::stoi(hex, nullptr, 16);

	std::cout << binAsNumber << '\n';
	std::cout << octAsNumber << '\n';
	std::cout << decAsNumber << '\n';
	std::cout << hexAsNumber << '\n';

	double pi = 3.14;

	std::string piAsString = std::to_string(pi);

	std::cout << piAsString << '\n';

	return 0;
}