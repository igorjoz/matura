#include <fstream>
#include <string>

int main()
{
    std::ofstream file{"file.txt"};
    std::string data{"do pliku dane zapisujemy tak samo jak wypisujemy je w konsoli"};

    file << data << '\n'; // zamiast std::cout dajemy nazwe obiektu typu ofstream

    return 0;
}
