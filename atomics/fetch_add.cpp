#include <atomic>
#include <cstdint>
#include <iostream>
#include <vector>

#include <pthread.h>

std::atomic<std::int64_t> data;

auto do_work(void* p) -> void*
{
    data.fetch_add(1, std::memory_order_relaxed);
}

auto main() -> int
{
    auto threads = std::vector<pthread_t>(5);

    for(auto& t : threads)
        pthread_create(&t, nullptr, do_work, nullptr);

    for(auto& t : threads)
        pthread_join(t, nullptr);

    std::cout << "Result: " << data << std::endl;

    return 0;
}
