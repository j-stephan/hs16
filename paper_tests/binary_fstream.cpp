#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto main() -> int
{
    auto path = std::string{"test.bin"};
    auto output = std::vector<int>{};
    auto input = std::vector<int>{};
    output.resize(1000);
    input.resize(1000);

    std::generate(std::begin(output), std::end(output), std::rand);
    
    {
        std::ofstream out{path.c_str(), std::ios::binary};
        out.write(reinterpret_cast<const char*>(output.data()), output.size() * sizeof(int));
    }

    {
        std::ifstream in{path.c_str(), std::ios::binary};
        in.read(reinterpret_cast<char*>(input.data()), input.size() * sizeof(int));
    }

    if(!std::equal(std::begin(output), std::end(output), std::begin(input)))
        std::cerr << "Error: Input does not match output" << std::endl;

    return 0;
}
