#include <algorithm>
#include <cstdio>
#include <cstdlib>
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

    auto out = std::fopen(path.c_str(), "wb");
    std::fwrite(output.data(), sizeof(int), output.size(), out);
    std::fclose(out);

    auto in = std::fopen(path.c_str(), "rb");
    std::fread(input.data(), sizeof(int), input.size(), in);
    std::fclose(in);

    if(!std::equal(std::begin(output), std::end(output), std::begin(input)))
        std::cerr << "Error: Input does not match output." << std::endl;

    return 0;
}
