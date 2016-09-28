#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>

constexpr auto vec_size = std::size_t{1000000};

auto f() -> void
{
    auto vec = std::vector<std::int32_t>{vec_size};
    std::iota(std::rbegin(vec), std::rend(vec), 0);
    std::sort(std::begin(vec), std::end(vec));
}

auto main() -> int
{
    auto t = std::thread{f};
    t.detach();

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(5s);

    return 0;
}
