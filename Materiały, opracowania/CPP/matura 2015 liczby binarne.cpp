#include <fstream>
#include <string>
#include <iostream>
#include <array>

void zad41();
void zad42();
void zad43();
bool isBigger(std::string s1, std::string s2);

int main()
{
	zad41();
	zad42();
	zad43();

	getchar(); getchar();
	return 0;
}

void zad41()
{
	int moreZero = 0;
	int zero;
	std::string number;
	std::fstream file("liczby.txt");
	std::fstream file2("wynik4.txt", std::ios::app);

	for (int i = 0; i < 1000; i++)
	{
		file >> number;

		zero = 0;

		for (int j = 0; j < number.length(); j++)
			if (number[j] == '0')
				zero++;

		if (zero > (number.length() - zero))
			moreZero++;	
	}

	file2 << "4.1. ilosc liczb z wieksza iloscia 0 niz 1: " << moreZero << '\n';

	file.close();
	file2.close();
}

void zad42()
{
	int by2 = 0;
	int by8 = 0;
	std::string number;
	std::fstream file("liczby.txt");
	std::fstream file2("wynik4.txt", std::ios::app);

	for (int i = 0; i < 1000; i++)
	{
		file >> number;

		if (number[number.length() - 1] == '0')
			by2++;

		if (number.length() < 3)
			void;
		else if (number[number.length() - 1] == '0' &&
			number[number.length() - 2] == '0' &&
			number[number.length() - 3] == '0')
			by8++;
	}

	file2 << "4.2. podzielnych przez 2: " << by2 << ", podzielnych przez 8: " << by8 << '\n';

	file.close();
	file2.close();
}

void zad43()
{
	int indexMin = 0;
	int indexMax = 0;
	std::array<std::string, 1000> arr;
	std::fstream file("liczby.txt");
	std::fstream file2("wynik4.txt", std::ios::app);

	for (int i = 0; i < 1000; i++)
		file >> arr[i];

	for (int i = 1; i < 1000; i++)
	{
		if (isBigger(arr[indexMin], arr[i]))
			indexMin = i;
		if (isBigger(arr[i], arr[indexMax]))
			indexMax = i;
	}

	file2 << "4.3. numer wierwsza zawierajacy najmniejsza liczbe: " << indexMin + 1 << ", numer wierwsza zawierajacy najwieksza liczbe: " << indexMax + 1 << '\n';

	file.close();
	file2.close();
}

bool isBigger(std::string s1, std::string s2)
{
	if (s1.length() > s2.length())
		return true;
	if (s1.length() < s2.length())
		return false;
	
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == '1' && s2[i] == '0')
			return true;
		if (s1[i] == '0' && s2[i] == '1')
			return false;
	}
}
