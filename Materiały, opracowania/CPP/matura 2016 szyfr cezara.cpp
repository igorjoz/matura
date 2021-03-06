#include <iostream>
#include <string>
#include <fstream>

void zad61();
void zad62();
void zad63();

int main()
{
	return 0;
}

void zad61()
{
	int key = 107;
	key %= 26;
	std::string word;
	std::fstream file("dane_6_1.txt");
	std::fstream file2("wyniki_6_1.txt", std::ios::out);

	for (int i = 0; i < 100; i++)
	{
		file >> word;

		for (int j = 0; j < word.length(); j++)
			word[j] = 'A' + (word[j] + 26 - 'A' + key) % 26;

		file2 << word << '\n';
	}
}

void zad62()
{
	int key;
	std::string word;
	std::fstream file("dane_6_2.txt");
	std::fstream file2("wyniki_6_2.txt", std::ios::out);

	for (int i = 0; i < 3000; i++)
	{
		if (file >> word >> key) 
		{
			key %= 26;
			for (int j = 0; j < word.length(); j++)
				word[j] = 'A' + (word[j] + 26 - 'A' - key) % 26;
			file2 << word << '\n';
		}
		else
		{
			file2 << word << '\n';
			file.clear();
		}
	}

	file.close();
	file2.close();
}

void zad63()
{
	int key;
	std::string word;
	std::string word2;
	std::fstream file("dane_6_3.txt");
	std::fstream file2("wyniki_6_3.txt", std::ios::out);

	for (int i = 0; i < 3000; i++)
	{
		file >> word >> word2;

		key = word2[0] - word[0];

		if (key < 0)
			key += 26;

		for (int j = 0; j < word2.length(); j++)
			word2[j] = 'A' + (word2[j] + 26 - 'A' - key) % 26;

		if (word != word2)
			file2 << word << '\n';
	}

	file.close();
	file2.close();
}
