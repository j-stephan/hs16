#include <iostream>
#include <mutex>

#include <pthread.h>
#include <unistd.h>

std::mutex m;

auto f1(void* p) -> void*
{
    std::lock_guard<std::mutex> l(m);
    std::cout << "Mutex locked in f1" << std::endl;
    usleep(20 * 1000);
    return nullptr;
}

auto f2(void* p) -> void*
{
    usleep(10 * 1000);
    std::lock_guard<std::mutex> l(m);
    std::cout << "Mutex locked in f2" << std::endl;
    usleep(20 * 1000);
    return nullptr;
}

auto main(int argc, char** argv) -> int
{
    pthread_t threads[2];

    pthread_create(&threads[0], nullptr, f1, 0);
    pthread_create(&threads[1], nullptr, f2, 0);

    pthread_join(threads[0], nullptr);
    pthread_join(threads[1], nullptr);

    return 0;
}

