#include <iostream>

#include <time.h>

constexpr auto add_multiples(int i) -> int
{
    return (i == 0) ? 0 : (((i % 3 == 0) || (i % 5 == 0)) ? i + add_multiples(i - 1) : add_multiples(i - 1));
}

auto main() -> int
{
    auto start = timespec{};
    auto end = timespec{};

    clock_gettime(CLOCK_MONOTONIC, &start);
    constexpr auto sum = add_multiples(999);
    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Result: " << sum << std::endl;
    std::cout << "Elapsed time: " << end.tv_nsec - start.tv_nsec << "ns" << std::endl;

    clock_gettime(CLOCK_MONOTONIC, &start);
    auto sum2 = add_multiples(999);
    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Result: " << sum2 << std::endl;
    std::cout << "Elapsed time: " << end.tv_nsec - start.tv_nsec << "ns" << std::endl;

    return 0;
}
