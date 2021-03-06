#include <iostream>
#include <algorithm>
#include <string>

bool anagram(std::string str1, std::string str2);

int main()
{
	std::cout << anagram("kebab", "babek");

	return 0;
}

bool anagram(std::string str1, std::string str2)
{
	str1.erase(std::remove_if(str1.begin(), str1.end(), ::isspace), str1.end());
	str2.erase(std::remove_if(str2.begin(), str2.end(), ::isspace), str2.end());

	if (str1.length() != str2.length())
		return false;

	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

	return str1 == str2;
}
