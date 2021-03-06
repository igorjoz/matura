#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream file{"file.txt"};
    std::vector<std::string> vec; // zamiast std::string mozeby dac co chcemy odczytywac z pliku
    std::string temp; // wtedy typ zmiennej temp tez trzeba zmienic

    while (file >> temp) // najprostszy sposob
        vec.emplace_back(temp); // to jest szybsze
        //vec.push_back(temp);

    return 0;
}
