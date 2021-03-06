#include <iostream>

void hanoi(unsigned n, char a = 'A', char b = 'B', char c = 'C');

int main()
{
    hanoi(4);

    return 0;
}

void hanoi(unsigned n, char a, char b, char c)
{
	if (n == 1)
		std::cout << a << " -> " << c << '\n';
	else {
		hanoi(n - 1, a, c, b);
		std::cout << a << " -> " << c << '\n';
		hanoi(n - 1, b, a, c);
	}
}
