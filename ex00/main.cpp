#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        std::cout << "Arguments not sufficient" << std::endl;
    ScalarConverter::convert(argv[1]);
    return (0);
}