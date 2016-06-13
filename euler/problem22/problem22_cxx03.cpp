#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <numeric>
#include <list>
#include <string>

#include <time.h>

struct alphabetical_value
{
    int operator()(int acc, char c) { return acc + (c - 64); }
};

int main()
{
    std::string filename("p022_names.txt");
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: Could not open "  << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }


    std::list<std::string> names;
    std::string name;
    while(std::getline(file, name, ','))
    {
        if(name.compare("") == 0)
            break;
        names.push_front(name);
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    names.sort();
    std::size_t idx = 1;
    std::size_t total = 0;
    for(std::list<std::string>::iterator it = names.begin(); it != names.end(); ++it, ++idx)
    {
        std::string& s = *it;
        s.erase(std::remove(s.begin(), s.end(), '\"'), s.end());
        int alpha_val = std::accumulate(s.begin(), s.end(), 0, alphabetical_value());
        total += alpha_val * idx;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Total: " << total << std::endl;
    std::cout << "Elapsed time: " << (end.tv_nsec - start.tv_nsec) / 1000 << "µs" << std::endl;

    return 0;
}
