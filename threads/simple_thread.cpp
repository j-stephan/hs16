#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

auto f() -> void
{
    std::cout << "Hello from thread #" << std::this_thread::get_id() << std::endl;
}

auto main() -> int
{
    auto threads = std::vector<std::thread>{4};
    for(auto& t : threads)
        t = std::move(std::thread{&f});

    for(auto& t : threads)
        t.join();

    return 0;
}
