#include <iostream>

#include <time.h>

constexpr auto add_multiples(int limit) -> int
{
/*    if(i == 0)
        return 0;
    else
    {
        if((i % 3 == 0) || (i % 5 == 0))
            return i + add_multiples(i - 1);
        else
            return add_multiples(i - 1);
    }*/
    auto sum = 0;
    for(auto i = 0; i < limit; ++i)
    {
        if((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    }
    return sum;

}

auto main() -> int
{
    auto start = timespec{};
    auto end = timespec{};
    

    clock_gettime(CLOCK_MONOTONIC, &start);
    constexpr auto sum = add_multiples(1000);
    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Result: " << sum << std::endl;
    std::cout << "Time elapsed: " << end.tv_nsec - start.tv_nsec << "ns" << std::endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    auto sum2 = add_multiples(1000);
    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Result 2: " << sum2 << std::endl;
    std::cout << "Elapsed time: " << end.tv_nsec - start.tv_nsec << "ns" << std::endl;

    return 0;
}
