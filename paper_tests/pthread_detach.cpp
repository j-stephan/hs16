#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>

#include <pthread.h>
#include <unistd.h>

constexpr auto vec_size = std::size_t{1000000};

auto f(void*) -> void*
{
    auto vec = std::vector<std::int32_t>{vec_size};
    std::iota(std::rbegin(vec), std::rend(vec), 0);
    std::sort(std::begin(vec), std::end(vec));
    return nullptr;
}

auto main() -> int
{
    auto t = pthread_t{};
    pthread_create(&t, nullptr, f, 0);
    pthread_detach(t);

    usleep(5000000);

    return 0;
}
