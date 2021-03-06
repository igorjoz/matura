#include <iostream>

int reverseNubmer(int num);

int main()
{
    std::cout << reverseNubmer(78342);

    return 0;
}

int reverseNubmer(int num)
{
    int reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return reversed;
}
