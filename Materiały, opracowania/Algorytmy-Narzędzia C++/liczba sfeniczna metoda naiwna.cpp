#include <iostream>
#include <cstddef>
#include <cmath>

void sphenic(unsigned n);

int main()
{
	sphenic(114u);

    return 0;
}

void sphenic(unsigned n)
{
    auto notSphenic = true;

    for (std::size_t i = 2; i <= std::sqrt(n) && notSphenic; ++i)
        for (std::size_t j = i + 1; j <= std::sqrt(n) && notSphenic; ++j)
            for (std::size_t k = j + 1; k <= n && notSphenic; ++k)
                if (i * j * k == n) {
                        std::cout << i << " * " << j << " * " << k << '\n';
                        notSphenic = false;
                }

    if (notSphenic)
        std::cout << "NO\n";
}