#include <iostream>
#include <random>
#include <chrono>

double getPi(std::size_t n);

int main()
{
    std::cout << getPi(10000000);

    return 0;
}

double getPi(std::size_t n)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine realEngine{seed};
    std::uniform_real_distribution<> dist{0, 1};
    auto nk = 0u;

    for (std::size_t i = 0; i < n; ++i) {
        auto x = dist(realEngine);
        auto y = dist(realEngine);

        if (x * x + y * y <= 1)
            nk++;
    }

    return static_cast<double>(nk) / n * 4;
}
