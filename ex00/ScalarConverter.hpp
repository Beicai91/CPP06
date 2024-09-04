#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <iomanip>

typedef enum s_type
{
    ERR = 0,
    CHAR = 1,
    INT = 2,
    DOUBLE = 3,
    FLOAT = 4,
    NN = 5,
    INF = 6
}   t_type;

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        static t_type  _parseInput(const std::string &input);
        static bool _isInt(const std::string &input);
        static bool _isFloat(const std::string &input);
        static bool _isDouble(const std::string &input);
        static void _fromInt(const std::string &input);
        static void _fromChar(const std::string &input);
        static void _fromDouble(const std::string &input);
        static void _fromFloat(const std::string &input);
        static void _fromNan(const std::string &input);
        static void _fromInf(const std::string &input);
        static void _reportErr(const std::string &input);
        static void _printChar(char c);
        static void _printInt(int num);
        static void _printDouble(double num);
        static void _printFloat(float num);

    public:
        static void convert(std::string str);
};

typedef void (*convertFuncs)(const std::string &);

#endif