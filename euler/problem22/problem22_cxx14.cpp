#include <algorithm>
#include <cstdlib>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>

#include <time.h>

auto main() -> int
{
    auto filename = "p022_names.txt";
    auto&& file = std::ifstream{filename};
    if(!file.is_open())
    {
        std::cerr << "Error: Could not open "  << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }


    auto names = std::forward_list<std::string>{};
    auto name = std::string{};
    while(std::getline(file, name, ','))
    {
        if(name.compare("") == 0)
            break;
        names.push_front(name);
    }

    auto start = timespec{};
    auto end = timespec{};
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    names.sort();
    auto idx = 1ul;
    auto total = 0ul;
    for(auto& s : names)
    {
        s.erase(std::remove(s.begin(), s.end(), '\"'), s.end());
        auto alpha_val = std::accumulate(s.begin(), s.end(), 0, [](int acc, char c) { return acc + (c - 64); });
        total += alpha_val * idx;
        ++idx;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Total: " << total << std::endl;
    std::cout << "Elapsed time: " << (end.tv_nsec - start.tv_nsec) / 1000 << "µs" << std::endl;

    return 0;
}
