#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

auto binary_file_test() -> void
{
    auto path = std::string{"test.bin"};
    auto output = std::vector<int>(1000u, 0);
    auto input = std::vector<int>(1000u, 0);

    std::generate(std::begin(output), std::end(output), std::rand);
    
    {
        auto&& out = std::ofstream{path.c_str(), std::ios::binary};

        if(out.is_open())
            out.write(reinterpret_cast<const char*>(output.data()), output.size() * sizeof(int));
        else
            throw std::runtime_error{"Could not open " + path + " for writing."};
    }
    
    {
        auto&& in = std::ifstream{path.c_str(), std::ios::binary};
        if(in.is_open())
            in.read(reinterpret_cast<char*>(input.data()), input.size() * sizeof(int));
        else
            throw std::runtime_error{"Could not open " + path + " for reading."};
    }

    if(!std::equal(std::begin(output), std::end(output), std::begin(input)))
        throw std::runtime_error{"Input and output are not equal!"};
}

auto text_file_test() -> void
{
    auto path = std::string{"test.txt"};

    {
        auto&& out = std::ofstream{path.c_str()};
        if(out.is_open())
        {
            out << "Lorem ipsum dolor sit amet, consetetur sadipscing elitir, sed diam nonumy\n"
                << "eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam\n"
                << "voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita\n"
                << "kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem\n"
                << "ipsum dolor sit amet, consetetur sadipscing elitir, sed diam nonumy eirmod"
                << std::endl;
        }
        else
            throw std::runtime_error{"Could not open " + path + " for writing."};
    }
    {
        auto&& in = std::ifstream{path.c_str()};
        if(in.is_open())
        {
            in >> std::cout.rdbuf();
            std::cout << std::endl;
        }
        else
            throw std::runtime_error{"Could not open " + path + " for reading."};
    }
}

auto c_file_test() -> void
{
    auto path = std::string{"test.cbin"};
    auto output = std::vector<int>(1000u, 0);
    auto input = std::vector<int>(1000u, 0);
    
    std::generate(std::begin(output), std::end(output), std::rand);

    auto out = std::fopen(path.c_str(), "wb");
    if(out != nullptr)
    {
        std::fwrite(output.data(), sizeof(int), output.size(), out);
        std::fclose(out);
    }
    else
        throw std::runtime_error{"Could not open " + path + " for writing."};

    auto in = std::fopen(path.c_str(), "rb");
    if(in != nullptr)
    {
        std::fread(input.data(), sizeof(int), input.size(), in);
        std::fclose(in);
    }
    else
        throw std::runtime_error{"Could not open " + path + " for reading."};

    if(!std::equal(std::begin(output), std::end(output), std::begin(input)))
        throw std::runtime_error{"Input and output are not equal!"};
}

auto main() -> int
{
    try
    {
        c_file_test();
        binary_file_test();
        text_file_test();
    }
    catch(const std::runtime_error& err)
    {
        std::cerr << "A runtime error has occurred: " << err.what() << std::endl;
    }
    return 0;
}

