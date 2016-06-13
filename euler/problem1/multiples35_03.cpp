#include <iostream>

#include <time.h>

template <int i, bool = ((i % 3 == 0) || (i % 5 == 0))>
struct add_multiples
{
    const static int value = add_multiples<i - 1>::value;
};

template <int i>
struct add_multiples<i, true>
{
    const static int value = add_multiples<i - 1>::value + i;
};

template <>
struct add_multiples<0>
{
    const static int value = 0;
};

int main()
{
    timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    int sum = add_multiples<999>::value;
    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Time elapsed: " << end.tv_nsec - start.tv_nsec << "ns" << std::endl;

    return 0;
}
