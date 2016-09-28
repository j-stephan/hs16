#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <future>
#include <iterator>
#include <numeric>
#include <vector>

constexpr auto vec_size = std::size_t{1000000};

auto task1() -> void
{
    // fill a vector with values from vec_size to 0 and sort it
    auto vec = std::vector<std::int32_t>{vec_size};
    std::iota(std::rbegin(vec), std::rend(vec), 0);
    std::sort(std::begin(vec), std::end(vec));
}

auto task2() -> std::int32_t
{
    // fill a vector with random values and return the maximum
    auto vec = std::vector<std::int32_t>{vec_size};
    std::generate(std::begin(vec), std::end(vec), std::rand);
    auto it = std::max_element(std::begin(vec), std::end(vec));
    return *it;
}

auto main() -> int
{
    auto f1 = std::async(std::launch::deferred, task1);
    auto f2 = std::async(std::launch::deferred, task2);

    f1.get(); // return type void
    auto res = f2.get();

    return 0;
}
