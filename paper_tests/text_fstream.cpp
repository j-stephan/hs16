#include <fstream>
#include <iostream>
#include <string>

auto main() -> int
{
    auto path = std::string{"test.txt"};

    {
        std::ofstream out{path.c_str()};
        out << "Lorem ipsum dolor sit amet, consetetur sadipscing elitir, sed diam nonumy\n"
            << "eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam\n"
            << "voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita\n"
            << "kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem\n"
            << "ipsum dolor sit amet, consetetur sadipscing elitir, sed diam nonumy eirmod"
            << std::endl;
    }

    {
        std::ifstream in{path.c_str()};
        in >> std::cout.rdbuf();
        std::cout << std::endl;
    }

    return 0;
}
