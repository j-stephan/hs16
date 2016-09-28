#include <algorithm>
#include <array>
#include <condition_variable>
#include <iostream>
#include <iterator>
#include <mutex>

#include <pthread.h>
#include <unistd.h>

std::condition_variable cv;
std::mutex m;

auto done = false;

auto wait(void*) -> void*
{
    std::unique_lock<std::mutex> l(m);
    std::cout << "Waiting\n";
    cv.wait(l, []{return done;});
    std::cout << "...finished waiting. done == true\n";
    return nullptr;
}

auto signal(void*) -> void*
{
    usleep(1000000);
    {
        // create scope for lock_guard
        std::lock_guard<std::mutex> l(m);
        std::cout << "Notifying...\n";
    }
    cv.notify_all();

    usleep(1000000);
    {
        std::lock_guard<std::mutex> l(m);
        done = true;
        std::cout << "Notifying again...\n";
    }
    cv.notify_all();

    return nullptr;
}

auto main() -> int
{
    auto threads = std::array<pthread_t, 4>{};

    std::for_each(std::begin(threads), std::begin(threads) + 3, [](auto& t){ pthread_create(&t, nullptr, wait, 0); });

    pthread_create(&threads[3], nullptr, signal, 0);

    for(auto&& t : threads)
        pthread_join(t, nullptr);
}
