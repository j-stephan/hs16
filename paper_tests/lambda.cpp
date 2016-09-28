#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <vector>

auto main() -> int
{
    auto vec1 = std::vector<int>{};
    vec1.resize(1000);
    std::for_each(std::begin(vec1), std::end(vec1), [](int& i) { i = std::rand() % 10; } );

    auto vec2 = std::vector<int>{};
    vec2.resize(1000);
    std::for_each(std::begin(vec2), std::end(vec2), [](auto& i) { i = std::rand() % 10; });

    return 0;
}
