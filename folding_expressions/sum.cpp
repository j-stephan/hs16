#include <iostream>

template <class... Args>
auto print(Args... args) -> void
{
    (std::cout << ... << args) << std::endl;
}

template <class... Args>
auto sum(Args... args) -> int
{
    return (args + ...);
}

auto main() -> int
{
    auto result = sum(40, 2);
    print("The result is: ", result);

    return 0;
}

