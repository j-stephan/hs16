#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iterator>
#include <vector>

auto main() -> int
{
    constexpr auto vec_size = 1000u;

    auto vec_a = std::vector<int>{vec_size};
    auto vec_b = std::vector<int>{vec_size};
    auto vec_c = std::vector<int>{vec_size};

    std::generate(std::begin(vec_a), std::end(vec_a), std::rand);
    std::generate(std::begin(vec_b), std::end(vec_b), std::rand);

    std::transform(std::begin(vec_a), std::end(vec_a), std::begin(vec_b), std::begin(vec_c),
            [](auto a, auto b){return a * b;});

    return 0;
}
